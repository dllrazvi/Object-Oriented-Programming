#include "Event.h"

Event::Event(const QString& name, const QString& description, double latitude, double longitude, const QString& date, bool organizer)
    : name(name), description(description), latitude(latitude), longitude(longitude), date(date), organizer(organizer) {}

QString Event::getName() const {
    return name;
}

QString Event::getDescription() const {
    return description;
}

double Event::getLatitude() const {
    return latitude;
}

double Event::getLongitude() const {
    return longitude;
}

QString Event::getDate() const {
    return date;
}

bool Event::getOrganizer() const {
    return organizer;
}

std::vector<QString> Event::getAttendees() const {
    return attendees;
}

void Event::addAttendee(const QString& attendee) {
    attendees.push_back(attendee);
}

void Event::setDescription(const QString& newDescription) {
    description = newDescription;
}

void Event::setDate(const QString& newDate) {
    date = newDate;
}
