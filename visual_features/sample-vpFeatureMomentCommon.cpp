#include <visp3/core/vpMomentObject.h>
#include <visp3/core/vpMomentCommon.h>
#include <visp3/core/vpPoint.h>
#include <visp3/visual_features/vpFeatureMoment.h>
#include <visp3/visual_features/vpFeatureMomentCommon.h>
#include <visp3/vs/vpServo.h>
#include <iostream>
#include <vector>

#ifdef ENABLE_VISP_NAMESPACE
using namespace VISP_NAMESPACE_NAME;
#endif

int main()
{
    // Define source polygon
  vpPoint p;
  std::vector<vpPoint> vec_p; // vector that contains the vertices of the contour polygon

  p.set_x(-0.2); p.set_y(0.1); // coordinates in meters in the image plane (vertex 1)
  vec_p.push_back(p);
  p.set_x(+0.3); p.set_y(0.1); // coordinates in meters in the image plane (vertex 2)
  vec_p.push_back(p);
  p.set_x(+0.2); p.set_y(-0.1); // coordinates in meters in the image plane (vertex 3)
  vec_p.push_back(p);
  p.set_x(-0.2); p.set_y(-0.15); // coordinates in meters in the image plane (vertex 4)
  vec_p.push_back(p);
  p.set_x(-0.2); p.set_y(0.1); // close the contour (vertex 5 = vertex 1)
  vec_p.push_back(p);


  vpMomentObject src(6); // Create a source moment object with 6 as maximum order
  src.setType(vpMomentObject::DENSE_POLYGON); // The object is defined by a countour polygon
  src.fromVector(vec_p); // Init the dense object with the source polygon
  vec_p.clear();

  //Define destination polygon. This is the source polygon translated
  //of 0.1 on x-axis
  p.set_x(-0.1); p.set_y(0.1); // coordinates in meters in the image plane (vertex 1)
  vec_p.push_back(p);
  p.set_x(+0.4); p.set_y(0.1); // coordinates in meters in the image plane (vertex 2)
  vec_p.push_back(p);
  p.set_x(+0.3); p.set_y(-0.1); // coordinates in meters in the image plane (vertex 3)
  vec_p.push_back(p);
  p.set_x(-0.1); p.set_y(-0.15); // coordinates in meters in the image plane (vertex 4)
  vec_p.push_back(p);
  p.set_x(-0.1); p.set_y(0.1); // close the contour (vertex 5 = vertex 1)
  vec_p.push_back(p);

  vpMomentObject dst(6); // Create a destination moment object with 6 as maximum order
  dst.setType(vpMomentObject::DENSE_POLYGON); // The object is defined by a countour polygon
  dst.fromVector(vec_p); // Init the dense object with the destination
       // polygon


  //init classic moment primitives (for source)
  vpMomentCommon mdb_src(vpMomentCommon::getSurface(dst), vpMomentCommon::getMu3(dst), vpMomentCommon::getAlpha(dst), 1.);
  //Init classic features
  vpFeatureMomentCommon fmdb_src(mdb_src);

  ////init classic moment primitives (for destination)
  vpMomentCommon mdb_dst(vpMomentCommon::getSurface(dst), vpMomentCommon::getMu3(dst), vpMomentCommon::getAlpha(dst), 1.);
  //Init classic features
  vpFeatureMomentCommon fmdb_dst(mdb_dst);

  //update+compute moment primitives from object (for source)
  mdb_src.updateAll(src);
  //update+compute features (+interaction matrixes) from plane
  fmdb_src.updateAll(0., 0., 1.);

  //update+compute moment primitives from object (for destination)
  mdb_dst.updateAll(dst);
  //update+compute features (+interaction matrixes) from plane
  fmdb_dst.updateAll(0., 0., 1.);

  //define visual servoing task
  vpServo task;
  task.setServo(vpServo::EYEINHAND_CAMERA);
  task.setInteractionMatrixType(vpServo::CURRENT);

  //Add all classic features to the task
  //In this example, source and destination features are translated by 0.1
  //will produce a movement of 0.1 on x-axis.
  task.addFeature(fmdb_src.getFeatureGravityNormalized(), fmdb_dst.getFeatureGravityNormalized());
  task.addFeature(fmdb_src.getFeatureAn(), fmdb_dst.getFeatureAn());
  //the object is NOT symmetric
  //select C4 and C6
  task.addFeature(fmdb_src.getFeatureCInvariant(), fmdb_dst.getFeatureCInvariant(), (1 << 3) | (1 << 5));
  task.addFeature(fmdb_src.getFeatureAlpha(), fmdb_dst.getFeatureAlpha());

  task.setLambda(1);
  vpColVector v = task.computeControlLaw();

  task.print();

  task.kill();

  return 0;
}
