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

#define infinite 1000000000
typedef std::pair<double,int> pair_t ;

dijkstra::dijkstra() : kGraph_("data/airports.dat.txt", "data/routes.dat.txt") {}

std::vector<Airport> dijkstra::find_shortest(const std::string& arrival, const std::string& departure) {
  std::vector<adj> distance_;
  int arrival_idx = kGraph_.get_airport(arrival).get_index();
  int departure_idx = kGraph_.get_airport(departure).get_index();
  
  
  if ( kGraph_.get_airport(arrival).get_id( ) == "NULL"  ){
    std:: cout << 1 ;
    std::vector<Airport> tem ;
    tem . push_back( Airport (arrival ,"","" , 0, 0, -1) ) ;
    return tem ;
  }
  if ( kGraph_.get_airport(departure ).get_id ( ) == "NULL"  ){
    std::vector<Airport> tem ;
    tem . push_back( Airport (departure ,"","" , 0, 0, -1) ) ;
    return tem ;
  }
  std::vector<std::vector<int>> adj_list = kGraph_.MakeAdjacencyList(); 
  
  std::priority_queue<pair_t, std::vector<pair_t>, std::greater<pair_t>> q; 
  q.push(std::make_pair(0, departure_idx));
  
  for (size_t i = 0; i < kGraph_.get_vertices().size(); i++) {
    distance_.push_back(std::make_pair(infinite, -1)); 
  } 
  
  distance_[departure_idx].first = 0;
  
  while ( q.empty() == false) {
    int temp_idx = q.top().second;
    q.pop();
    
    Airport current_airport = kGraph_.get_airports()[temp_idx];
    for (int adjacent_index : adj_list[temp_idx]) {
      
      Airport adjacent_airport = kGraph_.get_airports()[adjacent_index];
      double distance = kGraph_.CalculateAirportDistance(current_airport, adjacent_airport);
      
      if (distance_[adjacent_index].first > distance_[temp_idx].first + distance) {
        distance_[adjacent_index].first = distance_[temp_idx].first + distance; 
        distance_[adjacent_index].second = temp_idx ; 
        q.push(std::make_pair(distance_[adjacent_index].first, adjacent_index)) ;
      }
    }
  }    
  
  return get_shortest(distance_, arrival_idx, departure_idx);
}

std::vector<Airport> dijkstra::get_shortest(const std::vector<adj>& distance_, int arrival_idx, int departure_idx) {
  int index = arrival_idx;
  
  std::stack<Airport> visalization;
  std::vector<Airport> shortest_path;
  
  while (true) { 
    visalization.push(kGraph_.get_airports()[index]);
    index = distance_[index].second;
    
    if (index == -1) {
      return shortest_path;
    } else if (index == departure_idx) {
      visalization.push(kGraph_.get_airports()[index]);
      break;
    }
  }
  
  while (!visalization.empty()) {
    shortest_path.push_back(visalization.top());
    visalization.pop();
  }
  
  return shortest_path; 
}