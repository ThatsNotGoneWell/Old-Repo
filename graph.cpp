#include <fstream>
#include <sstream>
#include <stdexcept>
#include <unordered_map>
#include <list>
#include <cmath>
#include <algorithm>

#include "graph.h"

Graph::Graph(const std::string& airports_file_name, const std::string& routes_file_name) {
  read_airports(airports_file_name);
  read_routes(routes_file_name);
}

std::vector<std::vector<int>> Graph::MakeAdjacencyList() const {
  std::vector<std::vector<int>> adjacency_list(kVertices_.size(), std::vector<int>());

  for(auto it = kEdges_.begin(); it != kEdges_.end(); ++it) {
    Airport origin = it->get_origin();
    Airport destination = it->get_destination();
    adjacency_list[origin.get_index()].push_back(destination.get_index());
  }

  // for (size_t i = 0; i < adjacency_list.size(); i++) {
  //   std::cout << "Row " << i << ": ";
  //   for (size_t j = 0; j < adjacency_list[i].size(); j++){
  //     std::cout << adjacency_list[i][j] << "  ";
  //   }
  //   std::cout << std::endl;
  // } 
  return adjacency_list;
}

void Graph::read_airports(const std::string& airports_file_name) {
  // Airport lax("LAX", "Los Angeles International Airport", "Los Angeles", 0, 0, 0);
  // Airport ewr("EWR", "Newark Liberty International Airport", "Newark", 0, 0, 1);
  // Airport jfk("JFK", "John F Kennedy International Airport", "New York", 0, 0, 2);
  // Airport sfo("SFO", "San Francisco International Airport", "San Francisco", 0, 0, 3);
  // Airport dfw("DFW", "Dallas Fort Worth International Airport", "Dallas-Fort Worth", 0, 0, 4);
  // Airport jnu("JNU", "Juneau International Airport", "Juneau", 0, 0, 5);
  // Airport lft("LFT", "afayette Regional Airport", "Lafayette", 0, 0, 6);
  // Airport boi("BOI", "Boise Air Terminal/Gowen Field", "Boise", 0, 0, 7);
  // Airport fll("FLL", "Fort Lauderdale Hollywood International Airport", "Fort Lauderdale", 0, 0, 8);
  // Airport slc("SLC", "Salt Lake City International Airport", "Salt Lake City", 0, 0, 9);


  // kVertices_.emplace("LAX", lax);
  // kAirports_.push_back(lax);

  // kVertices_.emplace("EWR", ewr);
  // kAirports_.push_back(ewr);

  // kVertices_.emplace("JFK", jfk);
  // kAirports_.push_back(jfk);

  // kVertices_.emplace("SFO", sfo);
  // kAirports_.push_back(sfo);

  // kVertices_.emplace("DFW", dfw);
  // kAirports_.push_back(dfw);

  // kVertices_.emplace("JNU", jnu);
  // kAirports_.push_back(jnu);

  // kVertices_.emplace("LFT", lft);
  // kAirports_.push_back(lft);

  // kVertices_.emplace("BOI", boi);
  // kAirports_.push_back(boi);

  // kVertices_.emplace("FLL", fll);
  // kAirports_.push_back(fll);

  // kVertices_.emplace("SLC", slc);
  // kAirports_.push_back(slc);

  std::ifstream airport_file(airports_file_name);
  std::string line;

  // Open file and iterate through each line to fill airport hash table
  size_t vertex_index = 0;
  if (airport_file.is_open()) {
    while (getline(airport_file, line)) {
      // if (kVertices_.size() > 55) {
      //   break;
      // }
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
        double longitude = std::stod(vect[7]);
        double latitude = std::stod(vect[6]);

        std::string country = vect[3].substr(1, vect[3].size() - 2);

        // only reads airpots in USA
        if (country != "United States") {
          continue;
        }

        Airport new_vertex(id, name, city, longitude, latitude, vertex_index);
        kVertices_.emplace(id, new_vertex);
        kAirports_.push_back(new_vertex);

        vertex_index++;
      } catch (const std::invalid_argument& error) {
          continue;
      }
    }
  }
}

void Graph::read_routes(const std::string& routes_file_name) {
  // kEdges_.push_back(Route(kVertices_.at("LAX"), kVertices_.at("EWR"), 0));

  // kEdges_.push_back(Route(kVertices_.at("EWR"), kVertices_.at("JFK"), 0));

  // kEdges_.push_back(Route(kVertices_.at("JFK"), kVertices_.at("LAX"), 0));
  // kEdges_.push_back(Route(kVertices_.at("JFK"), kVertices_.at("LFT"), 0));

  // kEdges_.push_back(Route(kVertices_.at("SFO"), kVertices_.at("DFW"), 0));

  // kEdges_.push_back(Route(kVertices_.at("DFW"), kVertices_.at("JNU"), 0));
  // kEdges_.push_back(Route(kVertices_.at("DFW"), kVertices_.at("LFT"), 0));

  // kEdges_.push_back(Route(kVertices_.at("JNU"), kVertices_.at("SFO"), 0));

  // kEdges_.push_back(Route(kVertices_.at("LFT"), kVertices_.at("EWR"), 0));
  // kEdges_.push_back(Route(kVertices_.at("LFT"), kVertices_.at("BOI"), 0));

  // kEdges_.push_back(Route(kVertices_.at("BOI"), kVertices_.at("FLL"), 0));
  
  // kEdges_.push_back(Route(kVertices_.at("FLL"), kVertices_.at("LFT"), 0));


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
    double lat1 = ToRad(origin.get_latitude());
    double lat2 = ToRad(destination.get_latitude());

    double delta_long = ToRad(destination.get_longitude() - origin.get_longitude());

    double a = (std::sin((lat2 - lat1) / 2) * std::sin((lat2 - lat1) / 2)) + 
               (std::cos(lat1) * std::cos(lat2)) *
               (std::sin((delta_long) / 2) * std::sin((delta_long) / 2));
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1-a));

    return 6371 * c;
}