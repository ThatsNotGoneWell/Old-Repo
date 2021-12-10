#include "cs225/catch/catch.hpp"

#include "graph.h"
#include "visualizer.h"

Graph graph("data/airports.dat.txt", "data/routes.dat.txt");

TEST_CASE("Draw All Canadian Routes", "[weight=1]") {
  std::vector<Airport> airports;

  for (const auto& airport : graph.GetAirports()) {
    if (airport.get_country() == "Canada") {
      airports.push_back(airport);
    }
  }

  Visualizer::VisualizePath(airports, 1939, 1010, "world_map.png", "canadian_routes.png");
  REQUIRE(airports[0].get_id() == "YAM");
}

TEST_CASE("Draw All Russian Routes", "[weight=1]") {
  std::vector<Airport> airports;

  for (const auto& airport : graph.GetAirports()) {
    if (airport.get_country() == "Russia") {
      airports.push_back(airport);
    }
  }

  Visualizer::VisualizePath(airports, 1939, 1010, "world_map.png", "russian_routes.png");
  REQUIRE(airports[0].get_id() == "YKS");
}

TEST_CASE("Draw All Australian Routes", "[weight=1]") {
  std::vector<Airport> airports;

  for (const auto& airport : graph.GetAirports()) {
    if (airport.get_country() == "Australia") {
      airports.push_back(airport);
    }
  }

  Visualizer::VisualizePath(airports, 1939, 1010, "world_map.png", "australian_routes.png");
  REQUIRE(airports[0].get_id() == "ACF");
}

TEST_CASE("Draw All Brazilian Routes", "[weight=1]") {
  std::vector<Airport> airports;

  for (const auto& airport : graph.GetAirports()) {
    if (airport.get_country() == "Brazil") {
      airports.push_back(airport);
    }
  }

  Visualizer::VisualizePath(airports, 1939, 1010, "world_map.png", "brazilian_routes.png");
  REQUIRE(airports[0].get_id() == "CDJ");
}

TEST_CASE("Draw Dummy Routes", "[weight=1]") {
  std::vector<Airport> airports;

  airports.push_back(graph.GetAirport("JFK"));
  airports.push_back(graph.GetAirport("ORD"));
  airports.push_back(graph.GetAirport("LAX"));
  airports.push_back(graph.GetAirport("ATL"));

  std::vector<std::vector<int>> points = Visualizer::VisualizePath(airports, 1939, 1010, "world_map.png", "dummy_routes.png");\

  REQUIRE(airports[0].get_id() == "JFK");
  REQUIRE(airports[1].get_id() == "ORD");
  REQUIRE(airports[2].get_id() == "LAX");
  REQUIRE(airports[3].get_id() == "ATL");

  // Check that all the airports are mapped to the correct x, y coordinates
  REQUIRE(points[1][0] == 572);
  REQUIRE(points[1][1] == 276);
  REQUIRE(points[1][2] == 496);
  REQUIRE(points[1][3] == 269);

  REQUIRE(points[2][0] == 496);
  REQUIRE(points[2][1] == 269);
  REQUIRE(points[2][2] == 331);
  REQUIRE(points[2][3] == 314);

  REQUIRE(points[3][0] == 331);
  REQUIRE(points[3][1] == 314);
  REQUIRE(points[3][2] == 514);
  REQUIRE(points[3][3] == 316);
}