#ifndef TRAVEL_PACKAGE_H
#define TRAVEL_PACKAGE_H

#include <ostream>

using namespace std;

class TravelPackage {
protected:
    int packageId;
    int price;
    bool booked;

public:
    explicit TravelPackage(const int packageId = 0)
        : packageId(packageId), price(0), booked(false) {
    }

    TravelPackage(const TravelPackage &other) = default;

    TravelPackage(const int packageId, const int price, const bool booked)
        : packageId(packageId), price(price), booked(booked) {
    }

    virtual ~TravelPackage() = default;

    void setPackageId(const int packageId) { this->packageId = packageId; }

    void setPrice(const int price) { this->price = price; }

    void setIsBooked(const bool booked) { this->booked = booked; }

    [[nodiscard]] int getPackageId() const { return packageId; }

    [[nodiscard]] int getPrice() const { return price; }

    [[nodiscard]] bool isBooked() const { return booked; }

    virtual void book() = 0;

    virtual void generateItinerary() = 0;

    [[nodiscard]] virtual string output() const;

    virtual void input();

    [[nodiscard]] virtual bool validate() const noexcept { return price > 0; }

    bool operator==(const TravelPackage &other) const {
        return packageId == other.packageId;
    }

    friend ostream &operator<<(ostream &os, const TravelPackage &package);

    friend istream &operator>>(istream &is, TravelPackage &package);
};

#endif // TRAVEL_PACKAGE_H
