#include "Refrigerator.h"
#include <sstream>

Refrigerator::Refrigerator(const std::string& newId, const std::string& usageClass, bool freezer)
    : Appliance(newId), electricityUsageClass(usageClass), hasFreezer(freezer) {}

double Refrigerator::consumedElectricity() const {
    double baseRate = 30.0;
    double multiplier = (electricityUsageClass == "A++") ? 2 : 3;
    return (baseRate * multiplier) + (hasFreezer ? 20 : 0);
}

std::string Refrigerator::toString() const {
    std::ostringstream stream;
    stream << "Refrigerator ID: " << getId() << ", Class: " << electricityUsageClass
        << ", Has Freezer: " << (hasFreezer ? "Yes" : "No")
        << ", Consumed Electricity: " << consumedElectricity() << " KW";
    return stream.str();
}
