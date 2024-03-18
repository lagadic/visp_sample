#include <visp3/vision/vpPoseFeatures.h>

#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
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
#endif

int main()
{
#if (VISP_CXX_STANDARD >= VISP_CXX_STANDARD_11)
  vpPoseFeatures pose;

  vpPoint pts[4];
  vpLine line;

  //... Projection of the points and line

  vpFeaturePoint fp;
  vpFeatureLine fl;
  void (*ptr)(vpFeaturePoint&, const vpPoint&) = &vpFeatureBuilder::create;

  pose.addSpecificFeature(ptr, fp, pts[0]);
  pose.addSpecificFeature(&vp_createPoint, fp, pts[1]);
  pose.addSpecificFeature(&vp_createTwoPoint, fp, pts[2], pts[3]);
  pose.addSpecificFeature(&vp_createLine, fl, line);

  //... Pose Computation
#endif
  return 0;
}
