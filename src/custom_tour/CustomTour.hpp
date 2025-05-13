#ifndef CUSTOM_TOUR_H
#define CUSTOM_TOUR_H

#include "../discount_system/DiscountSystem.hpp"
#include "../travel_package/TravelPackage.hpp"
#include <memory>
#include <vector>

class CustomTour : public TravelPackage, public DiscountSystem {
  bool isVip;
  double price;
  unique_ptr<vector<string>> customActivities;

public:
  void book() override;

  bool validate() const { return customActivities.get()->size() <= 5; }
};

#endif
