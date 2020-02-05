#include <visp3/vision/vpPoseFeatures.h>
#include <iostream>

class vp_createClass{
public:
  vp_createClass(){}

  int vp_createPoint(vpFeaturePoint &fp,const vpPoint &p){
    vpFeatureBuilder::create(fp,p);
    return 2;
  }

  void vp_createTwoPoint(vpFeaturePoint &fp,const vpPoint &p, const vpPoint &p2){
    vpFeatureBuilder::create(fp,p);
    vpFeatureBuilder::create(fp,p2);
  }

  void vp_createLine(vpFeatureLine &fp,const vpLine &l){
    vpFeatureBuilder::create(fp,l);
  }
};

int main()
{
  vpPoseFeatures pose;

  vpPoint pts[3];
  vpLine line;

  //... Projection of the points and line

  vpFeaturePoint fp;
  vpFeatureLine fl;

  vp_createClass cpClass;
  int (vp_createClass::*ptrClassPoint)(vpFeaturePoint&, const vpPoint&) = &vp_createClass::vp_createPoint;
  void (vp_createClass::*ptrClassTwoPoint)(vpFeaturePoint&, const vpPoint&, const vpPoint&) = &vp_createClass::vp_createTwoPoint;
  void (vp_createClass::*ptrClassLine)(vpFeatureLine &, const vpLine &) = &vp_createClass::vp_createLine;

#ifdef VISP_HAVE_CPP11_COMPATIBILITY
  pose.addSpecificFeature(&cpClass, ptrClassPoint, fp, pts[0]);
  pose.addSpecificFeature(&cpClass, ptrClassTwoPoint, fp, pts[1], pts[2]);
  pose.addSpecificFeature(&cpClass, ptrClassLine, fl, line);
#endif

  //... Pose Computation

  return 0;
}
