#ifndef CRUISE_H
#define CRUISE_H

#include "../travel_package/TravelPackage.hpp"

class Cruise final : public TravelPackage {
    string shipName;
public:
  void book() override {
    // Implementation for booking a cruise
  }

  void generateItinerary() override {
    // Implementation for generating an itinerary for a cruise
  }
};

#endif
