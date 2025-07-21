#ifndef APPLIANCE_H
#define APPLIANCE_H

#include <string>

class Appliance {
protected:
    std::string id;

public:
    Appliance(const std::string& id);
    virtual ~Appliance(); // Virtual destructor for proper cleanup of derived types

    std::string getId() const;
    virtual double consumedElectricity() const = 0; // Pure virtual function
    virtual std::string toString() const = 0; // Pure virtual function to return a string representation
};

#endif // APPLIANCE_H
