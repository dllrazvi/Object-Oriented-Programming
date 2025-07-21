#pragma once
#pragma once
#include <string>

class Person {
    std::string name;
    double latitude;
    double longitude;
    bool organiser;

public:
    Person(std::string name, double lat, double lon, bool organiser)
        : name(name), latitude(lat), longitude(lon), organiser(organiser) {
    }

    const std::string& getName() const { return name; }
    double getLat() const { return latitude; }
    double getLon() const { return longitude; }
    bool isOrganiser() const { return organiser; }

    std::string toString() const;
};
