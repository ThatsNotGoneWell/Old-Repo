#include <algorithm>

#include "strong_connected_components.h"

StrongConnectedComponents::StrongConnectedComponents(const std::vector<std::vector<int>>& adjacency_list) :
                                                     adjacency_list_original_(adjacency_list) { 
  visited_ = std::vector<bool>(adjacency_list_original_.size(), false);
  low_link_ = std::vector<int>(adjacency_list_original_.size(), 0);
  number_ = std::vector<int>(adjacency_list_original_.size(), 0);
  // current_scc_ = std::vector<std::vector<int>>(adjacency_list.size(), std::vector<int>());
  // stack_ = std::vector<int>();
  scc_counter_ = 0;
}

SCCResult StrongConnectedComponents::GetAdjacencyList(int airport_index) {
  visited_ = std::vector<bool>(adjacency_list_original_.size(), false);
  low_link_ = std::vector<int>(adjacency_list_original_.size(), 0);
  number_ = std::vector<int>(adjacency_list_original_.size(), 0);
  stack_.clear();
  current_scc_.clear();

  MakeAdjacencyListSubgraph(airport_index);

  for (size_t i = airport_index; i < adjacency_list_original_.size(); i++) {
    if (!visited_[i]) {
      GetStrongConnectedComponents(i);
      std::vector<int> nodes = GetLowestIdComponent();
      // for (const auto& elem : nodes) {
      //   std::cout << elem << "     ";
      // }
      // std::cout << std::endl;

      if (!IsNodesNull(nodes) && // NULL CHECK
         !std::count(nodes.begin(), nodes.end(), airport_index) &&
         !std::count(nodes.begin(), nodes.end(), airport_index + 1)) {
        return GetAdjacencyList(airport_index + 1);
      } else {
        std::vector<std::vector<int>> temp_adjacency_list = GetAdjList(nodes);
        if (!IsAdjacencyListNull(temp_adjacency_list)) { // NULL CHECK
          for (size_t j = 0; j < adjacency_list_original_.size(); j++) {
            if (temp_adjacency_list[j].size() > 0) {
              return SCCResult(temp_adjacency_list, j);
            }
          }
        }
      }
    }
  }

  return SCCResult(adjacency_list_original_, -1);
}

void StrongConnectedComponents::MakeAdjacencyListSubgraph(int node) {
  adjacency_list_ = std::vector<std::vector<int>>(adjacency_list_original_.size(), std::vector<int>());

  for (size_t i = node; i < adjacency_list_.size(); i++) {
    std::vector<int> successors;
    for (size_t j = 0; j < adjacency_list_original_[i].size(); j++) {
      if (adjacency_list_original_[i][j] >= node) {
        successors.push_back(adjacency_list_original_[i][j]);
      }
    }
    if (successors.size() > 0) {
      adjacency_list_[i] = std::vector<int>(successors.size());
      for (size_t j = 0; j < successors.size(); j++) {
        adjacency_list_[i][j] = successors[j];
      }
    }
  }

  // size_t index = 0;
  // std::cout << "Making Subgraph for node: " << node << std::endl;
  // for (const auto& row : adjacency_list_) {
  //   std::cout << index << "  ";
  //   for (const auto& elem : row) {
  //     std::cout << elem << " ";
  //   }
  //   std::cout << std::endl;
  //   index++;
  // }
}

std::vector<int> StrongConnectedComponents::GetLowestIdComponent() {
  int min = adjacency_list_.size();
  std::vector<int> curr_scc{-1};

  for (size_t i = 0; i < current_scc_.size(); i++) {
   std::vector<int> scc = current_scc_[i];
    for (size_t j = 0; j < scc.size(); j++) {
      int node = scc[j];
      if (node < min) {
        curr_scc = scc; // possible seg fault
        min = node;
      }
    }
  }

  return curr_scc;
}

std::vector<std::vector<int>> StrongConnectedComponents::GetAdjList(const std::vector<int> nodes) {
  std::vector<std::vector<int>> lowest_id_adjacency_list {{-1, -1}, {-1, -1}};

  if (nodes.size() != 1 && nodes[0] != -1) { // NULL CHECK
    lowest_id_adjacency_list = std::vector<std::vector<int>>(adjacency_list_.size(), std::vector<int>());
    // for (size_t i = 0; i < lowest_id_adjacency_list.size(); i++) {
    //   lowest_id_adjacency_list[i] = std::vector<int>();
    // }

    for (size_t i = 0; i < nodes.size(); i++) {
      int node = nodes[i];
      for (size_t j = 0; j < adjacency_list_[node].size(); j++) {
        int succ = adjacency_list_[node][j];
        if (std::count(nodes.begin(), nodes.end(), succ)) {
          lowest_id_adjacency_list[node].push_back(succ);
        }
      }
    }
  }

  return lowest_id_adjacency_list;
}

void StrongConnectedComponents::GetStrongConnectedComponents(int root) {
  scc_counter_++;
  low_link_[root] = scc_counter_;
  number_[root] = scc_counter_;
  visited_[root] = true;
  stack_.push_back(root);

  for (size_t i = 0; i < adjacency_list_[root].size(); i++) {
    int w = adjacency_list_[root][i];
    if (!visited_[w]) {
      GetStrongConnectedComponents(w);
      low_link_[root] = std::min(low_link_[root], low_link_[w]);
    } else if (number_[w] < number_[root]) {
      if (std::count(stack_.begin(), stack_.end(), w)) {
        low_link_[root] = std::min(low_link_[root], number_[w]);
      }
    }
  }

  // found scc
  if ((low_link_[root] == number_[root]) && (stack_.size() > 0)) {
    int next = -1;
    std::vector<int> scc;

    do {
      next = stack_.back();
      stack_.pop_back();
      scc.push_back(next);
    } while (number_[next] > number_[root]);

    if (scc.size() > 1) {
      current_scc_.push_back(scc);
    }
  }

  // std::cout << "SCC Count: " << scc_counter_ << "  Root: " << root << "  size: " << current_scc_.size() << std::endl;
}

bool StrongConnectedComponents::IsAdjacencyListNull(const std::vector<std::vector<int>>& adjacency_list) {
  return adjacency_list.size() == 2 && adjacency_list[0][0] == -1;
}

bool StrongConnectedComponents::IsNodesNull(const std::vector<int>& nodes) {
  return nodes.size() == 1 && nodes[0] == -1;
}
