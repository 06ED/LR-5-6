#ifndef DISCOUNT_SYSTEM_H
#define DISCOUNT_SYSTEM_H

class DiscountSystem {
    int sale;

protected:
    explicit DiscountSystem(const int sale = 20) : sale(sale) {
    }

    virtual int generateSale() = 0;

public:
    virtual ~DiscountSystem() = default;

    [[nodiscard]] int getSale() const { return sale; }
};

#endif
