#ifndef REFRIGERATOR_H
#define REFRIGERATOR_H

#include "Appliance.h"
#include <string>

class Refrigerator : public Appliance {
private:
    std::string electricityUsageClass;
    bool hasFreezer;

public:
    Refrigerator(const std::string& id, const std::string& usageClass, bool freezer);

    virtual double consumedElectricity() const override;
    virtual std::string toString() const override;
};


#endif // REFRIGERATOR_H