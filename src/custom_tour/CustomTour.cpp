#include "CustomTour.hpp"

void CustomTour::book() { price = price * ((double)generate_sale() / 100); }
