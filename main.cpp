#include "airport.h"
#include "route.h"
#include "graph.h"
#include "BFS.h"
#include "dijkstra.h" 
#include <vector>

int main() {
    //Graph graph("data/airports.dat.txt", "data/routes.dat.txt");
    dijkstra dikstra_("SFO", "CMI");
  dikstra_.find_shortest( ) ;
    dikstra_.get_shortest();
    BFS bfs("SFO", "CMI");
     bfs.printShortestPath();
    
    return 1;
}