#ifndef ADVENTURE_TOUR_HPP
#define ADVENTURE_TOUR_HPP

#include "../travel_package/TravelPackage.hpp"

using namespace std;

enum class ActivityType { TRACKING, DIVING };

class AdventureTour : public TravelPackage {
  ActivityType activityType;
  int difficultyLevel;

public:
  void setActivityType(ActivityType activityType) {
    this->activityType = activityType;
  }

  void setDifficultyLevel(int difficultyLevel) {
    this->difficultyLevel = difficultyLevel;
  }

  ActivityType getActivityType() const { return activityType; }

  int getDifficultyLevel() const { return difficultyLevel; }

  void book() override {
    setIsBooked(true);
  }

  bool validate() const {
    return difficultyLevel <= 3 && TravelPackage::validate();
  }
};

#endif
