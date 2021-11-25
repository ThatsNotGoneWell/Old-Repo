#pragma once

#include <vector>
#include <stack>

#include "../graph.h"

class DonaldsonAlgo {

public:

  DonaldsonAlgo(const std::string& airports_file_name, const std::string& routes_file_name);

  std::vector<Airport> GetLongestCycle();

private:  

  std::vector<std::vector<Airport>> GetAllCycles();

  bool FindCycles(int v, int s, std::vector<std::vector<int>> adjacency_list);

  void unblock(int airport_index);

  const Graph kAirportRoutes_;
  const std::vector<std::vector<int>> kAdjacencyList_;

  std::vector<int> stack_;
  std::vector<std::vector<int>> B_;
  std::vector<std::vector<Airport>> cycles_;
  std::vector<bool> blocked_;
};