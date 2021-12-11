// BFS
// modify graph object such:
//    - Have a count of number of airports (nodes)
//    - Have an adjacency list for each airport (neighboring nodes)
// our graph has to be unweighted

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

// #include "graph.h"
#include "BFS.h"
// #include "airport.h"

BFS::BFS(const Graph& graph) {
    adj_list = graph.MakeAdjacencyList();
    num_of_airports = graph.GetVertices().size();

    // maps airports to an index
    for (auto elem : graph.GetVertices()) {
        airport_map.emplace(elem.second.GetIndex(), elem.first);
        airport_obj_copies.emplace(elem.first, elem.second);
    }
}

// checks if path exists and finds shortest one
bool BFS::findShortestPath(const std::string& departure, const std::string& arrival, int prev_nodes[], int node_dists[]) {
    // finds indicies of departure and arrival airports
    for (auto elem : airport_map) {
        if (elem.second == departure) {
            departure_index = elem.first;
        } else if (elem.second == arrival) {
            arrival_index = elem.first;
        }
    }
    
    // none of the nodes are visited initally so we set distances to infinity and predecessors to -1
    bool visited[num_of_airports];
    for (int i = 0; i < num_of_airports; i++) {
        visited[i] = false;
        node_dists[i] = INT_MAX;
        prev_nodes[i] = -1;
    }
    
    // queue to queue veriticies that have yet to be visited
    std::list<int> q;
 
    // we visit departure first and has 0 distance to itself
    visited[departure_index] = true;
    node_dists[departure_index] = 0;
    q.push_back(departure_index);
 
    // BFS step
    while (!q.empty()) {
        int j = q.front();
        q.pop_front();
        for (unsigned long k = 0; k < adj_list[j].size(); k++) {
            if (!visited[adj_list[j][k]]) {
                visited[adj_list[j][k]] = true;
                node_dists[adj_list[j][k]] = node_dists[j] + 1;
                prev_nodes[adj_list[j][k]] = j;
                q.push_back(adj_list[j][k]);
 
                if (adj_list[j][k] == arrival_index) {
                    return true;
                }
            }   
        }
    }
    return false;
}

void BFS::printShortestPath(const std::string& departure, const std::string& arrival) {
    // checks if departure and arrival airports are valid
    try {
        airport_obj_copies.at(departure);
        airport_obj_copies.at(arrival);
    } catch (...) {
        std::cout << "\nOne of your airports does not exist!" << std::endl;
        return;
    }

    int prev_nodes[num_of_airports], node_dists[num_of_airports];
 
    // checks for a path
    if (findShortestPath(departure, arrival, prev_nodes, node_dists) == false) {
        std::cout << "\nNo path found from " << arrival << " to " << departure << std::endl;
        airport_path.clear();
        return;
    }
    
    // empties path and creates new one
    airport_path.clear();
    int temp = arrival_index;
    airport_path.push_back(airport_map.at(temp));
    while (prev_nodes[temp] != -1) {
        airport_path.push_back(airport_map.at(prev_nodes[temp]));
        temp = prev_nodes[temp];
    }
 
    // prints path and adds airports to visualization vector (input for visualizaiton)
    std::cout << "\nShortest path length is: " << node_dists[arrival_index];
    std::cout << "\nPath is: ";
    for (auto elem : airport_path) {
        std::cout << elem << " ";
        visualization_path.push_back(airport_obj_copies.at(elem));
    }
    std::cout << std::endl;
}