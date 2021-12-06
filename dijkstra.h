#pragma once 
#include <stdexcept>
#include <unordered_map>
#include <list>
#include <cmath>
#include <unordered_map>

#include "graph.h"
#include "airport.h"
typedef std::pair <int,int> adj ;
class dijkstra {
public :
  dijkstra ( std::string arrival_ , std::string departure_ ) ;
  void find_shortest ( ) ;
  void get_shortest ( ) ;
private :
  std::vector <adj> distance_ ;
  int arrival_idx ;
  int departure_idx ;
  std::vector<std::vector<int>> adj_list; 
  
};