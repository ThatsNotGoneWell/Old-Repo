#pragma once

#include <unordered_map>
#include <list>
#include <vector>

#include "airport.h"
#include "route.h"

class Graph {

public:
  Graph(const std::string& airports_file_name, const std::string& routes_file_name);

  std::vector<std::vector<int>> MakeAdjacencyList() const;

  /**
   * getter functions 
   */
  inline const Airport& get_airport(const std::string& airport_name) const { return kVertices_.at(airport_name); }

  inline const std::unordered_map<std::string, Airport>& get_vertices() const { return kVertices_; }

  inline const Route& get_route() const { return kEdges_.front(); }

  inline const std::vector<Airport>& get_airports() const { return kAirports_; }

  const std::unordered_map<std::string, Airport>& GetVerticies() const { return kVertices_; }
  const std::list<Route> get_kEdges ( ) const {  return kEdges_ ; }  
  
  double CalculateAirportDistance(const Airport& origin, const Airport& destination) const;

private:
  
  /**
   * Reads file to instatiate vertices and edges
   */
  void read_airports(const std::string& airports_file_name);

  void read_routes(const std::string& routes_file_name);

  double ToRad(double degree) const;

 

  /**
   * @kVertices_ : maps each airport 3-letter IATA code
   * @kEdges_ : linked list of each edge in graph
   * @kAirports_ : list of each airport
   */
  std::unordered_map<std::string, Airport> kVertices_;
  std::list<Route> kEdges_;
  std::vector<Airport> kAirports_;
};