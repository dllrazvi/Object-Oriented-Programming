#include "person.h"
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>

Person::Person()
{
	this->name = "";
	this->latitude = 0;
	this->longitude = 0;
	this->status = 0;
}

Person::Person(std::string name, int latitude, int longitude, bool status)
{
	this->name = name;
	this->latitude = latitude;
	this->longitude = longitude;
	this->status = status;
}

std::vector<std::string> tokenize1(const std::string& str, char delimiter)
{
	std::vector<std::string> tokens;
	std::istringstream stream(str);
	std::string token;
	while (std::getline(stream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}

std::istream& operator>>(std::istream& is, Person& p)
{
	std::string line;
	std::getline(is, line);
	if (line.empty())
		return is;
	std::vector<std::string> tokens;
	tokens = tokenize1(line, ',');
	p.name= tokens[0];
	p.latitude = std::stoi(tokens[1]);
	p.longitude = std::stoi(tokens[2]);
	if(tokens[3] == "1")
		p.status = true;
	if(tokens[3] == "0")
		p.status = false;
	return is;
}

std::ostream& operator<<(std::ostream& os, const Person& p)
{
	os<< p.name << "," << p.latitude << "," << p.longitude << "," << p.status << "\n";
	return os;
}

std::string Person::toString()
{
	std::string s;
	s = this->name + " | " + std::to_string(this->latitude) + " | " + std::to_string(this->longitude) + " | " + std::to_string(this->status);
	return s;
}

