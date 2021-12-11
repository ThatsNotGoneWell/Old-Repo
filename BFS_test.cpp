#include "cs225/catch/catch.hpp"

#include "BFS.h"
#include "graph.h"

Graph bfs_graph("data/airports.dat.txt", "data/routes.dat.txt");
BFS bfs(bfs_graph);

// 0
TEST_CASE("Check inputs are valid", "[weight=1]") {
    bfs.printShortestPath("", "");
    
    REQUIRE(bfs.getRouteLength() == 0);
}

// 1
TEST_CASE("Check SFO to PEK", "[weight=1]") {
    bfs.printShortestPath("PEK", "SFO");
    
    REQUIRE(bfs.getPath().at(0) == "SFO");
    REQUIRE(bfs.getPath().at(1) == "PEK");
    REQUIRE(bfs.getRouteLength() == 2);
}

// 2
TEST_CASE("Check ATL to DIA", "[weight=1]") {
    bfs.printShortestPath("DIA", "ATL");
   
    REQUIRE(bfs.getRouteLength() == 0);
}

// 3
TEST_CASE("Check RKV to RDD", "[weight=1]") {
    bfs.printShortestPath("RDD", "RKV");
    
    REQUIRE(bfs.getPath().at(0) == "RKV");
    REQUIRE(bfs.getPath().at(1) == "GOH");
    REQUIRE(bfs.getPath().at(2) == "KEF");
    REQUIRE(bfs.getPath().at(3) == "JFK");
    REQUIRE(bfs.getPath().at(4) == "SFO");
    REQUIRE(bfs.getPath().at(5) == "RDD");
    REQUIRE(bfs.getRouteLength() == 6);
}

// 4
TEST_CASE("Check CMI to SFO", "[weight=1]") {
    bfs.printShortestPath("SFO", "CMI");
    
    REQUIRE(bfs.getPath().at(0) == "CMI");
    REQUIRE(bfs.getPath().at(1) == "DFW");
    REQUIRE(bfs.getPath().at(2) == "SFO");
    REQUIRE(bfs.getRouteLength() == 3);
}

// 5
TEST_CASE("Check SYD to ORD", "[weight=1]") {
    bfs.printShortestPath("ORD", "SYD");
    
    REQUIRE(bfs.getPath().at(0) == "SYD");
    REQUIRE(bfs.getPath().at(1) == "AUH");
    REQUIRE(bfs.getPath().at(2) == "ORD");
    REQUIRE(bfs.getRouteLength() == 3);
}

// 6
TEST_CASE("Check SJC to RKV", "[weight=1]") {
    bfs.printShortestPath("RKV", "SJC");
    
    REQUIRE(bfs.getPath().at(0) == "SJC");
    REQUIRE(bfs.getPath().at(1) == "BOS");
    REQUIRE(bfs.getPath().at(2) == "KEF");
    REQUIRE(bfs.getPath().at(3) == "GOH");
    REQUIRE(bfs.getPath().at(4) == "RKV");
    REQUIRE(bfs.getRouteLength() == 5);
}

// 7
TEST_CASE("Check IPC to PEK", "[weight=1]") {
    bfs.printShortestPath("PEK", "IPC");
    
    REQUIRE(bfs.getPath().at(0) == "IPC");
    REQUIRE(bfs.getPath().at(1) == "SCL");
    REQUIRE(bfs.getPath().at(2) == "YYZ");
    REQUIRE(bfs.getPath().at(3) == "PEK");
    REQUIRE(bfs.getRouteLength() == 4);
}