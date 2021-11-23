#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <unordered_map>
#include <list>
#include <cmath>
#include <unordered_map>
#include <list>

#include "node.h" 

#include "airport.h"
#include "route.h"

class Graph {

public:
  Graph(const std::string& airports_file_name, const std::string& routes_file_name);

  const Airport& get_airport(const std::string& airport_name) const;

  const std :: vector  <Route >  get_route(const std ::  string& rout_origin ) const;
  
  const node*  create_nodes (  ) ; 
  
  std :: vector < node * > node_holder ;
private:

  void read_airports(const std::string& airports_file_name);

  void read_routes(const std::string& routes_file_name);

  double ToRad(double degree) const;

  double CalculateAirportDistance(const Airport& origin, const Airport& destination) const;

  std::unordered_map<std::string, Airport> kVertices_;
  std::list<Route> kEdges_; 
  
};
