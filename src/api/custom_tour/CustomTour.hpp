#ifndef CUSTOM_TOUR_H
#define CUSTOM_TOUR_H

#include "../discount_system/DiscountSystem.hpp"
#include "../travel_package/TravelPackage.hpp"

#include <memory>
#include <vector>

class CustomTour : public TravelPackage, public DiscountSystem {
    bool vip;
    bool hasGuide;
    unique_ptr<vector<string> > customActivities;

public:
    explicit CustomTour(const int packageId = 0)
        : TravelPackage(packageId), vip(false), hasGuide(false),
          customActivities(make_unique<vector<string> >()) {
    }

    CustomTour(
        const int packageId,
        const int price,
        const bool booked,
        const int sale,
        const vector<string> &customActivities,
        const bool vip,
        const bool hasGuide
    ): TravelPackage(packageId, price, booked),
       DiscountSystem(sale),
       vip(vip),
       hasGuide(hasGuide),
       customActivities(make_unique<vector<string> >(customActivities)) {
    }

    CustomTour(const CustomTour &other)
        : TravelPackage(other),
          DiscountSystem(other),
          vip(other.vip),
          hasGuide(other.hasGuide),
          customActivities(make_unique<vector<string> >(*other.customActivities)) {
    }

    void book() override;

    int generateSale() override;

    void generateItinerary() override;

    [[nodiscard]] bool validate() const noexcept override;

    void addPersonalGuide() { hasGuide = true; }

    [[nodiscard]] bool isVip() const { return vip; }

    friend ostream &operator<<(ostream &os, const CustomTour &tour);

    friend istream &operator>>(istream &is, CustomTour &tour);
};

#endif
