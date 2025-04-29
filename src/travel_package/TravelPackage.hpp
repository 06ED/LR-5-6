#ifndef TRAVEL_PACKAGE_H
#define TRAVEL_PACKAGE_H

#include <istream>
#include <ostream>

using namespace std;

class TravelPackage {
protected:
  int packageId;
  int price;
  bool booked;

public:
  void setPackageId(int packageId) { this->packageId = packageId; }

  void setPrice(int price) { this->price = price; }

  void setIsBooked(bool booked) { this->booked = booked; }

  int getPackageId() const { return packageId; }

  int getPrice() const { return price; }

  bool isBooked() const { return booked; }

public:
  TravelPackage(int packageId = 0)
      : packageId(packageId), price(0), booked(false) {}

  TravelPackage(const int packageId, const int price, const bool booked)
      : packageId(packageId), price(price), booked(booked) {}

  virtual ~TravelPackage() {};

  virtual void book() = 0;

  virtual void generateItinerary() = 0;

  bool validate() const { return price > 0; }

  bool operator==(const TravelPackage &other) const {
    return packageId == other.packageId;
  }

  friend ostream &operator<<(ostream &os, const TravelPackage &package);

  friend istream &operator>>(istream &is, TravelPackage &package);
};

#endif
