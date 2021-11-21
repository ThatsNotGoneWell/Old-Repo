#pragma once

#include <string>
#include <iostream>

struct Airport {

public:
  Airport(const std::string& id,  const std::string& name,  const std::string& city, double longitude, double latitude) 
          : kID_(id), kName_(name), kCity_(city), kLongitude_(longitude), kLatitude_(latitude) {};

  /**
   * getter functions 
   */
  inline const std::string& get_id() const { return kID_; }

  inline const std::string& get_name() const { return kName_; }

  inline const std::string& get_city() const { return kCity_; }

  inline double get_latitude() const { return kLatitude_; }

  inline double get_longitude() const { return kLongitude_; }

  /**
   * Puts key information of airport into outstream object
   */
  friend std::ostream& operator<<(std::ostream& os, const Airport& airport) { 
    return os << airport.kID_ << ", " << airport.kName_ << ", " << airport.kCity_; 
  }

private:

  /**
   * @kLatitude_ : latitude of airport
   * @kLongitude_ : longitude of airport
   * @kCity_ : name of city airport is in
   * @kName_ : name of airport
   * @kID_ : 3-letter IATA code
   */
  const std::string kID_;
  const std::string kName_;
  const std::string kCity_;
  const double kLongitude_;
  const double kLatitude_;
};