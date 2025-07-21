#include "school.h"
#include <sstream>
#include <cmath>
#include <string>


School::School(const std::string& name, double latitude, double longitude, const std::string& date)
    : name(name), latitude(latitude), longitude(longitude), date(date) {
}

std::string School::getName() const { return name; }
double School::getLatitude() const { return latitude; }
double School::getLongitude() const { return longitude; }
std::string School::getDate() const { return date; }

double School::distanceTo(double lat, double lon) const {
    return sqrt(pow(latitude - lat, 2) + pow(longitude - lon, 2));
}

std::string School::toString() const {
    std::ostringstream oss;
    oss << name << " | " << latitude << ", " << longitude << " | " << date;
    return oss.str();
}
School::School() : name(""), latitude(0.0), longitude(0.0), date("") {}

