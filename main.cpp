#include "airport.h"
#include "route.h"
#include "graph.h"
#include "BFS.h"
#include "dijkstra.h" 
#include <algorithm> 
#include <vector>

int main() {
    //Graph graph("data/airports.dat.txt", "data/routes.dat.txt");
   
    dijkstra dijkstra_  ;
  std::vector < Airport> tem   = dijkstra_  . find_shortest("ABG", "PEK" ) ;
    
   
    
    for ( size_t i = 0 ; i< tem. size ( ) ; i++ ){
      std:: cout << tem [i ] . get_id ( ) ;
    }
    
    
    return 1;
}