#include "AdventureTour.hpp"
#include "../../utils/input_utils.h"

#include <iostream>

using namespace std;

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

ostream &operator<<(ostream &os, const AdventureTour &tour) {
    os << "AdventureTour(" << tour.packageId << ", " << tour.price << "$, "
            << (tour.booked ? "Booked" : "Not booked")
            << ", Activity: " << (tour.activityType == ActivityType::DIVING
                                      ? "Diving"
                                      : "Tracking")
            << ", Difficulty: " << tour.difficultyLevel
            << ", Safety Briefing: " << (tour.safetyBriefing ? "Yes" : "No")
            << ")";
    return os;
}

istream &operator>>(istream &is, AdventureTour &tour) {
    int packageId;
    int price;
    bool isBooked;
    bool isDiving;
    int difficulty;
    bool safetyBriefing;

    parse_int("Enter package id: ", packageId);
    parse_int("Enter price: ", price);
    parse_bool("Is this package booked? ", isBooked);
    parse_bool("Is is diving activity? ", isDiving);
    parse_int("Enter difficulty (1-5): ", difficulty);
    parse_bool("Do you need safety briefing? ", safetyBriefing);

    tour.setPrice(price);
    tour.setPackageId(packageId);
    tour.setIsBooked(isBooked);
    tour.setDifficultyLevel(difficulty);
    tour.setActivityType(isDiving ? ActivityType::DIVING : ActivityType::TRACKING);
    if (safetyBriefing) {
        tour.addSafetyBriefing();
    }

    return is;
}
