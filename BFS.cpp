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

#include "graph.h"
#include "BFS.h"
#include "airport.h"

BFS::BFS(Graph graph) {
    adj_list = graph.MakeAdjacencyList();
    num_of_airports = graph.get_vertices().size();

    // represent airports in a vector so we can use indexing (possibly need to change constructor or read_airports)
    for (auto elem : graph.get_vertices()) {
        airport_map.emplace(elem.second.get_index(), elem.first);
        //std::cout << elem.first << i << std::endl;
    }

    //print out adj list
    // for (unsigned long i = 0; i < adj_list.size(); i++)
    // {
    //     for (unsigned long j = 0; j < adj_list[i].size(); j++)
    //     {
    //         std::cout << adj_list[i][j] << " ";
    //     }   
    // }
    // std::cout << std::endl;

    // prints out adj edges for departure and arrival airports
    // std::cout << "Departure connecting airports: ";
    // for (unsigned long i = 0; i < adj_list[departure_index].size(); i++) {
    //     std::cout << adj_list[departure_index][i] << " ";
    // }
    
    // std::cout << "Arrival connecting airports: ";
    // for (unsigned long i = 0; i < adj_list[arrival_index].size(); i++) {
    //     std::cout << adj_list[arrival_index][i] << " ";
    // }
}

// checks if path exists and finds shortest one
bool BFS::findShortestPath(std::string departure, std::string arrival, int prev_nodes[], int node_dists[]) {
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

void BFS::printShortestPath(std::string departure, std::string arrival) {
    int prev_nodes[num_of_airports], node_dists[num_of_airports];
 
    // checks for a path
    if (findShortestPath(departure, arrival, prev_nodes, node_dists) == false) {
        std::cout << "No path found" << std::endl;
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
 
    // prints path
    std::cout << "\nShortest path length is: " << node_dists[arrival_index];
    std::cout << "\nPath is: ";
    for (auto elem : airport_path) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    
}