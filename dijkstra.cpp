#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <stdexcept>
#include <unordered_map>
#include <list>
#include <cmath>
#include <bits/stdc++.h>
#include <unordered_map>

#include "graph.h"
#include "dijkstra.h"
#include "airport.h"

#define infinite  1000000000  
typedef std::pair<double,int> pair_t ;
dijkstra :: dijkstra ( std::string arrival_ ,  std::string departure_ ) {
  Graph graph("data/airports.dat.txt", "data/routes.dat.txt");
  adj_list = graph.MakeAdjacencyList(); 
  for (auto elem : graph.get_vertices()) {
    if (elem.first == departure_) {
      departure_idx = elem.second.get_index();
    }  
  }
  for (auto elem : graph.get_vertices()) {
    if(elem.first == arrival_) {
      arrival_idx = elem.second.get_index();;
    }
  }
  std::cout << arrival_idx <<" " << departure_idx << std:: endl ;
}
 void dijkstra :: find_shortest ( ) {

  Graph graph("data/airports.dat.txt", "data/routes.dat.txt");
   
    
    std::list<Route> kEdges = graph .get_kEdges ( );
    std::unordered_map<std::string, Airport> kVertices = graph. GetVerticies( ) ;
    std::vector<Airport> kAirports  = graph . get_airports( ) ;
    
    
    std :: priority_queue < pair_t , std::vector <pair_t> , std::greater<pair_t>   > q ; 
      for ( size_t i=0 ; i <  graph. get_vertices( ) . size( ) ; i++   ){
        distance_ .push_back ( std::make_pair (infinite , -1) ) ; 
         
      } 
    q. push (  std:: make_pair ( 0 , departure_idx )) ;
    distance_ [ departure_idx ] .first  = 0 ;
    while ( q . empty ( ) == false ) {
      int temp_idx = q .top( ) . second ;
      q .pop ( ) ;
      for (auto i = adj_list[ temp_idx ] . begin ( ) ; i != adj_list[temp_idx ] . end ( )  ; ++i ){
        int  vert =  *i    ; 
        double  weig = graph. CalculateAirportDistance( kAirports [temp_idx ]    , kAirports [vert ] )  ;
        if ( distance_[vert].first > distance_[temp_idx].first  + weig) {
          distance_[ vert ].first = distance_ [temp_idx].first + weig ; 
          distance_ [vert ].second = temp_idx ; 
          q. push (std::make_pair ( distance_[vert ].first ,vert )) ;
          
        }
      }
    }
    // std::cout << kAirports[ departure_idx ]. get_name ( ) ; 
    
    
    
}
bool dijkstra :: get_shortest ( ) {
  Graph graph("data/airports.dat.txt", "data/routes.dat.txt");
  std::vector<Airport> kAirports  = graph . get_airports( ) ;
  int i = arrival_idx  ;
  while ( true ){ 
    // std::cout << kAirports [i ] . get_id ( )    ;
    visalization .push (kAirports [i ] )  ;
    i= distance_ [i ] .second ;
    if ( i == -1 ) {
     return false  ;
    }
    if ( i == departure_idx ) {
      visalization .push (kAirports [i ] )  ;
      break ;
    }
  }
  while ( visalization . empty( ) == false ) {
    visua . push_back ( visalization .top ( ) ) ;
    visalization .pop( );
  }
  return true ;
  
}