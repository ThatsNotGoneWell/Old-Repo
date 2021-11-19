#pragma once

#include <string>
#include <iostream>

struct Airport {

public:
  Airport(const std::string& id,  const std::string& name,  const std::string& city, double longitude, double latitude) 
          : kID_(id), kName_(name), kCity_(city), kLongitude_(longitude), kLatitude_(latitude) {};

  inline const std::string& get_id() const { return kID_; }

  inline const std::string& get_name() const { return kName_; }

  inline const std::string& get_city() const { return kCity_; }

  inline double get_latitude() const { return kLatitude_; }

  inline double get_longitude() const { return kLongitude_; }

  friend std::ostream& operator<<(std::ostream& os, const Airport& airport) { 
    return os << airport.kID_ << ", " << airport.kName_ << ", " << airport.kCity_; 
  }

private:
  const std::string kID_;
  const std::string kName_;
  const std::string kCity_;
  const double kLongitude_;
  const double kLatitude_;
};