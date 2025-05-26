#ifndef ITINERARY_SEGMENT_HPP
#define ITINERARY_SEGMENT_HPP

#include <string>
#include <utility>

class ItinerarySegment final {
    std::string name;
    std::string description;

public:
    ItinerarySegment(std::string name, std::string description)
        : name(std::move(name)), description(std::move(description)) {
    }

    [[nodiscard]] std::string getName() const { return name; }

    [[nodiscard]] std::string getDescription() const { return description; }
};

#endif // ITINERARY_SEGMENT_HPP
