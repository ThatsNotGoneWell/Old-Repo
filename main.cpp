#include "airport.h"
#include "route.h"
#include "graph.h"
#include "JohnsonAlgo/donaldson_algo.h"

int main() {
  DonaldsonAlgo algo("data/airports.dat.txt", "data/routes.dat.txt");
  std::vector<Airport> longest_cycle = algo.GetLongestCycle();

  

  return 1;
}