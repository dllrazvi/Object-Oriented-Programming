#pragma once
#include <string>

class Engine {
protected:
    int price = 3000;
public:
    virtual double computePrice() const = 0;
    virtual std::string toString() const = 0;
    virtual ~Engine() {}
};
