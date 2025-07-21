#include "Service.h"
#include <fstream>
#include <algorithm>

Service::Service() {
}

Service::~Service() {
    // Assuming dynamic allocation of appliances, they need to be deleted
    for (auto appliance : appliances) {
        delete appliance;
    }
}

void Service::addAppliance(Appliance* appliance) {
    appliances.push_back(appliance);
}

std::vector<Appliance*> Service::getAllAppliances() const {
    return appliances;
}

std::vector<Appliance*> Service::getAppliancesWithConsumptionLessThan(double maxElectricity) const {
    std::vector<Appliance*> filteredAppliances;
    for (auto* appliance : appliances) {
        if (appliance->consumedElectricity() < maxElectricity) {
            filteredAppliances.push_back(appliance);
        }
    }
    return filteredAppliances;
}

void Service::writeFileWithAppliancesWithConsumptionLessThan(double maxElectricity, const std::string& filename) const {
    std::vector<Appliance*> filteredAppliances = getAppliancesWithConsumptionLessThan(maxElectricity);
    std::sort(filteredAppliances.begin(), filteredAppliances.end(),
        [](const Appliance* a, const Appliance* b) -> bool {
            return a->getId() < b->getId();
        });

    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const auto& appliance : filteredAppliances) {
            outFile << appliance->toString() << std::endl;
        }
        outFile.close();
    }
    else {
        throw std::runtime_error("Error opening file: " + filename);
    }
}
std::vector<Appliance*> Service::getInefficientAppliances() const {
    std::vector<Appliance*> inefficient;
    for (auto* appliance : appliances) {
        if (appliance->consumedElectricity() > 100) {
            inefficient.push_back(appliance);
        }
    }
    return inefficient;
}

