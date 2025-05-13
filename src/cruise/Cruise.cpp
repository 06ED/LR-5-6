#include "Cruise.hpp"
#include "../utils/input_utils.h"
#include <memory>

void Cruise::generateItinerary() {
  cout << "Generating itinerary..." << endl;

  while (true) {
    bool needNext;
    string name;

    parse_string("Enter name of port: ", name);
    ports.get()->emplace_back(name);

    parse_bool("Do you want to add another port? ", needNext);
    if (!needNext) {
      break;
    }
  }
}

void Cruise::book() {
  bool isLuxe;
  parse_bool("Do you want luxe cabin? ", isLuxe);

  cabinType = isLuxe ? CabinType::LUXE : CabinType::STANDARD;
  booked = true;
}

ostream &operator<<(ostream &os, const Cruise &cruise) {
  os << "TravelPackage(" << cruise.packageId << ", " << cruise.price << "$, "
     << (cruise.booked ? "booked" : "not booked") << ", "
     << (cruise.cabinType == CabinType::LUXE ? "luxe" : "standard") << ")";

  os << "Ports:" << endl;
  for (const string &port : *cruise.ports.get()) {
    os << port << endl;
  }
  os << "Duration: " << cruise.ports->size() * 24 << " hours" << endl;

  return os;
}

istream &operator>>(istream &is, Cruise &cruise) {
  int packageId;
  int price;
  bool isBooked;
  bool isLuxe;
  string shipName;

  parse_int("Enter package id: ", packageId);
  parse_int("Enter price: ", price);
  parse_bool("Is this package booked? ", isBooked);
  parse_bool("Is this package luxe? ", isLuxe);
  parse_string("Enter ship name: ", shipName);

  cruise.setPrice(price);
  cruise.setPackageId(packageId);
  cruise.setIsBooked(isBooked);
  cruise.cabinType = isLuxe ? CabinType::LUXE : CabinType::STANDARD;
  cruise.shipName = shipName;
  return is;
}

Cruise Cruise::operator+(const Cruise &other) {
  vector<string> newPorts;
  newPorts.insert(newPorts.end(), ports.get()->begin(), ports.get()->end());
  newPorts.insert(newPorts.end(), other.ports->begin(), other.ports->end());

  return {packageId,
          price + other.price,
          booked && other.booked,
          shipName,
          newPorts,
          cabinType};
}
