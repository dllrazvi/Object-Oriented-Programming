#ifndef DISHWASHER_H
#define DISHWASHER_H

#include "Appliance.h"
#include <string>

class DishWasher : public Appliance {
private:
    double consumedElectricityForOneHour;

public:
    DishWasher(const std::string& id, double electricityForOneHour);

    virtual double consumedElectricity() const override;
    virtual std::string toString() const override;

};

#endif // DISHWASHER_H
