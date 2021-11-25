#pragma once

#include <stack>

#include "scc_result.h"
#include "../airport.h"

class StrongConnectedComponents {

public:

StrongConnectedComponents(const std::vector<std::vector<int>>& adjacency_list);

SCCResult GetAdjacencyList(int airport_index);

void MakeAdjacencyListSubgraph(int airport_index);

std::vector<int>* GetLowestIdComponent();

std::vector<std::vector<int>> GetAdjList(const std::vector<int>* nodes);

void GetStrongConnectedComponents(int root);

private:
  std::vector<std::vector<int>> adjacency_list_original_;
  std::vector<std::vector<int>> adjacency_list_;
  std::vector<bool> visited_;
  std::vector<int> stack_;
  std::vector<int> low_link_;
  std::vector<int> number_;
  int scc_counter_;
  std::vector<std::vector<int>> current_scc_;
};