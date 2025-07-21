#include "event.h"
#include "string"
#include "vector"
#include <sstream>


Event::Event() 
{
	this->organizer = "";
	this->name = "";
	this->date = "";
	this->description = "";
	this->latitude = 0;
	this->longitude = 0;
}

Event::Event(std::string organizer, std::string name, std::string description, int latitude, int longitude, std::string date)
{
	this->organizer = organizer;
	this->name = name;
	this->date = date;
	this->description = description;
	this->latitude = latitude;
	this->longitude = longitude;
}

std::vector<std::string> tokenize(const std::string& str, char delimiter)
{
	std::vector<std::string> tokens;
	std::istringstream stream(str);
	std::string token;
	while (std::getline(stream, token, delimiter))
		tokens.push_back(token);
	return tokens;
}

std::istream& operator>>(std::istream& is, Event& e)
{
	std::string line;
	std::getline(is, line);
	if (line.empty())
		return is;
	std::vector<std::string> tokens;
	tokens = tokenize(line, ',');
	e.organizer= tokens[0];
	e.name = tokens[1];
	e.description = tokens[2];
	e.latitude = std::stoi(tokens[3]);
	e.longitude = std::stoi(tokens[4]);
	e.date = tokens[5];
	return is;
}

std::ostream& operator<<(std::ostream& os, Event& e)
{
	os<< e.organizer << "," << e.name << "," << e.description << "," << e.latitude << "," << e.longitude << "," << e.date << "\n";
	return os;
}

std::string Event::toString()
{
	std::string s;
	s = this->organizer + " | " + this->name + " | " + this->description + " | " + std::to_string(this->latitude) + " | " + std::to_string(this->longitude) + " | " + this->date;
	return s;
}


