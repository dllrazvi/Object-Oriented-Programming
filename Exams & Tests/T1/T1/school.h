#pragma once
#ifndef SCHOOL_H
#define SCHOOL_H

#include <string>
#include <cmath>
#include <sstream>
#include <vector>
#include <algorithm>

class School {
private:
    std::string name;
    double latitude;
    double longitude;
    std::string date;

public: 
    School(); // Constructor implicit (dacă e necesar)
    School(const std::string& name, double latitude, double longitude, const std::string& date);

    std::string getName() const;
    double getLatitude() const;
    double getLongitude() const;
    std::string getDate() const;

    double distanceTo(double lat, double lon) const;
    std::string toString() const;
};


#endif
