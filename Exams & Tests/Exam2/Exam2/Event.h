#pragma once
#include <string>
#include <vector>

class Event {
    std::string organiser;
    std::string name;
    std::string description;
    double latitude;
    double longitude;
    std::string date;
    std::vector<std::string> attendees;

public:
    Event(std::string organiser, std::string name, std::string desc,
        double lat, double lon, std::string date)
        : organiser(organiser), name(name), description(desc),
        latitude(lat), longitude(lon), date(date) {
    }

    const std::string& getOrganiser() const { return organiser; }
    const std::string& getName() const { return name; }
    const std::string& getDescription() const { return description; }
    const std::string& getDate() const { return date; }
    double getLat() const { return latitude; }
    double getLon() const { return longitude; }

    const std::vector<std::string>& getAttendees() const { return attendees; }

    void addAttendee(const std::string& name) {
        if (std::find(attendees.begin(), attendees.end(), name) == attendees.end())
            attendees.push_back(name);
    }

    void removeAttendee(const std::string& name) {
        attendees.erase(std::remove(attendees.begin(), attendees.end(), name), attendees.end());
    }

    std::string toString() const;
    bool isSame(const Event& other) const;
};
