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
    BFS(Graph graph);

    bool findShortestPath(const std::string departure, const std::string arrival, int prev_nodes[], int node_dists[]);

    void printShortestPath(const std::string departure, const std::string arrival);

    int getNumAirports() { return num_of_airports; }

    int getDepartureIndex() { return departure_index; }

    int getArrivalIndex() { return arrival_index; }

    int getRouteLength() { return airport_path.size(); }

    std::vector<std::string> getPath() { return airport_path; }

    std::string getAirport(int airport_index) { return airport_map.at(airport_index); }

    std::vector<std::vector<int>> getAdjList() { return adj_list; }
private:
    int num_of_airports, departure_index, arrival_index;
    std::vector<std::vector<int>> adj_list;
    std::unordered_map<int, std::string> airport_map;
    std::vector<std::string> airport_path;
};