#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <vector>
#include "Event.h"
#include "Person.h"

class Repository {
public:
    std::vector<Event> readEvents();
    std::vector<Person> readPersons();
    void writeEvents(const std::vector<Event>& events);
    void writePersons(const std::vector<Person>& persons);
};

#endif // REPOSITORY_H
