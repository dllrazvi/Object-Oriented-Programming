#pragma once
#include "repository.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
class Service
{
private:
	Repository& repo;
public:
	Service(Repository& repo) : repo{ repo } {}

	std::vector<Person> getAllPersons() { return this->repo.getPersons(); }
	std::vector<Event> getAllEvents() { return this->repo.getEvents(); }

	std::vector<Event> getEventsSorted();

	void addPerson(std::string name, int latitute, int longitude, bool status);
	void addEvent(std::string organiser,std::string name, std::string description, int latitute, int longitude, std::string date);
};

