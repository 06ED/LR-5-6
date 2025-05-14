#include "MenuItem.hpp"

#include "../api/TourType.hpp"
#include "../api/adventure_tour/AdventureTour.hpp"
#include "../api/cruise/Cruise.hpp"
#include "../api/custom_tour/CustomTour.hpp"
#include "../api/travel_package/TravelPackage.hpp"

#include <iostream>
#include <map>
#include <vector>

void createCustomTour(std::map<TourType, std::vector<TravelPackage>> *tours) {
  CustomTour tour;
  std::cin >> tour;

  (*tours)[TourType::CUSTOM].push_back(tour);
}

void createAdventureTour(
    std::map<TourType, std::vector<TravelPackage>> *tours) {
  AdventureTour tour;
  std::cin >> tour;

  (*tours)[TourType::ADVENTURE].push_back(tour);
}

void createCruse(std::map<TourType, std::vector<TravelPackage>> *tours) {
  Cruise cruise;
  std::cin >> cruise;

  (*tours)[TourType::CRUISE].push_back(cruise);
}

void getAllTours(std::map<TourType, std::vector<TravelPackage>> *tours) {
  for (const auto &[type, typeTours] : *tours) {
    for (const TravelPackage &tour : typeTours) {
      cout << tour << endl;
    }
  }
}

std::vector<MenuItem> MenuItem::getMenu() {
  return {
      {"Create new custom tour", createCustomTour},
      {"Create new adventure tour", createAdventureTour},
      {"Create new cruise", createCruse},
      {"Get all tours to demonstrate polymorphysm", getAllTours},
  };
}
