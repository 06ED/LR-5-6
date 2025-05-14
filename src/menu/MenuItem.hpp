#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include "../api/TourType.hpp"
#include "../api/travel_package/TravelPackage.hpp"
#include <functional>
#include <map>
#include <string>
#include <vector>

typedef std::function<void(std::map<TourType, std::vector<TravelPackage>> *)>
    MenuCallback;

class MenuItem {
  std::string title;
  MenuCallback callback;

public:
  MenuItem(const std::string &title, const MenuCallback &callback)
      : title(title), callback(callback) {}

  std::string getTitle() const { return title; }

  MenuCallback getCallback() { return callback; }

  static std::vector<MenuItem> getMenu();
};

#endif
