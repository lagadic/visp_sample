#include <visp3/sensor/vpRealSense2.h>
#ifdef VISP_HAVE_PCL
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/visualization/pcl_visualizer.h>
#endif

int main()
{
#if defined(VISP_HAVE_REALSENSE2) && defined(VISP_HAVE_PCL)
  vpRealSense2 rs;
  rs.open();
  pcl::PointCloud<pcl::PointXYZRGB>::Ptr pointcloud(new pcl::PointCloud<pcl::PointXYZRGB>);
  rs.acquire(NULL, NULL, NULL, pointcloud);
  pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(pointcloud);
  viewer->setBackgroundColor(0, 0, 0);
  viewer->initCameraParameters();
  viewer->setCameraPosition(0, 0, -0.5, 0, -1, 0);
  while (true) {
    rs.acquire(NULL, NULL, NULL, pointcloud);
    static bool update = false;
    if (!update) {
      viewer->addPointCloud<pcl::PointXYZRGB> (pointcloud, rgb, "sample cloud");
      viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "sample cloud");
      update = true;
    } else {
      viewer->updatePointCloud<pcl::PointXYZRGB> (pointcloud, rgb, "sample cloud");
    }
    viewer->spinOnce(30);
  }
#endif
  return 0;
}
