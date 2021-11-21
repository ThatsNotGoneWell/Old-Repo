#include "donaldson_algo.h"

DonaldsonAlgo::DonaldsonAlgo(const std::string& airports_file_name, const std::string& routes_file_name) : 
kAirportRoutes_(airports_file_name,  routes_file_name) { }

std::vector<Airport> DonaldsonAlgo::FindLongestCycle() const {
  std::vector<Airport> longest_cycle;
  longest_cycle.push_back(kAirportRoutes_.get_airport("JFK"));

  return longest_cycle;
}
