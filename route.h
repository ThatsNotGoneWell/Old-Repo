#pragma once

#include "Airport.h"

struct Route {
public:

  Route(const Airport& origin, const Airport& destination, double distance) : 
        kOrigin_(origin), kDestination_(destination), kDistance_(distance) {};

  inline const Airport& get_origin() const { return kOrigin_; }

  inline const Airport& get_destination() const { return kDestination_; }

  friend std::ostream& operator<<(std::ostream& os, const Route& route) { 
    return os << "Origin: " << route.kOrigin_ << '\n' << "Destination: " << route.kDestination_; 
  }

private:
  const Airport kOrigin_;
  const Airport kDestination_;
  const double kDistance_;
};