#include "api/TourType.hpp"
#include "api/travel_package/TravelPackage.hpp"
#include "menu/MenuItem.hpp"
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  map<TourType, vector<TravelPackage>> tours;

  while (true) {
    int index = 1;
    int selected;

    for (const auto item : MenuItem::getMenu()) {
      std::cout << index++ << ": " << item.getTitle() << std::endl;
    }

    cout << "Enter choice: " << endl;
    cin >> selected;
    if (MenuItem::getMenu().size() > selected) {
      cout << "Incorrect choice" << endl;
      continue;
    }

    MenuItem::getMenu()[selected - 1].getCallback()(&tours);
  }

  return 0;
}
