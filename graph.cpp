

#include "graph.h"
#include "airport.h"
#include "route.h"
#include "node.h" 
Graph::Graph(const std::string& airports_file_name, const std::string& routes_file_name) {
  read_airports(airports_file_name);
  read_routes(routes_file_name); 
  
  for ( auto  i = kVertices_ . begin ( ) ; i !=   kVertices_. end ( ) ; i++  ){ 
    node* temp = new node ( ) ;
    temp -> set_current ( i -> first  ) ;
    node_holder .push_back ( temp ) ; 
  }
   create_nodes (  ) ;
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
               (std::cos(lat1) * std::cos(lat2)) +
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

const node * Graph :: create_nodes  (   )  {
  for ( size_t i = 0 ; i < node_holder .size ( )  ; i++ ) { 
  
    std :: string temp =   node_holder [ i ] -> get_current ( )  ;
     for ( size_t j = 0 ; j < get_route ( temp  ) . size ( ) ; j++   ){ 
      std :: string destin = get_route ( temp ) [ j ] . get_destination ( ) . get_id ( ) ;
       
       for ( size_t a = 0 ; a < node_holder .size ( )  ; a++  ) {
         if ( node_holder [a ] -> get_current ( ) == destin  ) {
           node_holder [ i ] -> get_next_nodes ( ) . push_back ( node_holder [ a ] ) ;
           Airport a_ = get_airport (node_holder[ a ] -> get_current ( )  );
           Airport b_ = get_airport (node_holder [ i ] -> get_current ( ) );
            node_holder [i ] ->get_distance( )  . push_back (  CalculateAirportDistance ( a_ , b_ ) ) ;
            std :: cout << CalculateAirportDistance ( a_ , b_ ) << std :: endl   ; 
         }
         
           
        
       }
      }
   } 
}



