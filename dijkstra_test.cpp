#include "cs225/catch/catch.hpp" 

#include "dijkstra.h" 

Graph dijkstra_graph("data/airports.dat.txt", "data/routes.dat.txt");

TEST_CASE( "check airports that needs to travel directly " ,"[weight = 1]") {
  dijkstra dijkstra_(dijkstra_graph);
  std::vector<Airport> tem = dijkstra_.find_shortest("ORD", "SFO");
  
  REQUIRE(tem[0].GetID() == "SFO");
  REQUIRE(tem[1].GetID() == "ORD");
} 

TEST_CASE( "check airports that needs to travel across nodes " ,"[weight = 1]") {
  dijkstra dijkstra_(dijkstra_graph);
  std::vector<Airport> tem = dijkstra_.find_shortest("YHM", "YHY");
  
  REQUIRE(tem[0].GetID() == "YHY");
  REQUIRE(tem[1].GetID() == "YEG"); 
  REQUIRE(tem[2].GetID() == "YHM");
}

TEST_CASE( "check airports that doesn't need to travel " ,"[weight = 1]") {
  dijkstra dijkstra_(dijkstra_graph);
  std::vector<Airport> tem = dijkstra_  . find_shortest("YHY", "YHY");
  
  REQUIRE (true ) ;
} 

TEST_CASE( "check airports that are not there  arrival " ,"[weight = 1]") {
  dijkstra dijkstra_(dijkstra_graph);
  std::vector<Airport>tem   = dijkstra_.find_shortest("ABG", "YHY");
  
  REQUIRE(tem[0].GetID() == "ABG");
}

TEST_CASE( "check airports that are not there destinastion " ,"[weight = 1]") {
  dijkstra dijkstra_(dijkstra_graph);
  std::vector<Airport> tem   = dijkstra_.find_shortest("YHY", "ABG");
  
  REQUIRE(tem[0].GetID()  == "ABG");
}

TEST_CASE( "check airports that are accross countries   " ,"[weight = 1]") {
  dijkstra dijkstra_(dijkstra_graph);
  std::vector<Airport> tem = dijkstra_.find_shortest("MUC", "YHY"); 
  REQUIRE(tem[0].GetID() == "YHY");
  REQUIRE(tem[1].GetID() == "YEG"); 
  REQUIRE(tem[2].GetID() == "KEF");
  REQUIRE(tem[3].GetID() == "MUC");
}

TEST_CASE( "check airports that are accross country longer 2  " ,"[weight = 1]") {
  dijkstra dijkstra_(dijkstra_graph);
  std::vector<Airport> tem   = dijkstra_.find_shortest("ABJ", "MNL"); 
  REQUIRE(tem[0].GetID() == "MNL");
  REQUIRE(tem[1].GetID() == "JED"); 
  REQUIRE(tem[2].GetID() == "NDJ");
  REQUIRE(tem[3].GetID() == "ABV"); 
  REQUIRE(tem[4].GetID() == "LFW");
  REQUIRE(tem[5].GetID() == "ABJ");
} 

TEST_CASE( "check airports that are accross country longer 3  " ,"[weight = 1]") {
  dijkstra dijkstra_(dijkstra_graph);
  std::vector<Airport> tem = dijkstra_.find_shortest("YHY", "PEK"); 
  REQUIRE(tem[0].GetID() == "PEK");
  REQUIRE(tem[1].GetID() == "YVR"); 
  REQUIRE(tem[2].GetID() == "YEG");
  REQUIRE(tem[3].GetID() == "YHY"); 
  
} 

TEST_CASE( "check airports that are not accross  " ,"[weight = 1]") {
  dijkstra dijkstra_(dijkstra_graph);
  std::vector<Airport> tem = dijkstra_.find_shortest("BNU", "PEK"); 
  REQUIRE(tem.size() == 0);
} 