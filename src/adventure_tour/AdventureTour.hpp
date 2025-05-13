#ifndef ADVENTURE_TOUR_HPP
#define ADVENTURE_TOUR_HPP

#include "../travel_package/TravelPackage.hpp"
#include "itinerary/ItinerarySegment.hpp"
#include <memory>
#include <vector>

using namespace std;

enum class ActivityType { TRACKING, DIVING };

class AdventureTour : public TravelPackage {
  ActivityType activityType;
  unique_ptr<vector<ItinerarySegment>> itinerary;
  bool safetyBriefing;
  int difficultyLevel;

public:
  AdventureTour(ActivityType activityType = ActivityType::DIVING,
                bool safetyBriefing = false, int difficultyLevel = 2)
      : activityType(activityType), difficultyLevel(difficultyLevel),
        safetyBriefing(safetyBriefing) {}

  void setActivityType(ActivityType &activityType) {
    this->activityType = activityType;
  }

  void setDifficultyLevel(int difficultyLevel) {
    this->difficultyLevel = difficultyLevel;
  }

  ActivityType getActivityType() const { return activityType; }

  int getDifficultyLevel() const { return difficultyLevel; }

  vector<ItinerarySegment> *getItinerary() const { return itinerary.get(); }

  void book() override { setIsBooked(true); }

  bool validate() const {
    return difficultyLevel <= 3 && TravelPackage::validate();
  }

  void addSafetyBriefing() { safetyBriefing = true; }

  void operator+=(ItinerarySegment segment) {
    itinerary.get()->push_back(segment);
  }

  void generateItinerary() override;
};

#endif
