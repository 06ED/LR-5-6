#include "AdventureTour.hpp"
#include "../utils/input_utils.h"
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
    itinerary.get()->emplace_back(name, description);

    parse_bool("Do you want to add another itinerary? ", needNext);
    if (!needNext) {
      break;
    }
  }
}
