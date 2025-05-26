#include "MenuItem.hpp"

#include "../api/TourType.hpp"
#include "../api/adventure_tour/AdventureTour.hpp"
#include "../api/cruise/Cruise.hpp"
#include "../api/custom_tour/CustomTour.hpp"
#include "../api/travel_package/TravelPackage.hpp"

#include <iostream>
#include <map>
#include <ranges>
#include <vector>

void createCustomTour(std::map<TourType, std::vector<unique_ptr<TravelPackage> > > *tours) {
    CustomTour tour;
    std::cin >> tour;

    (*tours)[TourType::CUSTOM].push_back(make_unique<CustomTour>(tour));
}

void createAdventureTour(
    std::map<TourType, std::vector<unique_ptr<TravelPackage> > > *tours) {
    AdventureTour tour;
    std::cin >> tour;

    (*tours)[TourType::ADVENTURE].push_back(make_unique<AdventureTour>(tour));
}

void createCruse(std::map<TourType, std::vector<unique_ptr<TravelPackage> > > *tours) {
    Cruise cruise;
    std::cin >> cruise;

    (*tours)[TourType::CRUISE].push_back(make_unique<Cruise>(cruise));
}

void getAllTours(std::map<TourType, std::vector<unique_ptr<TravelPackage> > > *tours) {
    for (const auto &tour: *tours | std::views::values | std::views::join) {
        if (const auto adventure = dynamic_cast<AdventureTour *>(tour.get())) {
            cout << *adventure;
        } else if (const auto cruise = dynamic_cast<Cruise *>(tour.get())) {
            cout << *cruise;
        } else if (const auto custom = dynamic_cast<CustomTour *>(tour.get())) {
            cout << *custom;
        } else {
            cout << *tour;
        }
    }
}

std::vector<MenuItem> MenuItem::getMenu() {
    return {
        {"Create new custom tour", createCustomTour},
        {"Create new adventure tour", createAdventureTour},
        {"Create new cruise", createCruse},
        {"Get all tours to demonstrate polymorphism", getAllTours},
    };
}
