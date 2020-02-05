#include <visp3/core/vpConfig.h>
#if defined(VISP_HAVE_REALSENSE) && defined(VISP_HAVE_PCL)

#include <visp3/sensor/vpRealSense.h>

#include <pcl/visualization/cloud_viewer.h>
#include <pcl/visualization/pcl_visualizer.h>

int main()
{
  vpRealSense rs;
  rs.open();
  std::cout << rs << std::endl;

  pcl::PointCloud<pcl::PointXYZRGB>::Ptr pointcloud(new pcl::PointCloud<pcl::PointXYZRGB>);

  rs.acquire(pointcloud);

  pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer ("3D Viewer"));
  pcl::visualization::PointCloudColorHandlerRGBField<pcl::PointXYZRGB> rgb(pointcloud);
  viewer->setBackgroundColor (0, 0, 0);
  viewer->addCoordinateSystem (1.0);
  viewer->initCameraParameters ();
  viewer->setCameraPosition(0,0,-0.5, 0,-1,0);

  while (1) {
    rs.acquire(pointcloud);

    static bool update = false;
    if (! update) {
      viewer->addPointCloud<pcl::PointXYZRGB> (pointcloud, rgb, "sample cloud");
      viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "sample cloud");
      update = true;
    }
    else {
      viewer->updatePointCloud<pcl::PointXYZRGB> (pointcloud, rgb, "sample cloud");
    }

    viewer->spinOnce (100);
  }
}

#else
int main() {}
#endif

