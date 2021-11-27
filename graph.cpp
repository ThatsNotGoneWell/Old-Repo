

#include "graph.h"
#include "airport.h"
#include "route.h"
#include "node.h" 
Graph::Graph(const std::string& airports_file_name, const std::string& routes_file_name) {
  read_airports(airports_file_name);
  read_routes(routes_file_name); 
  
  for ( auto  c = kVertices_ . begin ( ) ; c !=   kVertices_. end ( ) ; c++  ){ 
    node* temp = new node ( ) ; 
    temp -> set_current ( c -> first  ) ;
    node_holder .push_back ( temp ) ; 
  }
  for ( size_t i = 0 ; i < node_holder .size ( )  ; i++ ) { 
    
    std :: string temp =   node_holder [ i ] -> get_current ( )  ;
    // std :: cout << 1 ;
    for ( size_t j = 0 ; j < get_route ( temp  ) . size ( ) ; j++   ){ 
      // std :: cout << 1 ; 
      std :: string destin = get_route ( temp ) [ j ] . get_destination ( ) . get_id ( ) ;
      // std :: cout << 1 ;
      for ( size_t a = 0 ; a < node_holder .size ( )  ; a++  ) {
        if ( node_holder [a ] -> get_current ( ) == destin  ) {
          node_holder [ i ] -> set_next_nodes ( node_holder [ a ] ) ;
          Airport a_ = get_airport (node_holder[ a ] -> get_current ( )  );
          Airport b_ = get_airport (node_holder [ i ] -> get_current ( ) );
          node_holder [i ] -> set_dis  (  CalculateAirportDistance ( a_ , b_ ) ) ;
         //  std :: cout << 1 ; 
         //  std :: cout << CalculateAirportDistance ( a_ , b_ ) << std :: endl   ; 
        }
        
        
        
      }
    }
  } 
}



void Graph::read_airports(const std::string& airports_file_name) {
  std::ifstream airport_file(airports_file_name);
  std::string line;

  // Open file and iterate through each line to fill airport hash table
  if (airport_file.is_open()) {
    while (getline(airport_file, line)) {

      // Convert line to stringstream object and grab each comma separated value
      std::stringstream ss(line);
      std::vector<std::string> vect;

      while(ss.good()) {
          std::string substr;
          getline(ss, substr, ','); 
          vect.push_back(substr);
      }

      // Try-catch statement essentially ignores invalid or poorly formatted entries from the data
      try {
        // Check if a 3-letter Airport Code exists
        std::string id = vect[4];
        if (id.at(0) != '"') {
            continue;
        }

        // Remove first and last characters from string since they are usuaully surrounded by quotes (eg. ""AYGA"")
        id = id.substr(1, id.size() - 2);
        std::string name = vect[1].substr(1, vect[1].size() - 2);
        std::string city = vect[2].substr(1, vect[2].size() - 2);
        double longitude = std::stod(vect[7]);
        double latitude = std::stod(vect[6]);

        Airport new_vertex(id, name, city, longitude, latitude);
        kVertices_.emplace(id, new_vertex);
      } catch (const std::invalid_argument& error) {
          continue;
      }
    }
  }
}

void Graph::read_routes(const std::string& routes_file_name) {
  std::ifstream route_file(routes_file_name);
  std::string line;

  // Open file and iterate through each line to fill airport hash table
  if (route_file.is_open()) {
    while (getline(route_file, line)) {

      // Convert line to stringstream object and grab each comma separated value
      std::stringstream ss(line);
      std::vector<std::string> vect;

      while(ss.good()) {
          std::string substr;
          getline(ss, substr, ','); 
          vect.push_back(substr);
      }

      // Try-catch statement essentially ignores invalid or poorly formatted entries from the data
      try {
        // Remove first and last characters from string since they are usuaully surrounded by quotes (eg. ""AYGA"")
        std::string origin_id = vect[2];
        std::string destination_id = vect[4];
        
        Airport origin = kVertices_.at(origin_id);
        Airport destination = kVertices_.at(destination_id);
        double distance = CalculateAirportDistance(origin, destination);

        Route new_edge(origin, destination, distance);
        kEdges_.push_back(new_edge);
      } catch (const std::out_of_range& error) {
        continue;
      }
    }
  }

  Airport champaign = kVertices_.at("CMI");
  Airport jfk = kVertices_.at("JFK");
  std::cout << champaign.get_longitude() << " " << champaign.get_latitude() << std::endl;
  std::cout << jfk.get_longitude() << " " << jfk.get_latitude() << std::endl;

  std::cout << CalculateAirportDistance(champaign, jfk) << std::endl;
}

double Graph::ToRad(double degree) const {
    return (degree * 3.1415926) / 180 ;
}

double Graph::CalculateAirportDistance(const Airport& origin, const Airport& destination) const {
    double lat1 = ToRad(origin.get_latitude());
    double lat2 = ToRad(destination.get_latitude());

    double delta_long = ToRad(destination.get_longitude() - origin.get_longitude());

    double a = (std::sin((lat2 - lat1) / 2) * std::sin((lat2 - lat1) / 2)) + 
               (std::cos(lat1) * std::cos(lat2)) *
               (std::sin((delta_long) / 2) * std::sin((delta_long) / 2));
    double c = 2 * std::atan2(std::sqrt(a), std::sqrt(1-a));

    return 6371 * c;
}

const   Airport& Graph :: get_airport(const std::string& airport_name) const { 
  // i : holds the address of the airport 
  // returns the address of the airport name loacations 
  // else : returns  end  ;
  auto i = kVertices_ . begin  ( ) ;  
  for (  i  =   kVertices_  .begin ( ) ; i != kVertices_  .end ( ) ; i ++ ) {
    if ( i -> first  == airport_name ) {
    //    Airport temp = Airport ( i .get_id ( ) , i .get_name ( ) , i .get_city ( ) , i . get_latitude ( ) ,i .get_altitude ( )  ) ; 
      break ;
    }
  }
  return i -> second ;
  
}
const std:: vector <Route >  Graph :: get_route( const std :: string & rout_origin ) const {
      std :: vector  <Route > temp ;
      auto i = kEdges_ .begin ( ) ; 
      for ( i = kEdges_ .begin ( ) ; i != kEdges_ . end ( ) ; i ++ ){
        if ( i  -> get_origin ( ) . get_id ( ) == rout_origin ) {
          temp . push_back ( *i ) ;
        }  
        
      }
      return temp   ; 
} 




size_t  Graph  :: find_nodes ( std :: vector < node * > graph_nodes , std :: string origin ) {
  for ( size_t e= 0 ;  e < graph_nodes. size ( ) ; e++ ) {
    if ( graph_nodes [ e ] -> get_current ( )  == origin ) {
      return e ;
    }
  }
}
// assumption  graph consists on the nodes that contains its origin name distance as vector and next destin as vector and visted as bool vector  
// set origin distance as the first distance of itself 
void Graph :: dijkstr_distance ( std :: vector < node *  > graph_nodes , std :: string origin ) {
  size_t   origin_node_index =  find_nodes ( graph_nodes , origin ) ; 
  
  
  std :: vector < double  > distance_temp  ;
  for ( size_t i = 0 ; i < graph_nodes  . size ( ) ; i ++ ) {
    
    shortest_length . push_back ( 1000000000 ) ;
  }
  shortest_length  [ origin_node_index ] = 0 ;
  long temp =  shortest_length [ 0 ]; 
  
  size_t e ;
  size_t temp_e ;
  node *  next_destination ;
  node*  current = graph_nodes [origin_node_index ] ; 
  do { 
    for (  e = 0 ; e < shortest_length . size ( ) ; e++ ) {
      if ( temp > shortest_length [ e ] ) {
        if ( graph_nodes [ e]   -> get_visited ( )  == false ) { 
          
          temp = shortest_length [ e ] ;
          temp_e = e ;
          
          
        }
      } 
    }
    next_destination = graph_nodes [ temp_e ] ;
    
    for ( e= 0 ; e < next_destination -> get_distance ( ) . size ( )   ; e++  ) {
      if ( next_destination -> get_next_nodes ( ) [ e ] -> get_visited ( ) == false ) {
        //   temp =  dijkstr_distance (  graph_nodes ,  origin  ,  next_destination -> destination  [e ] ) ;
        if ( shortest_length [ temp_e ] + next_destination  -> get_distance ( ) [e ] <  shortest_length[ e ]   ){
          shortest_length [e ]  = shortest_length [ temp_e] + next_destination -> get_distance ( ) [ e];
        }
      }
    }
    graph_nodes [ temp_e ] -> set_visited ( true  )  ;
  }while ( visited_check ( graph_nodes  )) ;

}
bool Graph :: visited_check ( std :: vector < node *  > graph_nodes  ) {
  for ( size_t i =0 ; i < graph_nodes . size( ) ; i++ ){ 
    if ( graph_nodes [ i] -> get_visited ( ) == false ){
      return false ; 
    }
  }
  return true ;
}

