#include "airport.h"
#include "route.h"
#include "graph.h"
#include "BFS.h"
#include "dijkstra.h"
#include "visualizer.h"

#include <algorithm>
#include <chrono>

using namespace std::chrono;

int main() {
  Graph graph("data/airports.dat.txt", "data/routes.dat.txt");
  std::vector<Airport> airports;

  dijkstra dijkstra_(graph);
  std::vector<Airport> dijkstra_path = dijkstra_.find_shortest("ORD", "SFO");
  std::vector<std::vector<int>> dijkstra_points = Visualizer::VisualizePath(dijkstra_path, 1944, 1009, "world_map.png", "dijkstra_path");

  BFS bfs(graph);
  bfs.printShortestPath("PEK", "SFO");
  std::vector<Airport> bfs_path = bfs.getVisualizationPath();
  std::vector<std::vector<int>> bfs_points = Visualizer::VisualizePath(bfs_path, 1944, 1009, "world_map.png", "bfs_path");
  
  return 1;
}