#ifndef SERVICE_H
#define SERVICE_H

#include <vector>
#include "Person.h"
#include "Event.h"
#include "Repository.h"

class Service {
public:
    Service(Repository* repo);
    std::vector<Event> getEvents();
    std::vector<Person> getPersons();
    void addEvent(const Event& event);
    void addPerson(const Person& person);

private:
    Repository* repo;
    std::vector<Event> events;
    std::vector<Person> persons;
};

#endif // SERVICE_H
