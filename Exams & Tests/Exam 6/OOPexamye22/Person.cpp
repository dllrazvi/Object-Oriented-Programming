#include "Person.h"

Person::Person(const QString& name, double latitude, double longitude, bool isOrganizer)
    : name(name), latitude(latitude), longitude(longitude), organizer(isOrganizer) {}

QString Person::getName() const {
    return name;
}

double Person::getLatitude() const {
    return latitude;
}

double Person::getLongitude() const {
    return longitude;
}

bool Person::isOrganizer() const {
    return organizer;
}
