#pragma once

#include "airport.h"

struct Route {
public:

  Route(const Airport& origin, const Airport& destination, double distance) : 
        kOrigin_(origin), kDestination_(destination), kDistance_(distance) {};

  /**
   * getter functions 
   */
  inline const Airport& get_origin() const { return kOrigin_; }

  inline const Airport& get_destination() const { return kDestination_; }

  inline double get_distance() const { return kDistance_; }

  
  /**
   * Puts key information of route into outstream object
   */
  friend std::ostream& operator<<(std::ostream& os, const Route& route) { 
    return os << "Origin: " << route.kOrigin_ << '\n' << "Destination: " << route.kDestination_; 
  }

  friend bool operator==(const Route& lhs, const Route& rhs) { 
    return (lhs.kOrigin_.get_id() == rhs.kOrigin_.get_id()) && 
           (lhs.kDestination_.get_id() == rhs.kDestination_.get_id()); 
  }


private:
  /**
   * @kOrigin_ : flight's origin airport
   * @kDestination_ : flight's destination airport
   * @kDistance_ : distance between airports in kilometers
   */
  const Airport kOrigin_;
  const Airport kDestination_;
  const double kDistance_;
};