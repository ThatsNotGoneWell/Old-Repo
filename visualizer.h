#include "airport.h"
#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <math.h> 

class Visualizer {

public:

  /**
   * Takes vector of airports ordered by path and draws them on map with lines representing respective routes
   *
   * @airports : vector of airports ordered by path
   * @image_width : height of input image
   * @image_height : width of input image
   * @input_file_name : name of input file (world map png onto which routes will be drawn)
   * @output_file_name : name of output file (world map png with routes drawn)
   */
  static std::vector<std::vector<int>> VisualizePath(const std::vector<Airport>& airports, size_t image_width, size_t image_height,
                            const std::string& input_file_name, const std::string& output_file_name) {
                              
    cs225::PNG png;
    png.readFromFile(input_file_name);

    int airport_size = 5;
    int route_width = 1;

    cs225::HSLAPixel route_color(216, 0.5, 0.5);
    cs225::HSLAPixel destination_airport_color(300, 0.5, 0.5);
    cs225::HSLAPixel origin_airport_color(11, 0.5, 0.5);
    cs225::HSLAPixel other_airport_color(266, 0.5, 0.5);

    // draw a square around the coordinates of each airport
    for (size_t index = 0; index < airports.size(); index++) {
      const Airport& airport = airports[index];

      // project longitude and latitude onto 2d map coordinates
      size_t projected_x =  (size_t) ((image_width * (180 + airport.GetLongitude())) / 360);
      size_t projected_y =  (size_t) ((image_height * (90 - airport.GetLatitude())) / 180);

      // draw square around airport coordinates
      for (size_t x = (projected_x - airport_size); x < (projected_x + airport_size); x++) {
        for (size_t y = (projected_y - airport_size); y < (projected_y + airport_size); y++) {
          if (x >= image_width) {
            continue;
          }
          cs225::HSLAPixel& pixel = png.getPixel(x, y);
          // change color depending on if it's starting or ending airport
          if (index == 0) {
            pixel = origin_airport_color;
          } else if (index == airports.size() - 1) {
            pixel = destination_airport_color;
          } else {
            pixel = other_airport_color;
          }
        }
      }
    }

    std::vector<std::vector<int>> points = CalculateAirportPoints(airports, image_width, image_height);

    // draw routes between airports
    for (size_t index = 1; index < points.size() - 1; index++) {
      // grab points
      std::vector<int> pair = points[index];
      int x1 = pair[0];
      int y1 = pair[1];
      int x2 = pair[2];
      int y2 = pair[3];

      // check if route is horizontally or vertically skewed
      if (std::abs(x1 - x2) > std::abs(y1 - y2)) {
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
        for (int new_x = min_x + airport_size; new_x < max_x - airport_size; new_x++) {
          double slope = (double) (y1 - y2) / (x1 - x2);
          int new_y = (slope * (new_x - x1)) + y1;

          for (int i = -route_width; i < route_width; i++) {
            cs225::HSLAPixel& pixel = png.getPixel(new_x, new_y + i);
            pixel = route_color;
          }
        }
      } else {

        int max_y, min_y;
        if (y1 > y2) {
          max_y = y1;
          min_y = y2;
        } else {
          max_y = y2;
          min_y = y1;
        }
        
        // calculate line equation to grab coordinates of each point on line
        for (int new_y = min_y + airport_size; new_y < max_y - airport_size; new_y++) {
          double slope = (double) (y1 - y2) / (x1 - x2);
          // int new_x = (slope * (new_x - x1)) + y1;
          int new_x = -(((y1 - new_y) / slope) - x1);

          for (int i = -route_width; i < route_width; i++) {
            cs225::HSLAPixel& pixel = png.getPixel(new_x + i, new_y);
            pixel = route_color;
          }

        }
      }

    }
    
    png.writeToFile(output_file_name);

    return points;
  }

private:

  /**
   * Projects longitude and latitude of  each airport onto 2d map coordinates and packages 
   * each route pair of airports into a 2d vector of  points
   *
   * @airports : vector of airport objects ordered by path
   * @png_width : width of map png
   * @png_height : height of map png
   */ 
  static std::vector<std::vector<int>> CalculateAirportPoints(const std::vector<Airport>& airports, size_t png_width, size_t png_height) {
    std::vector<std::vector<int>> points(airports.size() + 1);

    for (size_t index = 0; index < airports.size(); index++) {
      const Airport& airport = airports[index];

      // project longitude and latitude onto 2d map coordinates
      size_t projected_x =  (size_t) ((png_width * (180 + airport.GetLongitude())) / 360);
      size_t projected_y =  (size_t) ((png_height * (90 - airport.GetLatitude())) / 180);

      // store projected coordiantes for drawing routes
      points[index].push_back(projected_x);
      points[index].push_back(projected_y);
      points[index + 1].push_back(projected_x);
      points[index + 1].push_back(projected_y);
    }

    return points;
  }

};