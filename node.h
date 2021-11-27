#pragma once 
#include <string> 
#include "graph.h"  
#include "route.h"  
#include "airport.h"


class node {
  
public : 
  node ( std :: vector < node* > next_nodes_ ,
           std :: vector < double > distance_ ,
           const std:: string &  current_node_name_  , 
           std :: vector < bool > visited_ ) : 
            next_nodes (  next_nodes_ )  ,
            distance (  distance_ ) , 
            current (  current_node_name_ )  ,
            visited (  false  ) { } ; 
  node ( ) {visited =   false  ; } 
   
   
  std :: string get_current ( ) const { return current ;  }
  std :: vector < node* >  get_next_nodes ( ) const { return next_nodes ; }
  std :: vector < double > get_distance ( ) const { return distance ; }
    bool get_visited ( ) const { return visited ; }
  void  set_current (  std :: string current_ )   { current =  current_ ; }
  void  set_dis (  double  distan )   { distance .push_back (   distan ) ; }
  void  set_next_nodes  (  node * nodes  )   { next_nodes .push_back (  nodes ) ; }
  void set_visited ( bool value  )  { visited = value  ; }
private :
  std :: vector < node* > next_nodes ; 
  std :: vector < double > distance ;
    bool  visited ;
   std:: string  current ; 
};