#include "airport.h"
#include "route.h"
#include "graph.h"
#include "BFS.h"
#include <vector>

int main() {
    Graph graph("data/airports.dat.txt", "data/routes.dat.txt");
    BFS bfs(graph);
    bfs.printShortestPath("", "");
    // bfs.printShortestPath("ORD", "LAX");
    // bfs.printShortestPath("SFO", "JFK");
    return 1;
}