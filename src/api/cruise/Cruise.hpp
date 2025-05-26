#ifndef CRUISE_H
#define CRUISE_H

#include "../travel_package/TravelPackage.hpp"

#include <memory>
#include <string>
#include <utility>
#include <vector>

enum class CabinType { STANDARD, LUXE };

class Cruise final : public TravelPackage {
    string shipName;
    unique_ptr<vector<string> > ports;
    CabinType cabinType;

public:
    explicit Cruise(string shipName = "Titanic")
        : shipName(std::move(shipName)),
          ports(make_unique<vector<string> >()),
          cabinType(CabinType::STANDARD) {
    }

    Cruise(const Cruise &other)
        : TravelPackage(other),
          shipName(other.shipName),
          ports(make_unique<vector<string> >(*other.ports)), cabinType(other.cabinType) {
    }

    Cruise(
        const int packageId,
        const int price,
        const bool booked,
        string shipName,
        const vector<string> &ports,
        const CabinType cabinType = CabinType::STANDARD)
        : TravelPackage(packageId, price, booked),
          shipName(std::move(shipName)),
          ports(make_unique<vector<string> >(ports)),
          cabinType(cabinType) {
    }

    void book() override;

    void generateItinerary() override;

    [[nodiscard]] bool validate() const noexcept override { return ports->size() > 3 && TravelPackage::validate(); }

    void upgradeCabin(const CabinType cabinType = CabinType::LUXE) { this->cabinType = cabinType; }

    Cruise operator+(const Cruise &other);

    friend ostream &operator<<(ostream &os, const Cruise &cruise);

    friend istream &operator>>(istream &is, Cruise &cruise);
};

#endif
