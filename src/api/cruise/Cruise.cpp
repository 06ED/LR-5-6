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

void Cruise::book() {
    bool isLuxe;
    parse_bool("Do you want luxe cabin? ", isLuxe);

    cabinType = isLuxe ? CabinType::LUXE : CabinType::STANDARD;
    booked = true;
}

ostream &operator<<(ostream &os, const Cruise &cruise) {
    os << "Cruise(" << cruise.packageId << ", " << cruise.price << "$, "
            << (cruise.booked ? "Booked" : "Not booked") << ", "
            << (cruise.cabinType == CabinType::LUXE ? "Luxe" : "Standard") << ", Ports: [";

    for (int i = 0; i < cruise.ports->size(); i++) {
        if (i + 1 == cruise.ports->size()) {
            os << (*cruise.ports)[i] << "], ";
            break;
        }

        os << (*cruise.ports)[i] << ", ";
    }

    os << "Duration: " << cruise.ports->size() * 24 << " hours)" << endl;

    return os;
}

istream &operator>>(istream &is, Cruise &cruise) {
    int packageId;
    int price;
    bool isBooked;
    bool isLuxe;
    string shipName;
    int portsSize;

    parse_int("Enter package id: ", packageId);
    parse_int("Enter price: ", price);
    parse_bool("Is this package booked? ", isBooked);
    parse_bool("Is this package luxe? ", isLuxe);
    parse_string("Enter ship name: ", shipName);
    parse_int("Enter port size: ", portsSize);

    for (int i = 0; i < portsSize; i++) {
        string portName;
        parse_string("Enter port number " + std::to_string(i + 1) + ": ", portName);

        cruise.ports->push_back(portName);
    }

    cruise.setPrice(price);
    cruise.setPackageId(packageId);
    cruise.setIsBooked(isBooked);
    cruise.cabinType = isLuxe ? CabinType::LUXE : CabinType::STANDARD;
    cruise.shipName = shipName;
    return is;
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
