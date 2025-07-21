#include "FileRepo.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

FileRepo::FileRepo(std::string pf, std::string ef)
    : peopleFile{ pf }, eventFile{ ef }
{
    std::ifstream inPeople(pf);
    std::string line;
    while (std::getline(inPeople, line)) {
        std::istringstream ss(line);
        std::string name;
        double lat, lon;
        bool isOrg;
        ss >> name >> lat >> lon >> isOrg;
        persons.emplace_back(name, lat, lon, isOrg);
    }

    std::ifstream inEvents(ef);
    while (std::getline(inEvents, line))
    {
        std::istringstream ss(line);
        std::string organiser, name, desc, date;
        double lat = 0.0, lon = 0.0;

        std::getline(ss, organiser, ';');
        std::getline(ss, name, ';');
        std::getline(ss, desc, ';');
        ss >> lat >> lon;          
        ss.ignore();               
        std::getline(ss, date, ';');

        Event e{ organiser, name, desc, lat, lon, date };

        std::string att;
        while (ss >> att)
            e.addAttendee(att);

        events.push_back(e);
    }
}

const std::vector<Person>& FileRepo::getAllPersons() const {
    return persons;
}

const std::vector<Event>& FileRepo::getAllEvents() const {
    return events;
}

void FileRepo::addEvent(const Event& e) {
    for (const auto& ev : events)
        if (ev.isSame(e))
            throw std::runtime_error("Duplicate event!");
    events.push_back(e);
}

void FileRepo::updateEvent(const Event& updated) {
    for (auto& ev : events)
        if (ev.isSame(updated)) {
            ev = updated;
            return;
        }
    throw std::runtime_error("Event not found");
}

void FileRepo::saveToFile() const {
    std::ofstream out(eventFile);
    for (const auto& ev : events) {
        out << ev.getOrganiser() << ";" << ev.getName() << ";" << ev.getDescription()
            << ";" << ev.getLat() << " " << ev.getLon() << ";" << ev.getDate() << "; ";
        for (const auto& a : ev.getAttendees())
            out << a << " ";
        out << "\n";
    }
}

void FileRepo::clearAttendees() {
    for (auto& e : events)
        e = Event(e.getOrganiser(), e.getName(), e.getDescription(), e.getLat(), e.getLon(), e.getDate());
}

void FileRepo::addAttendee(const std::string& eventName, const std::string& personName) {
    for (auto& ev : events)
        if (ev.getName() == eventName) {
            ev.addAttendee(personName);
            return;
        }
}
