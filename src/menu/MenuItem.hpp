#ifndef MENU_ITEM_H
#define MENU_ITEM_H

#include "../api/TourType.hpp"
#include "../api/travel_package/TravelPackage.hpp"
#include <functional>
#include <map>
#include <memory>
#include <string>
#include <utility>
#include <vector>

typedef std::function<void(std::map<TourType, std::vector<unique_ptr<TravelPackage> > > *)> MenuCallback;

class MenuItem {
    std::string title;
    MenuCallback callback;

public:
    MenuItem(std::string title, MenuCallback callback)
        : title(std::move(title)), callback(std::move(callback)) {
    }

    [[nodiscard]] std::string getTitle() const { return title; }

    MenuCallback getCallback() { return callback; }

    static std::vector<MenuItem> getMenu();
};

#endif
