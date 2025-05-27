#include <iostream>

#include "../../utils/input_utils.h"
#include "TravelPackage.hpp"

using namespace std;

ostream &operator<<(ostream &os, const TravelPackage &package) {
    os << package.output();
    return os;
}

istream &operator>>(istream &is, TravelPackage &package) {
    package.input();
    package.generateItinerary();

    return is;
}

string TravelPackage::output() const {
    return "TravelPackage(" + std::to_string(packageId) + ", " + std::to_string(price) + "$, " + (
               booked ? "booked" : "not booked") + ")";
}

void TravelPackage::input() {
    int packageId;
    int price;
    bool isBooked;

    parse_int("Enter package id: ", packageId);
    parse_int("Enter price: ", price);
    parse_bool("Is this package booked? ", isBooked);

    setPrice(price);
    setPackageId(packageId);
    setIsBooked(isBooked);
}
