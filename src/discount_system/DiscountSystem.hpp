#ifndef DISCOUNT_SYSTEM_H
#define DISCOUNT_SYSTEM_H

class DiscountSystem {
  int sale;

protected:
  DiscountSystem(int sale = 20) : sale(sale) {}

  virtual int generate_sale() = 0;

public:
  int get_sale() const { return sale; }
};

#endif
