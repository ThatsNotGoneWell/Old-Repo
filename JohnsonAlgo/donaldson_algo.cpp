#include <algorithm>

#include "scc_result.h"
#include "donaldson_algo.h"
#include "strong_connected_components.h"

DonaldsonAlgo::DonaldsonAlgo(const std::string& airports_file_name, const std::string& routes_file_name) : 
                             kAirportRoutes_(airports_file_name,  routes_file_name),
                             kAdjacencyList_(kAirportRoutes_.MakeAdjacencyList()) { 

  blocked_ = std::vector<bool>(kAdjacencyList_.size(), false);
  B_ = std::vector<std::vector<int>>(kAdjacencyList_.size());
}

std::vector<Airport> DonaldsonAlgo::GetLongestCycle() {
  std::vector<std::vector<Airport>> all_cycles = GetAllCycles();

  // for (const auto& airport : longest_cycle) {
  //   std::cout << airport << std::endl;
  // }
  size_t max_size = 0;
  size_t max_size_index = 0;
  for (size_t index = 0; index < all_cycles.size(); index ++) {
    if (all_cycles[index].size() > max_size) {
      max_size = all_cycles[index].size();
      max_size_index = index;
    }
  }
  // for (const auto& cycle : longest_cycle) {
  //   for (const auto& airport : cycle) {
  //     std::cout << airport << std::endl;
  //   }
  //   std::cout << std::endl;
  // }
  
  return all_cycles[max_size_index];
}

std::vector<std::vector<Airport>> DonaldsonAlgo::GetAllCycles() {
  StrongConnectedComponents sccs(kAdjacencyList_);
  int s = 0;

  while (true) {
    SCCResult scc_result = sccs.GetAdjacencyList(s);

    if (scc_result.GetLowestAirportIndex() != -1 && !IsAdjacencyListNull(scc_result.GetAdjacencyList())) { // Removed Null Check    
      std::vector<std::vector<int>> scc = scc_result.GetAdjacencyList();
      s = scc_result.GetLowestAirportIndex();
      for (size_t j = 0; j < scc.size(); j++) {
        if (scc[j].size() > 0 && scc[j][0] != -1) { // Removed Null Check
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
  std::cout << __LINE__ << std::endl;
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
        cycle.push_back(kAirportRoutes_.GetAirports()[index]);
      }
      cycles_.push_back(cycle);
      f = true;
    } else if (!blocked_[w]) {
      bool temp = FindCycles(w, s, adj_list);
      if (temp) {
        f = true;
      }
    }
  }

  if (f) {
    unblock(v);
  } else {
    for (size_t i = 0; i < adj_list[v].size(); i++) {
      int w = adj_list[v][i];
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

bool DonaldsonAlgo::IsAdjacencyListNull(const std::vector<std::vector<int>>& adjacency_list) {
  return adjacency_list.size() == 2 && adjacency_list[0][0] == -1;
}

bool DonaldsonAlgo::IsSCCNull(const std::vector<std::vector<int>>& scc, size_t j) {
  return scc[j].size() > 0 && scc[j][0] != -1;
}
