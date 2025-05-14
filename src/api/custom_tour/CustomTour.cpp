#include "CustomTour.hpp"
#include "../../utils/input_utils.h"

#include <iostream>

using namespace std;

void CustomTour::book() {
  if (booked) {
    return;
  }

  price *= 1 - (generateSale() / 100);
  booked = true;
}

int CustomTour::generateSale() { return vip ? getSale() : 0; }

bool CustomTour::validate() const noexcept {
  return customActivities.get()->size() <= 5 && price > 1000;
}

void CustomTour::generateItinerary() {
  cout << "Generating itinerary..." << endl;

  while (true) {
    bool needNext;
    string name;

    parse_string("Enter name of activity: ", name);
    customActivities.get()->emplace_back(name);

    parse_bool("Do you want to add another activity? ", needNext);
    if (!needNext) {
      break;
    }
  }
}

ostream &operator<<(ostream &os, const CustomTour &tour) {
  os << "TravelPackage(" << tour.packageId << ", " << tour.price << "$, "
     << (tour.booked ? "booked" : "not booked") << ")";
  return os;
}

istream &operator>>(istream &is, CustomTour &tour) {
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
