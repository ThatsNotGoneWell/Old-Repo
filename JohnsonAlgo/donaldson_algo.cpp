#include <algorithm>

#include "scc_result.h"
#include "donaldson_algo.h"
#include "strong_connected_components.h"

DonaldsonAlgo::DonaldsonAlgo(const std::string& airports_file_name, const std::string& routes_file_name) : 
                             kAirportRoutes_(airports_file_name,  routes_file_name),
                             kAdjacencyList_(kAirportRoutes_.MakeAdjacencyList()) { 

  blocked_ = std::vector<bool>(kAdjacencyList_.size());
  B_ = std::vector<std::vector<int>>(kAdjacencyList_.size(), std::vector<int>());
  // stack_ = std::stack<Airport>();
  // cycles_ = std::vector<std::vector<Airport>>;
}

std::vector<Airport> DonaldsonAlgo::GetLongestCycle() {
  std::vector<Airport> longest_cycle = GetAllCycles()[0];

  for (const auto& airport : longest_cycle) {
    std::cout << airport << std::endl;
  }
  
  return longest_cycle;
}

std::vector<std::vector<Airport>> DonaldsonAlgo::GetAllCycles() {
  StrongConnectedComponents sccs(kAdjacencyList_);
  int s = 0;

  while (true) {
    std::cout << __LINE__ << std::endl;
    SCCResult scc_result = sccs.GetAdjacencyList(s);
    std::cout << __LINE__ << std::endl;
    if (scc_result.GetLowestAirportIndex() != -1 && scc_result.GetLowestAirportIndex() != -1) { // Removed Null Check    
      std::vector<std::vector<int>> scc = scc_result.GetAdjacencyList();
      s = scc_result.GetLowestAirportIndex();
      for (size_t j = 0; j < scc.size(); j++) {
        if (scc[j].size() > 0 && scc[0][0] != -1) { // Removed Null Check
          blocked_[j] = false;
          B_[j] = std::vector<int>();
        }
      }

      FindCycles(s, s, scc);
      s++;
    } else {
      break;
    }
  }

  return cycles_;
}

bool DonaldsonAlgo::FindCycles(int v, int s, std::vector<std::vector<int>> adj_list) {
  bool f = false;
  stack_.push_back(v);
  blocked_[v] = true;

  for (size_t i = 0; i < adj_list[v].size(); i++) {
    int w = adj_list[v][i];
    // found cycle
    if (w == s) {
      std::vector<Airport> cycle;
      for (size_t j = 0; j < stack_.size(); j++) {
        int index = stack_[j];
        cycle.push_back(kAirportRoutes_.get_airports()[index]);
      }
      cycles_.push_back(cycle);
      f = true;
    } else if (!blocked_[w]) {
      if (FindCycles(w, s, adj_list)) {
        f = true;
      }
    }
  }

  if (f) {
    unblock(v);
  } else {
    for (size_t i = 0; i < adj_list[v].size(); i++) {
      int w = adj_list[v][i];
      w++;
      if (!std::count(B_[w].begin(), B_[w].end(), v)) {
        B_[w].push_back(v);
      }
    }
  }

  stack_.erase(std::remove(stack_.begin(), stack_.end(), v), stack_.end());
  return f;
}

void DonaldsonAlgo::unblock(int airport_index) {
  blocked_[airport_index] = false;
  std::vector<int> B_node = B_[airport_index];
  while (B_node.size() > 0) {
    int w = B_node[0];
    B_node.erase(B_node.begin()); // make more efficient
    if (blocked_[w]) {
      unblock(w);
    }
  }
}
