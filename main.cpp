#include "airport.h"
#include "route.h"
#include "graph.h"
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
  airports.push_back(graph.GetAirport("LHR"));
  airports.push_back(graph.GetAirport("SXF"));
  airports.push_back(graph.GetAirport("DXB"));
  airports.push_back(graph.GetAirport("SVO"));
  airports.push_back(graph.GetAirport("DEL"));
  airports.push_back(graph.GetAirport("PEK"));
  airports.push_back(graph.GetAirport("ICN"));
  airports.push_back(graph.GetAirport("HND"));
  airports.push_back(graph.GetAirport("SYD"));

  std::vector<std::vector<int>> points = Visualizer::VisualizePath(airports, 1944, 1009, "world_map.png", "dummy_routes.png");
  
  return 1;
}