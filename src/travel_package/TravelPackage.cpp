#include <iostream>

#include "../utils/input_utils.h"
#include "TravelPackage.hpp"

using namespace std;

ostream &operator<<(ostream &os, const TravelPackage &package) {
  os << "TravelPackage(" << package.packageId << ", " << package.price << "$, "
     << (package.booked ? "booked" : "not booked") << ")";
  return os;
}

istream &operator>>(istream &is, TravelPackage &package) {
  int packageId;
  int price;
  bool isBooked;

  parse_int("Enter package id: ", packageId);
  parse_int("Enter price: ", price);
  parse_bool("Is this package booked?", isBooked);

  package.setPrice(price);
  package.setPackageId(packageId);
  package.setIsBooked(isBooked);

  return is;
}
