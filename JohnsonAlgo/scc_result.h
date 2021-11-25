#pragma once

#include <unordered_set>
#include <vector>
#include <iostream>
struct SCCResult {
public:
  SCCResult(std::vector<std::vector<int>> adjacency_list, int lowest_airport_index) {
    this->adjacency_list = adjacency_list;
		this->lowest_airport_index = lowest_airport_index;

    // size_t index = 0;
    // std::cout << "THIS IS THE SCC CONSTRUCTOR" << std::endl;
    // for (const auto& row : adjacency_list) {
    //   std::cout << index << "  ";
    //   for (const auto& elem : row) {
    //     std::cout << elem << " ";
    //   }
    //   std::cout << std::endl;
    //   index++;
    // }

    for (size_t i = lowest_airport_index; i < adjacency_list.size(); i++) {
      if (adjacency_list[i].size() > 0) {
        airport_index_of_SCC.insert(static_cast<int>(i));
      }
    }
  }

  inline const std::vector<std::vector<int>>& GetAdjacencyList() const { return adjacency_list; }

  inline int GetLowestAirportIndex() const { return lowest_airport_index; }

private:

  std::vector<std::vector<int>> adjacency_list;
  int lowest_airport_index = -1;
  std::unordered_set<int> airport_index_of_SCC;
};