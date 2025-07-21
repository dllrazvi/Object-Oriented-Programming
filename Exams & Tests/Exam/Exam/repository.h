#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "event.h"
#include "person.h"
class Repository
{
private:
	std::vector<Event> events;
	std::vector<Person> persons;
public:
	Repository();
	~Repository();

	void loadFromFile();
	void saveToFile();

	std::vector<Event> getEvents() { return this->events; }
	std::vector<Person> getPersons() { return this->persons; }

	void addEvent(Event e) { this->events.push_back(e); }
	void addPerson(Person p) { this->persons.push_back(p); }
};

