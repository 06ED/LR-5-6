#ifndef DISCOUNT_SYSTEM_H
#define DISCOUNT_SYSTEM_H

class DiscountSystem {
  int sale;

protected:
  DiscountSystem(int sale = 20) : sale(sale) {}

  virtual int generateSale() = 0;

public:
  int getSale() const { return sale; }
};

#endif
