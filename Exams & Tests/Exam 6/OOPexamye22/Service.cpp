#include "Service.h"
#include <algorithm>

Service::Service(Repository* repo) : repo(repo) {
    events = repo->readEvents();
    persons = repo->readPersons();
}

std::vector<Event> Service::getEvents() {
    std::sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        return a.getDate() < b.getDate();
        });
    return events;
}

std::vector<Person> Service::getPersons() {
    return persons;
}

void Service::addEvent(const Event& event) {
    auto it = std::find_if(events.begin(), events.end(), [&event](const Event& e) {
        return e.getName() == event.getName() && e.getLatitude() == event.getLatitude() && e.getLongitude() == event.getLongitude();
        });

    if (it == events.end()) {
        events.push_back(event);
        repo->writeEvents(events);
    }
}

void Service::addPerson(const Person& person) {
    persons.push_back(person);
    repo->writePersons(persons);
}
