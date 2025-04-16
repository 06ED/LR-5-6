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

  TravelPackage(int packageId, int price, bool booked)
      : packageId(packageId), price(price), booked(booked) {}

  virtual ~TravelPackage() {}

  virtual void book();

  virtual void generateItinerary();

  bool validate() const { return price > 0; }

  bool operator==(const TravelPackage &other) const {
    return packageId == other.packageId;
  }

  friend ostream &operator<<(ostream &os, const TravelPackage &package);

  friend istream &operator>>(std::istream &is, TravelPackage &package);
};

#endif
