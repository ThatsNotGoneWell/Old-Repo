#include "cs225/catch/catch.hpp"

#include "BFS.h"
#include "graph.h"

Graph graph("data/airports.dat.txt", "data/routes.dat.txt");
BFS bfs(graph);

// 1
TEST_CASE("Check SFO to PEK", "[weight=1]") {
    bfs.printShortestPath("PEK", "SFO");
    
    REQUIRE(bfs.getPath().at(0) == "SFO");
    REQUIRE(bfs.getPath().at(1) == "PEK");
    REQUIRE(bfs.getRouteLength() == 2);
}

// 2
TEST_CASE("Check CMI to SFO", "[weight=1]") {
    bfs.printShortestPath("SFO", "CMI");
    
    REQUIRE(bfs.getPath().at(0) == "CMI");
    REQUIRE(bfs.getPath().at(1) == "DFW");
    REQUIRE(bfs.getPath().at(2) == "SFO");
    REQUIRE(bfs.getRouteLength() == 3);
}

// 3
TEST_CASE("Check ORD to SYD", "[weight=1]") {
    bfs.printShortestPath("ORD", "SYD");
    
    REQUIRE(bfs.getPath().at(0) == "SYD");
    REQUIRE(bfs.getPath().at(1) == "AUH");
    REQUIRE(bfs.getPath().at(2) == "ORD");
    REQUIRE(bfs.getRouteLength() == 3);
}

// 4
TEST_CASE("Check SJC to RKV", "[weight=1]") {
    bfs.printShortestPath("RKV", "SJC");
    
    REQUIRE(bfs.getPath().at(0) == "SJC");
    REQUIRE(bfs.getPath().at(1) == "BOS");
    REQUIRE(bfs.getPath().at(2) == "KEF");
    REQUIRE(bfs.getPath().at(3) == "GOH");
    REQUIRE(bfs.getPath().at(4) == "RKV");
    REQUIRE(bfs.getRouteLength() == 5);
}

// 5
TEST_CASE("Check IPC to PEK", "[weight=1]") {
    bfs.printShortestPath("PEK", "IPC");
    
    REQUIRE(bfs.getPath().at(0) == "IPC");
    REQUIRE(bfs.getPath().at(1) == "SCL");
    REQUIRE(bfs.getPath().at(2) == "YYZ");
    REQUIRE(bfs.getPath().at(3) == "PEK");
    REQUIRE(bfs.getRouteLength() == 4);
}