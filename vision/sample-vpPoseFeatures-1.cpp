#include <visp3/vision/vpPoseFeatures.h>

void vp_createPoint(vpFeaturePoint &fp,const vpPoint &p){
  vpFeatureBuilder::create(fp,p);
}

void vp_createTwoPoint(vpFeaturePoint &fp,const vpPoint &p, const vpPoint&p2){
  vpFeatureBuilder::create(fp,p);
  vpFeatureBuilder::create(fp,p2);
}

void vp_createLine(vpFeatureLine &fp,const vpLine &l){
  vpFeatureBuilder::create(fp,l);
}

int main()
{
  vpPoseFeatures pose;

  vpPoint pts[4];
  vpLine line;

  //... Projection of the points and line

  vpFeaturePoint fp;
  vpFeatureLine fl;
  void (*ptr)(vpFeaturePoint&, const vpPoint&) = &vpFeatureBuilder::create;

#ifdef VISP_HAVE_CPP11_COMPATIBILITY
  pose.addSpecificFeature(ptr, fp, pts[0]);
  pose.addSpecificFeature(&vp_createPoint, fp, pts[1]);
  pose.addSpecificFeature(&vp_createTwoPoint, fp, pts[2], pts[3]);
  pose.addSpecificFeature(&vp_createLine, fl, line);
#endif

  //... Pose Computation

  return 0;
}
