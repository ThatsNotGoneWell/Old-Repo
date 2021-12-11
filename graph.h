#pragma once

#include <unordered_map>
#include <list>
#include <vector>

#include "airport.h"
#include "route.h"

class Graph {

public:
  Graph(const std::string& airports_file_name, const std::string& routes_file_name);

  /**
   * Creates adjacency list of the graph represented as a 2d vector
   * { 0 : [1, 2],
   *   1 : [2],
   *   2 : [1] }
   * This represents a graph where the 0-node connects  to the 1 and 2-nodes, 
   * the 1-node to the 2-node, and the 2-node to the 1-node
   */
  std::vector<std::vector<int>> MakeAdjacencyList() const;

  /**
   * getter functions 
   */
  inline const Airport& GetAirport(const std::string& airport_name) const { return kVertices_.at(airport_name); }

  inline const std::unordered_map<std::string, Airport>& GetVertices() const { return kVertices_; }

  inline const Route& GetRoute() const { return kEdges_.front(); }

  inline const std::vector<Airport>& GetAirports() const { return kAirports_; }

  /**
   * Calculates distance between two airports in kilometers
   */
  double CalculateAirportDistance(const Airport& origin, const Airport& destination) const;
  
private:
  
  /**
   * Reads file to instatiate vertices and edges
   */
  void ReadAirports(const std::string& airports_file_name);

  void ReadRoutes(const std::string& routes_file_name);

  /**
   * Converts degrees to radians
   */
  double ToRad(double degree) const;

  /**
   * @kVertices_ : maps each airport 3-letter IATA code to its respective airport object
   * @kEdges_ : linked list of each edge in graph as represented by 
   * @kAirports_ : list of each airport
   */
  std::unordered_map<std::string, Airport> kVertices_;
  std::list<Route> kEdges_;
  std::vector<Airport> kAirports_;
};