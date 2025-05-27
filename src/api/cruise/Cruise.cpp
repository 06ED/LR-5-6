#include "Cruise.hpp"
#include "../../utils/input_utils.h"

#include <memory>

void Cruise::generateItinerary() {
    cout << "Generating itinerary..." << endl;

    while (true) {
        bool needNext;
        string name;

        parse_string("Enter name of port: ", name);
        ports->emplace_back(name);

        parse_bool("Do you want to add another port? ", needNext);
        if (!needNext) {
            break;
        }
    }
}

string Cruise::output() const {
    string result;
    result += "Cruise(" + std::to_string(packageId) + ", " + std::to_string(price) + "$, "
            + (booked ? "Booked" : "Not booked") + ", "
            + (cabinType == CabinType::LUXE ? "Luxe" : "Standard") + ", Ports: [";

    for (int i = 0; i < ports->size(); i++) {
        if (i + 1 == ports->size()) {
            result += (*ports)[i] + "], ";
            break;
        }

        result += (*ports)[i] + ", ";
    }

    result += "Duration: " + std::to_string(ports->size() * 24) + " hours)";

    return result;
}

void Cruise::input() {
    TravelPackage::input();

    bool isLuxe;
    string shipName;

    parse_bool("Is this package luxe? ", isLuxe);
    parse_string("Enter ship name: ", shipName);

    cabinType = isLuxe ? CabinType::LUXE : CabinType::STANDARD;
    this->shipName = shipName;
}

void Cruise::book() {
    bool isLuxe;
    parse_bool("Do you want luxe cabin? ", isLuxe);

    cabinType = isLuxe ? CabinType::LUXE : CabinType::STANDARD;
    booked = true;
}

Cruise Cruise::operator+(const Cruise &other) {
    vector<string> newPorts;
    newPorts.insert(newPorts.end(), ports->begin(), ports->end());
    newPorts.insert(newPorts.end(), other.ports->begin(), other.ports->end());

    return {
        packageId,
        price + other.price,
        booked && other.booked,
        shipName,
        newPorts,
        cabinType
    };
}
