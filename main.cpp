#include "airport.h"
#include "route.h"
#include "graph.h"
#include "BFS.h"
#include "dijkstra.h" 
#include <algorithm> 
#include <vector>

int main() {
    //Graph graph("data/airports.dat.txt", "data/routes.dat.txt");
   
    dijkstra dikstra_("YOW", "YHY");
    dikstra_.find_shortest( ) ;
    dikstra_.get_shortest();
    std::vector < Airport> tem  = dikstra_. get_visual ( ) ;
    
    for ( size_t i = 0 ; i< tem. size ( ) ; i++ ){
      std:: cout << tem [i ] . get_id ( ) ;
    }
    
    
    return 1;
}