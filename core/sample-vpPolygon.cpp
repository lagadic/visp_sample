#include <iostream>

#include <visp3/core/vpPolygon.h>

int main()
{
  std::vector<vpImagePoint> corners;

  // Initialize the corners vector with 4 points
  corners.push_back( vpImagePoint( 50, 100) );
  corners.push_back( vpImagePoint( 50, 300) );
  corners.push_back( vpImagePoint(200, 300) );
  corners.push_back( vpImagePoint(200, 100) );

  // Initialize a polygon with the corners
  vpPolygon polygon(corners);

  // Get the polygon bounding box
  vpRect bbox = polygon.getBoundingBox();
  std::cout << "Bounding box: " << bbox.getTopLeft() << " to " << bbox.getBottomRight() << std::endl;

  // Get the polygon surface and center
  std::cout << "Area: " << polygon.getArea() << std::endl;
  std::cout << "Center: " << polygon.getCenter() << std::endl;

  // Check if a point is inside the polygon
  vpImagePoint ip(550, 200);
  std::cout << "The point " << ip << " is " << (polygon.isInside(ip) ? "inside":"outside") << " the polygon" << std::endl;

  return 0;
}
