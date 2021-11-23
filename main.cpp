#include "airport.h"
#include "route.h"
#include "graph.h"
#include "donaldson_algo.h"

int main() {
    DonaldsonAlgo algo("data/airports.dat.txt", "data/routes.dat.txt");
    std::vector<Airport> longest_cycle = algo.FindLongestCycle();

    for (const auto& airport : longest_cycle) {
        std::cout << airport << std::endl;
    }

    return 1;
}