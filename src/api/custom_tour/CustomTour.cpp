#include "CustomTour.hpp"
#include "../../utils/input_utils.h"

#include <iostream>

using namespace std;

void CustomTour::book() {
    if (booked) {
        return;
    }

    price *= 1 - generateSale() / 100;
    booked = true;
}

int CustomTour::generateSale() { return vip ? getSale() : 0; }

bool CustomTour::validate() const noexcept {
    return customActivities->size() <= 5 && price > 1000 && TravelPackage::validate();
}

string CustomTour::output() const {
    return "CustomTour("
           + std::to_string(packageId) + ", "
           + std::to_string(price) + "$, "
           + (booked ? "Booked" : "Not booked") + ", "
           + (vip ? "Vip" : "Default")
           + (hasGuide ? ", With guide" : "")
           + ")";
}

void CustomTour::input() {
    TravelPackage::input();

    bool isVip;
    parse_bool("Is this package vip? ", isVip);

    vip = isVip;
}


void CustomTour::generateItinerary() {
    cout << "Generating itinerary..." << endl;

    while (true) {
        bool needNext;
        string name;

        parse_string("Enter name of activity: ", name);
        customActivities->emplace_back(name);

        parse_bool("Do you want to add another activity? ", needNext);
        if (!needNext) {
            break;
        }
    }
}
