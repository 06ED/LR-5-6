#ifndef ITINERARY_SEGMENT_HPP
#define ITINERARY_SEGMENT_HPP

#include <string>

using namespace std;

class ItinerarySegment final {
  string name;
  string description;

public:
  ItinerarySegment(const string &name, const string &description)
      : name(name), description(description) {}

  string getName() const { return name; }
  string getDescription() const { return description; }
};

#endif
