#pragma once
#include "Engine.h"

class ElectricEngine : public Engine {
private:
    int autonomy;
public:
    ElectricEngine(int autonomy) : autonomy(autonomy) {}

    double computePrice() const override {
        return price + autonomy * 0.01;
    }
    std::string toString() const override {
        return "Electric | Autonomy: " + std::to_string(autonomy) + " | Price: " + std::to_string(computePrice());
    }
};
