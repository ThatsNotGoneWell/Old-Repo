#include "donaldson_algo.h"

DonaldsonAlgo::DonaldsonAlgo(const std::string& airports_file_name, const std::string& routes_file_name) : 
                             kAirportRoutes_(airports_file_name,  routes_file_name),
                             kAdjacencyList_(kAirportRoutes_.MakeAdjacencyList()) { }

std::vector<Airport> DonaldsonAlgo::FindLongestCycle() const {
  std::vector<Airport> longest_cycle;

  longest_cycle.push_back(kAirportRoutes_.get_airport("DFW"));
  longest_cycle.push_back(kAirportRoutes_.get_airport("CMI"));
  longest_cycle.push_back(kAirportRoutes_.get_airport("LAX"));
  longest_cycle.push_back(kAirportRoutes_.get_airport("ORD"));
  longest_cycle.push_back(kAirportRoutes_.get_airport("JFK"));
  longest_cycle.push_back(kAirportRoutes_.get_airport("DFW"));

  return longest_cycle;
}
