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
    unique_ptr<vector<ItinerarySegment> > itinerary;
    bool safetyBriefing;
    int difficultyLevel;

public:
    explicit AdventureTour(
        const ActivityType activityType = ActivityType::DIVING,
        const bool safetyBriefing = false,
        const int difficultyLevel = 2
    ): activityType(activityType),
       itinerary(make_unique<vector<ItinerarySegment> >()),
       safetyBriefing(safetyBriefing),
       difficultyLevel(difficultyLevel) {
    }

    AdventureTour(const AdventureTour &other)
        : TravelPackage(other),
          activityType(other.activityType),
          itinerary(make_unique<vector<ItinerarySegment> >(*other.itinerary)),
          safetyBriefing(other.safetyBriefing), difficultyLevel(other.difficultyLevel) {
    }

    void setActivityType(const ActivityType &activityType) { this->activityType = activityType; }

    void setDifficultyLevel(const int difficultyLevel) { this->difficultyLevel = difficultyLevel; }

    [[nodiscard]] ActivityType getActivityType() const { return activityType; }

    [[nodiscard]] int getDifficultyLevel() const { return difficultyLevel; }

    [[nodiscard]] vector<ItinerarySegment> &getItinerary() const { return *itinerary; }

    void book() override { setIsBooked(true); }

    [[nodiscard]] bool validate() const noexcept override { return difficultyLevel <= 3 && TravelPackage::validate(); }

    [[nodiscard]] string output() const override;

    void input() override;

    void addSafetyBriefing() { safetyBriefing = true; }

    void operator+=(const ItinerarySegment &segment) const { itinerary->push_back(segment); }

    void generateItinerary() override;
};

#endif
