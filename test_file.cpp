#include "catch/catch.hpp" 

#include "graph.h" 
#include "dijkstra.h" 

Graph graph("data/airports.dat.txt", "data/routes.dat.txt"); 

TEST_CASE( "check airports that needs to travel directly " ,"[weight = 1]") {
  dijkstra dijkstra_  ;
  std::vector < Airport> tem   = dijkstra_  . find_shortest("ORD", "SFO" ) ;
  
  REQUIRE(tem[0].get_id() == "SFO");
  REQUIRE(tem[1].get_id() == "ORD");
} 


TEST_CASE( "check airports that needs to travel across nodes " ,"[weight = 1]") {
  dijkstra dijkstra_  ;
  std::vector < Airport> tem   = dijkstra_  . find_shortest("YHM", "YHY" ) ;
  
  REQUIRE(tem[0].get_id() == "YHY" ) ;
  REQUIRE(tem[1].get_id() == "YEG"); 
  REQUIRE(tem[2].get_id() == "YHM");
  
}
TEST_CASE( "check airports that doesn't need to travel " ,"[weight = 1]") {
  dijkstra dijkstra_  ;
  std::vector < Airport> tem   = dijkstra_  . find_shortest("YHY", "YHY" ) ;
  
  REQUIRE (true ) ;
} 
TEST_CASE( "check airports that are not there  arrival " ,"[weight = 1]") {
  dijkstra dijkstra_  ;
  std::vector < Airport> tem   = dijkstra_  . find_shortest("ABG", "YHY" ) ;
  
  REQUIRE ( tem[0].get_id( ) == "ABG"  ) ;
}
TEST_CASE( "check airports that are not there destinastion " ,"[weight = 1]") {
  dijkstra dijkstra_  ;
  std::vector < Airport> tem   = dijkstra_  . find_shortest("YHY", "ABG" ) ;
  
  REQUIRE ( tem[0] .get_id( )  == "ABG"  ) ;
}
TEST_CASE( "check airports that are accross countries   " ,"[weight = 1]") {
  dijkstra dijkstra_  ;
  std::vector < Airport> tem   = dijkstra_  . find_shortest("MUC", "YHY" ) ; 
  REQUIRE ( tem[0]. get_id( ) == "YHY"  ) ;
  REQUIRE ( tem[1]. get_id( ) == "YEG"  ) ; 
  REQUIRE ( tem[2]. get_id( ) == "KEF"  ) ;
  REQUIRE ( tem[3]. get_id( ) == "MUC"  ) ;
}
TEST_CASE( "check airports that are accross country longer 2  " ,"[weight = 1]") {
  dijkstra dijkstra_  ;
  std::vector < Airport> tem   = dijkstra_  . find_shortest("ABJ", "MNL" ) ; 
  REQUIRE ( tem[0]. get_id( ) == "MNL"  ) ;
  REQUIRE ( tem[1]. get_id( ) == "JED"  ) ; 
  REQUIRE ( tem[2]. get_id( ) == "NDJ"  ) ;
  REQUIRE ( tem[3]. get_id( ) == "ABV"  ) ; 
  REQUIRE ( tem[4]. get_id( ) == "LFW"  ) ;
  REQUIRE ( tem[5]. get_id( ) == "ABJ"  ) ;
} 
TEST_CASE( "check airports that are accross country longer 3  " ,"[weight = 1]") {
  dijkstra dijkstra_  ;
  std::vector < Airport> tem   = dijkstra_  . find_shortest("YHY", "PEK" ) ; 
  REQUIRE ( tem[0]. get_id( ) == "PEK"  ) ;
  REQUIRE ( tem[1]. get_id( ) == "YVR"  ) ; 
  REQUIRE ( tem[2]. get_id( ) == "YEG"  ) ;
  REQUIRE ( tem[3]. get_id( ) == "YHY"  ) ; 
  
} 
TEST_CASE( "check airports that are not accross  " ,"[weight = 1]") {
  dijkstra dijkstra_  ;
  std::vector < Airport> tem   = dijkstra_  . find_shortest("BNU", "PEK" ) ; 
  REQUIRE (tem.size( ) == 0 );
  
} 