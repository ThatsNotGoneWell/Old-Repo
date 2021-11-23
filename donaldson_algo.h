#pragma once

#include <vector>

#include "graph.h"

class DonaldsonAlgo {

public:

  DonaldsonAlgo(const std::string& airports_file_name, const std::string& routes_file_name);

  std::vector<Airport> FindLongestCycle() const;

private:  
  const Graph kAirportRoutes_;
  const std::vector<std::vector<int>> kAdjacencyList_;
};