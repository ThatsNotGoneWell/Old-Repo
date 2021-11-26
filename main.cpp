#include "airport.h"
#include "route.h"
#include "graph.h"
#include "JohnsonAlgo/donaldson_algo.h"
#include <algorithm>

int main() {
  DonaldsonAlgo algo("data/airports.dat.txt", "data/routes.dat.txt");
  std::vector<Airport> longest_cycle = algo.GetLongestCycle();

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