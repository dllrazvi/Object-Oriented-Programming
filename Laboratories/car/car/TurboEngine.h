#pragma once
#include "Engine.h"

class TurboEngine : public Engine {
public:
    TurboEngine() {}

    double computePrice() const override {
        return price + 100;
    }

    std::string toString() const override {
        return "Turbo | Price: " + std::to_string(computePrice());
    }
};
