#include "cs225/catch/catch.hpp"

#include "graph.h"
#include "visualizer.h"

Graph graph("data/airports.dat.txt", "data/routes.dat.txt");

TEST_CASE("Draw All Routes", "[weight=1]") {
  std::vector<Airport> airports;

  for (const auto& airport : graph.GetAirports()) {
    airports.push_back(airport);
  }
  
  Visualizer::VisualizePath(airports, 1944, 1009, "world_map.png", "all_routes");
  REQUIRE(airports[0].GetID() == "GKA");
}

TEST_CASE("Draw All Canadian Routes", "[weight=1]") {
  std::vector<Airport> airports;

  for (const auto& airport : graph.GetAirports()) {
    if (airport.GetCountry() == "Canada") {
      airports.push_back(airport);
    }
  }
  
  Visualizer::VisualizePath(airports, 1944, 1009, "world_map.png", "canadian_routes");
  REQUIRE(airports[0].GetID() == "YAM");
}

TEST_CASE("Draw All Russian Routes", "[weight=1]") {
  std::vector<Airport> airports;

  for (const auto& airport : graph.GetAirports()) {
    if (airport.GetCountry() == "Russia") {
      airports.push_back(airport);
    }
  }

  Visualizer::VisualizePath(airports, 1944, 1009, "world_map.png", "russian_routes");
  REQUIRE(airports[0].GetID() == "YKS");
}

TEST_CASE("Draw All Brazilian Routes", "[weight=1]") {
  std::vector<Airport> airports;

  for (const auto& airport : graph.GetAirports()) {
    if (airport.GetCountry() == "Brazil") {
      airports.push_back(airport);
    }
  }

  Visualizer::VisualizePath(airports, 1944, 1009, "world_map.png", "brazilian_routes");
  REQUIRE(airports[0].GetID() == "CDJ");
}

TEST_CASE("Draw Dummy Routes", "[weight=1]") {
  std::vector<Airport> airports;

  airports.push_back(graph.GetAirport("JFK"));
  airports.push_back(graph.GetAirport("ORD"));
  airports.push_back(graph.GetAirport("LAX"));
  airports.push_back(graph.GetAirport("ATL"));

  std::vector<std::vector<int>> points = Visualizer::VisualizePath(airports, 1944, 1009, "world_map.png", "dummy_routes");

  REQUIRE(airports[0].GetID() == "JFK");
  REQUIRE(airports[1].GetID() == "ORD");
  REQUIRE(airports[2].GetID() == "LAX");
  REQUIRE(airports[3].GetID() == "ATL");

  // Check that all the airports are mapped to the correct x, y coordinates
  REQUIRE(points[1][0] == 573);
  REQUIRE(points[1][1] == 276);
  REQUIRE(points[1][2] == 497);
  REQUIRE(points[1][3] == 269);

  REQUIRE(points[2][0] == 497);
  REQUIRE(points[2][1] == 269);
  REQUIRE(points[2][2] == 332);
  REQUIRE(points[2][3] == 314);

  REQUIRE(points[3][0] == 332);
  REQUIRE(points[3][1] == 314);
  REQUIRE(points[3][2] == 516);
  REQUIRE(points[3][3] == 315);
}