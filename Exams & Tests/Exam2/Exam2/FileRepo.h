
#include "Event.h"
#include "Person.h"
#include <vector>
#include <string>

class FileRepo {
    std::vector<Person> persons;
    std::vector<Event> events;

    std::string peopleFile;
    std::string eventFile;

public:
    FileRepo(std::string peopleFile, std::string eventFile);

    const std::vector<Person>& getAllPersons() const;
    const std::vector<Event>& getAllEvents() const;

    void addEvent(const Event& e);
    void updateEvent(const Event& updated);

    void saveToFile() const;
    void clearAttendees();
    void addAttendee(const std::string& eventName, const std::string& personName);
};
