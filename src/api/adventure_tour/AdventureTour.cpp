#include "AdventureTour.hpp"
#include "../../utils/input_utils.h"

#include <iostream>

using namespace std;

string AdventureTour::output() const {
    return "AdventureTour(" + std::to_string(packageId) + ", " + std::to_string(price) + "$, "
           + (booked ? "Booked" : "Not booked")
           + ", Activity: " + (activityType == ActivityType::DIVING
                                   ? "Diving"
                                   : "Tracking")
           + ", Difficulty: " + std::to_string(difficultyLevel)
           + ", Safety Briefing: " + (safetyBriefing ? "Yes" : "No")
           + ")";
}

void AdventureTour::input() {
    TravelPackage::input();

    bool isDiving;
    int difficulty;
    bool safetyBriefing;

    parse_bool("Is is diving activity? ", isDiving);
    parse_int("Enter difficulty (1-5): ", difficulty);
    parse_bool("Do you need safety briefing? ", safetyBriefing);

    setDifficultyLevel(difficulty);
    setActivityType(isDiving ? ActivityType::DIVING : ActivityType::TRACKING);
    if (safetyBriefing) {
        addSafetyBriefing();
    }
}

void AdventureTour::generateItinerary() {
    cout << "Generating itinerary..." << endl;

    while (true) {
        bool needNext;
        string name;
        string description;

        parse_string("Enter name of itinerary: ", name);
        parse_string("Enter description of itinerary: ", description);
        itinerary->emplace_back(name, description);

        parse_bool("Do you want to add another itinerary? ", needNext);
        if (!needNext) {
            break;
        }
    }
}
