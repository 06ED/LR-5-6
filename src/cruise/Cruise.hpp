#ifndef CRUISE_H
#define CRUISE_H

#include "../travel_package/TravelPackage.hpp"
#include <memory>
#include <string>
#include <vector>

enum class CabinType { STANDARD, LUXE };

class Cruise final : public TravelPackage {
  string shipName;
  unique_ptr<vector<string>> ports;
  CabinType cabinType;

public:
  Cruise(const string &shipName) : shipName(shipName) {}
  Cruise(Cruise &other)
      : shipName(other.shipName),
        ports(make_unique<vector<string>>(*other.ports.get())),
        cabinType(other.cabinType), TravelPackage(other) {}
  Cruise(const int packageId, const int price, const bool booked,
         const string &shipName, const vector<string> &ports,
         CabinType cabinType = CabinType::STANDARD)
      : shipName(shipName), ports(make_unique<vector<string>>(ports)),
        cabinType(cabinType), TravelPackage(packageId, price, booked) {}

  void book() override;

  void generateItinerary() override;

  bool validate() const { return ports.get()->size() > 3; }

  void upgradeCabin(CabinType cabinType = CabinType::LUXE) {
    this->cabinType = cabinType;
  }

  Cruise operator+(const Cruise &other);

  friend ostream &operator<<(ostream &os, const Cruise &cruise);

  friend istream &operator>>(istream &is, Cruise &cruise);
};

#endif
