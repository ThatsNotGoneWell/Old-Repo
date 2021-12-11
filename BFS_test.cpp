#include "cs225/catch/catch.hpp"

#include "BFS.h"



TEST_CASE("Check SFO to CMI", "[weight=1]") {
    BFS bfs1("SFO", "CMI");
    bfs1.printShortestPath();
  
    REQUIRE(bfs1.getAirport(bfs1.getDepartureIndex()) == "SFO");
    REQUIRE(bfs1.getAirport(bfs1.getArrivalIndex()) == "CMI");
    REQUIRE(bfs1.getRouteLength() == 3);
}
