#pragma once
#include <string>
#include "Engine.h"

class Car {
private:
    std::string bodyStyle;
    Engine* engine;
public:
    Car(const std::string& bodyStyle, Engine* engine) : bodyStyle(bodyStyle), engine(engine) {}

    double getPrice() const {
        double base = (bodyStyle == "Sedan" ? 8000 : 10000);
        return base + engine->computePrice();
    }

    std::string toString() const {
        return "Body: " + bodyStyle + " | " + engine->toString() + " | Total Price: " + std::to_string(getPrice());
    }

    ~Car() {
        delete engine;
    }
};
