#pragma once

#include <unordered_map>
#include <list>

#include "airport.h"
#include "route.h"

class Graph {

public:
  Graph(const std::string& airports_file_name, const std::string& routes_file_name);

  /**
   * getter functions 
   */
  inline const Airport& get_airport(const std::string& airport_name) const { return kVertices_.at(airport_name); }

  inline const Route& get_route() const { return kEdges_.front(); }

private:
  
  /**
   * Reads file to instatiate vertices and edges
   */
  void read_airports(const std::string& airports_file_name);

  void read_routes(const std::string& routes_file_name);

  double ToRad(double degree) const;

  double CalculateAirportDistance(const Airport& origin, const Airport& destination) const;

  /**
   * @kVertices_ : maps each airport 3-letter IATA code
   * @kEdges_ : linked list of each edge in graph
   */
  std::unordered_map<std::string, Airport> kVertices_;
  std::list<Route> kEdges_;
};