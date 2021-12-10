#pragma once 
#include <stdexcept>
#include <unordered_map>
#include <list>
#include <cmath>
#include <unordered_map>
#include <stack>

#include "graph.h"
#include "airport.h"
typedef std::pair <int,int> adj ;
class dijkstra {
public :
  dijkstra ( std::string arrival_ , std::string departure_ ) ;
  void find_shortest ( ) ;
  bool get_shortest ( ) ;
  std::vector<Airport> get_visual ( ) { return visua ; }   
private :
  std::vector <adj> distance_ ;
  int arrival_idx ;
  int departure_idx ;
  std::vector<std::vector<int>> adj_list; 
  std::stack <Airport> visalization ;
  std:: vector <Airport> visua ;
};