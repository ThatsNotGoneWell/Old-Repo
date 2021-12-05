#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <unordered_map>
#include <list>
#include <cmath>
#include <unordered_map>

#include "graph.h"
#include "airport.h"

class BFS {

public:
    BFS(const std::string departure, const std::string arrival);

    bool findShortestPath(int pred[], int dist[]);

    int getNumAirports() { return num_of_airports; }

    int getDepartureIndex() { return departure_index; }

    int getArrivalIndex() { return arrival_index; }

    std::vector<std::vector<int>> getAdjList() { return adj_list; }
    
    void printShortestPath();
private:
    int num_of_airports, departure_index, arrival_index;
    std::unordered_map<std::string, Airport> routes;
    std::vector<std::vector<int>> adj_list;
    std::unordered_map<int, std::string> airport_map;
};