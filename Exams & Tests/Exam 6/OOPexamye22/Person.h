#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person {
public:
    Person(const QString& name, double latitude, double longitude, bool isOrganizer)
        : name(name), latitude(latitude), longitude(longitude), isOrganizer(isOrganizer) {}

    QString getName() const { return name; }
    double getLatitude() const { return latitude; }
    double getLongitude() const { return longitude; }
    bool isOrganizer() const { return isOrganizer; }

private:
    QString name;
    double latitude;
    double longitude;
    bool isOrganizer;
};

#endif // PERSON_H
