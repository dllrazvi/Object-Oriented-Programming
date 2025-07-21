#pragma once
#include "FileRepo.h"
#include "Observer.h"
#include <cmath>

class Service : public Subject {
    FileRepo& repo;

public:
    Service(FileRepo& r) : repo{ r } {}

    const std::vector<Person>& getPersons() const {
        return repo.getAllPersons();
    }

    const std::vector<Event>& getEvents() const {
        return repo.getAllEvents();
    }

    std::vector<Event> getEventsNear(double lat, double lon, double maxDist) const {
        std::vector<Event> result;
        for (const auto& e : repo.getAllEvents()) {
            double d = std::sqrt(std::pow(lat - e.getLat(), 2) + std::pow(lon - e.getLon(), 2));
            if (d <= maxDist)
                result.push_back(e);
        }
        return result;
    }

    void addEvent(const Event& e) {
        repo.addEvent(e);
        notify();
    }

    void updateDescription(const std::string& name, const std::string& desc) {
        for (auto ev : repo.getAllEvents()) {
            if (ev.getName() == name) {
                Event updated = ev;
                updated = Event(ev.getOrganiser(), ev.getName(), desc, ev.getLat(), ev.getLon(), ev.getDate());
                for (auto a : ev.getAttendees())
                    updated.addAttendee(a);
                repo.updateEvent(updated);
                notify();
                return;
            }
        }
    }

    void personGoing(const std::string& person, const std::string& eventName) {
        repo.addAttendee(eventName, person);
        notify();
    }

    void save() {
        repo.saveToFile();
    }
};
