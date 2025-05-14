#include "AdventureTour.hpp"
#include "../../utils/input_utils.h"

#include <iostream>

using namespace std;

void AdventureTour::generateItinerary() {
  cout << "Generating itinerary..." << endl;

  while (true) {
    bool needNext;
    string name;
    string description;

    parse_string("Enter name of itinerary: ", name);
    parse_string("Enter description of itinerary: ", description);
    itinerary.get()->emplace_back(name, description);

    parse_bool("Do you want to add another itinerary? ", needNext);
    if (!needNext) {
      break;
    }
  }
}

ostream &operator<<(ostream &os, const AdventureTour &tour) {
  os << "TravelPackage(" << tour.packageId << ", " << tour.price << "$, "
     << (tour.booked ? "booked" : "not booked") << ")";
  return os;
}

istream &operator>>(istream &is, AdventureTour &tour) {
  int packageId;
  int price;
  bool isBooked;

  parse_int("Enter package id: ", packageId);
  parse_int("Enter price: ", price);
  parse_bool("Is this package booked?", isBooked);

  tour.setPrice(price);
  tour.setPackageId(packageId);
  tour.setIsBooked(isBooked);

  return is;
}
