#include "airport.h"
#include "route.h"
#include "graph.h"
#include "JohnsonAlgo/donaldson_algo.h"
#include "visualizer.h"

#include <algorithm>
#include <chrono>

using namespace std::chrono;

int main() {
  Graph graph("data/airports.dat.txt", "data/routes.dat.txt");
  std::vector<Airport> airports;

  airports.push_back(graph.GetAirport("JFK"));
  airports.push_back(graph.GetAirport("DFW"));
  airports.push_back(graph.GetAirport("ORD"));
  airports.push_back(graph.GetAirport("LAX"));
  airports.push_back(graph.GetAirport("SEA"));
  airports.push_back(graph.GetAirport("ATL"));

  Visualizer::VisualizePath(airports);

  return 1;
}