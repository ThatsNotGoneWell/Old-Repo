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

BFS::BFS(const std::string departure, const std::string arrival) {
    Graph graph("data/airports.dat.txt", "data/routes.dat.txt");
    adj_list = graph.MakeAdjacencyList();
    num_of_airports = graph.get_vertices().size();

    // represent airports in a vector so we can use indexing (possibly need to change constructor or read_airports)
    for (auto elem : graph.get_vertices()) {
        if (elem.first == departure) {
            departure_index = elem.second.get_index();
        } else if (elem.first == arrival) {
            arrival_index = elem.second.get_index();;
        }
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

    std::cout << departure_index << std::endl;
    std::cout << arrival_index << std::endl;   
}


// indicies instead of airport objects themselves
bool BFS::findShortestPath(int pred[], int dist[]) {
    // finds indicies of departure and arrival airports
    // for (auto elem : airport_map) {
    //     if (elem.second == departure) {
    //         departure_index = elem.first;
    //     } else if (elem.second == arrival) {
    //         arrival_index = elem.first;
    //     }
    // }


    // array to track visited nodes
    bool visited[num_of_airports];
    
    // none of the nodes are visited initally so we set distances to infinity and predecessors to -1
    for (int i = 0; i < num_of_airports; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }
    
    // queue to queue veriticies that have yet to be visited
    std::list<int> queue;
 
    // we visit departure first and has 0 distance to itself
    visited[departure_index] = true;
    dist[departure_index] = 0;
    queue.push_back(departure_index);
 
    // BFS
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (unsigned long i = 0; i < adj_list[u].size(); i++) {
            if (visited[adj_list[u][i]] == false) {
                visited[adj_list[u][i]] = true;
                dist[adj_list[u][i]] = dist[u] + 1;
                pred[adj_list[u][i]] = u;
                queue.push_back(adj_list[u][i]);
 
                // destination found
                if (adj_list[u][i] == arrival_index) {
                    //std::cout << "Path Found!" << std::endl;
                    return true;
                }
            }   
        }
    }
    //std::cout << "No Path Found!" << std::endl;
    return false;
}

void BFS::printShortestPath() {
    int pred[num_of_airports], dist[num_of_airports];
 
    // checks for a path
    if (findShortestPath(pred, dist) == false) {
        std::cout << "Given source and destination are not connected";
        return;
    }
 
    // vector path stores the shortest path
    std::vector<int> path;
    int crawl = arrival_index;
    path.push_back(crawl);
    while (pred[crawl] != -1) {
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }
 
    // distance from source is in distance array
    std:: cout << "Shortest path length is : " << dist[arrival_index];
 
    // printing path from source to destination in 3 letter
    std::cout << "\nPath is: ";
    for (int i = path.size() - 1; i >= 0; i--) {
        std::cout << airport_map.at(path[i]) << " ";
    }

    // printing path from source to destination in index
    std::cout << "\nPath is: ";
    for (int i = path.size() - 1; i >= 0; i--) {
        std::cout << path[i] << " ";
    }

    path_length = path.size();
}