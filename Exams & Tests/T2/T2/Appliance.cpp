#include "Appliance.h"

Appliance::Appliance(const std::string& newId) : id(newId) {}

Appliance::~Appliance() {
    // Virtual destructor to allow for proper cleanup of derived types
}

std::string Appliance::getId() const {
    return id;
}

