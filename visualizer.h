#include "airport.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <math.h> 

class Visualizer {

public:
  static void VisualizePath(const std::vector<Airport>& airports) {
    cs225::PNG png;
    png.readFromFile("world_map5.png");

    std::vector<std::vector<int>> points(airports.size() + 1);

    size_t pair_index = 0;
    for (size_t index = 0; index < airports.size(); index++) {
      const Airport& airport = airports[index];

      // project longitude and latitude onto 2d map coordinates
      size_t projected_x =  (size_t) ((1939 * (180 + airport.get_longitude())) / 360);
      size_t projected_y =  (size_t) ((1010 * (90 - airport.get_latitude())) / 180);

      // store projected coordiantes for drawing routes
      points[pair_index].push_back(projected_x);
      points[pair_index].push_back(projected_y);
      points[pair_index + 1].push_back(projected_x);
      points[pair_index + 1].push_back(projected_y);
      pair_index++;

      // draw square around airport coordinates
      for (size_t x = (projected_x - 5); x < (projected_x + 5); x++) {
        for (size_t y = (projected_y - 5); y < (projected_y + 5); y++) {
          cs225::HSLAPixel& pixel = png.getPixel(x, y);
          if (index == 0) {
            pixel.h = 11;
          } else if (index == airports.size() - 1) {
            pixel.h = 300;
          } else {
            pixel.h = 216;
          }
          pixel.s = 0.5;
          pixel.l = 0.5;
        }
      }
    }

    // draw routes    
    for (size_t index = 1; index < points.size() - 1; index++) {
      // grab points
      std::vector<int> pair = points[index];
      int x1 = pair[0];
      int y1 = pair[1];
      int x2 = pair[2];
      int y2 = pair[3];

      // get max and min x values to ensure difference is positive
      int max_x, min_x;
      if (x1 > x2) {
        max_x = x1;
        min_x = x2;
      } else {
        max_x = x2;
        min_x = x1;
      }
      
      // calculate line equation to grab coordinates of each point on line
      for (int new_x = min_x; new_x < max_x; new_x++) {
        double slope = (double) (y1 - y2) / (x1 - x2);
        int new_y = (slope * (new_x - x1)) + y1;

        cs225::HSLAPixel& pixel = png.getPixel(new_x, new_y);
        pixel.h = 11;
        pixel.s = 0.5;
        pixel.l = 0.5;
        pixel = png.getPixel(new_x, new_y + 1);
        pixel.h = 11;
        pixel.s = 0.5;
        pixel.l = 0.5;
        pixel = png.getPixel(new_x, new_y + 2);
        pixel.h = 11;
        pixel.s = 0.5;
        pixel.l = 0.5;
        pixel = png.getPixel(new_x, new_y + 3);
        pixel.h = 11;
        pixel.s = 0.5;
        pixel.l = 0.5;
        pixel = png.getPixel(new_x, new_y + 4);
        pixel.h = 11;
        pixel.s = 0.5;
        pixel.l = 0.5;
        pixel = png.getPixel(new_x, new_y - 1);
        pixel.h = 11;
        pixel.s = 0.5;
        pixel.l = 0.5;
        pixel = png.getPixel(new_x, new_y - 2);
        pixel.h = 11;
        pixel.s = 0.5;
        pixel.l = 0.5;
        pixel = png.getPixel(new_x, new_y - 3);
        pixel.h = 11;
        pixel.s = 0.5;
        pixel.l = 0.5;
        pixel = png.getPixel(new_x, new_y - 4);
        pixel.h = 11;
        pixel.s = 0.5;
        pixel.l = 0.5;
      }

      png.writeToFile("nibbie.png");
    }
  }
};