#ifndef SERVICE_H
#define SERVICE_H

#include "Appliance.h"
#include <vector>
#include <string>

class Service {
private:
    std::vector<Appliance*> appliances;

public:
    Service(); 
    ~Service();

    void addAppliance(Appliance* appliance);
    std::vector<Appliance*> getAllAppliances() const;
    std::vector<Appliance*> getAppliancesWithConsumptionLessThan(double maxElectricity) const;
    void writeFileWithAppliancesWithConsumptionLessThan(double maxElectricity, const std::string& filename) const;
    std::vector<Appliance*> getInefficientAppliances() const;

};

#endif // SERVICE_H
