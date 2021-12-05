#include "airport.h"
#include "route.h"
#include "graph.h"
#include "BFS.h"
#include <vector>

int main() {
    //Graph graph("data/airports.dat.txt", "data/routes.dat.txt");
    BFS bfs("SFO", "CMI");
    bfs.printShortestPath();
    
    return 1;
}