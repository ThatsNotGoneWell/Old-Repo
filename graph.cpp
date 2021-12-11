#include <fstream>
#include <sstream>
#include <stdexcept>
#include <unordered_map>
#include <list>
#include <cmath>
#include <algorithm>

#include "graph.h"

Graph::Graph(const std::string& airports_file_name, const std::string& routes_file_name) : kNullAirport_("NULL", "", "", "", -1, -1, -1) {
  ReadAirports(airports_file_name);
  ReadRoutes(routes_file_name);
}

std::vector<std::vector<int>> Graph::MakeAdjacencyList() const {
  std::vector<std::vector<int>> adjacency_list(kVertices_.size(), std::vector<int>());

  for(auto it = kEdges_.begin(); it != kEdges_.end(); ++it) {
    Airport origin = it->GetOrigin();
    Airport destination = it->GetDestination();
    adjacency_list[origin.GetIndex()].push_back(destination.GetIndex());
  }

  return adjacency_list;
}

void Graph::ReadAirports(const std::string& airports_file_name) {
  std::ifstream airport_file(airports_file_name);
  std::string line;

  // Open file and iterate through each line to fill airport hash table
  size_t vertex_index = 0;
  if (airport_file.is_open()) {
    while (getline(airport_file, line)) {

      // Convert line to stringstream object and grab each comma separated value
      std::stringstream ss(line);
      std::vector<std::string> vect;

      while(ss.good()) {
          std::string substr;
          getline(ss, substr, ','); 
          vect.push_back(substr);
      }

      // Try-catch statement essentially ignores invalid or poorly formatted entries from the data
      try {
        // Check if a 3-letter Airport Code exists
        std::string id = vect[4];
        if (id.at(0) != '"') {
            continue;
        }

        // Remove first and last characters from string since they are usuaully surrounded by quotes (eg. ""AYGA"")
        id = id.substr(1, id.size() - 2);
        std::string name = vect[1].substr(1, vect[1].size() - 2);
        std::string city = vect[2].substr(1, vect[2].size() - 2);
        std::string country = vect[3].substr(1, vect[3].size() - 2);
        double longitude = std::stod(vect[7]);
        double latitude = std::stod(vect[6]);

        Airport new_vertex(id, name, city, country, longitude, latitude, vertex_index);
        kVertices_.emplace(id, new_vertex);
        kAirports_.push_back(new_vertex);

        vertex_index++;
      } catch (const std::invalid_argument& error) {
          continue;
      }
    }
  }
}

void Graph::ReadRoutes(const std::string& routes_file_name) {
  std::ifstream route_file(routes_file_name);
  std::string line;

  // Open file and iterate through each line to fill airport hash table
  if (route_file.is_open()) {
    while (getline(route_file, line)) {

      // Convert line to stringstream object and grab each comma separated value
      std::stringstream ss(line);
      std::vector<std::string> vect;

      while(ss.good()) {
          std::string substr;
          getline(ss, substr, ','); 
          vect.push_back(substr);
      }

      // Try-catch statement essentially ignores invalid or poorly formatted entries from the data
      try {
        // Remove first and last characters from string since they are usuaully surrounded by quotes (eg. ""AYGA"")
        std::string origin_id = vect[2];
        std::string destination_id = vect[4];
        
        Airport origin = kVertices_.at(origin_id);
        Airport destination = kVertices_.at(destination_id);
        double distance = CalculateAirportDistance(origin, destination);

        Route new_edge(origin, destination, distance);
        if (std::find(kEdges_.begin(), kEdges_.end(), new_edge) == kEdges_.end()) {
          kEdges_.push_back(new_edge);
        }
      } catch (const std::out_of_range& error) {
        continue;
      }
    }
  }
}

double Graph::ToRad(double degree) const {
    return (degree * 3.1415926) / 180 ;
}

double Graph::CalculateAirportDistance(const Airport& origin, const Airport& destination) const {
    double lat1 = ToRad(origin.GetLatitude());
    double lat2 = ToRad(destination.GetLatitude());

    double delta_long = ToRad(destination.GetLongitude() - origin.GetLongitude());

    double a = (std::sin((lat2 - lat1) / 2) * std::sin((lat2 - lat1) / 2)) + 
               (std::cos(lat1) * std::cos(lat2)) *
               (std::sin((delta_long) / 2) * std::sin((delta_long) / 2));
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1-a));

    return 6371 * c;
}