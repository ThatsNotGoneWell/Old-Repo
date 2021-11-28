#include "airport.h"
#include "route.h"
#include "graph.h"
#include "JohnsonAlgo/donaldson_algo.h"

#include <algorithm>
#include <chrono>

using namespace std::chrono;

int main() {
  auto start_build_graph = high_resolution_clock::now();
  DonaldsonAlgo algo("data/airports.dat.txt", "data/routes.dat.txt");
  auto stop_build_graph = high_resolution_clock::now();

  auto build_graph_duration = duration_cast<microseconds>(stop_build_graph - start_build_graph);
  std::cout << "Time to build graph: " << build_graph_duration.count() << std::endl;

  auto start_find_cycles = high_resolution_clock::now();
  std::vector<Airport> longest_cycle = algo.GetLongestCycle();
  auto stop_find_cycles = high_resolution_clock::now();

  for (const auto& airport : longest_cycle) {
    std::cout << airport << std::endl;
  }

  auto find_cycles_duration = duration_cast<microseconds>(stop_find_cycles - start_find_cycles);
  std::cout << "Time to find cycles: " << find_cycles_duration.count() << std::endl;
  
  // Graph graph("data/airports.dat.txt", "data/routes.dat.txt");
  // graph.MakeAdjacencyList();
  // std::vector<int> nodes{8, 7, 6};

  // std::cout << "HELLO WORLD!1!!" << std::endl;

  // if (!(nodes.size() == 1 && nodes[0] == -1) && // NULL CHECK
  //        !std::count(nodes.begin(), nodes.end(), 2) &&
  //        !std::count(nodes.begin(), nodes.end(), 2 + 1)) {
  //     std::cout << "HELLO WORLD2!!!" << std::endl;
  // }

  // std::vector<std::vector<int>> nib(3);
  // std::vector<int> nib1{1, 2, 3};
  // std::vector<int> nib2{1, 2};
  // std::vector<int> nib3{1};

  // nib.push_back(nib1);
  // nib.push_back(nib2);
  // nib.push_back(nib3);

  // for (size_t i = 0; i < nib.size(); i++) {
  //   std::cout << "Row " << i << ": ";
  //   for (size_t j = 0; j < nib[i].size(); j++){
  //     std::cout << nib[i][j] << "  ";
  //   }
  //   std::cout << std::endl;
  // } 

  // nib.clear();

  // nib.push_back(nib1);
  // nib.push_back(nib2);
  // nib.push_back(nib3);

  // for (size_t i = 0; i < nib.size(); i++) {
  //   std::cout << "Row " << i << ": ";
  //   for (size_t j = 0; j < nib[i].size(); j++){
  //     std::cout << nib[i][j] << "  ";
  //   }
  //   std::cout << std::endl;
  // } 

  return 1;
}