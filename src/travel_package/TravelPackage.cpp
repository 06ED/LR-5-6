#include "TravelPackage.hpp"

using namespace std;

ostream &operator<<(ostream &os, const TravelPackage &package) {
  os << "TravelPackage(" << package.packageId << ", " << package.price << "$, "
     << (package.booked ? "booked" : "not booked") << ")";
  return os;
}


