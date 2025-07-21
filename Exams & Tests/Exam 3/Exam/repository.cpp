#include "repository.h"
#include <fstream>
#include <algorithm>
#include <sstream>
#include <string>

Repository::Repository()
{
	this->loadFromFile();
}
Repository::~Repository()
{
	this->saveToFile();
}

void Repository::loadFromFile()
{
	std::string file1 = "events.txt";
	std::string file2 = "persons.txt";

	if (!file1.empty())
	{
		Event e;
		std::ifstream fin1(file1);
		while (fin1 >> e)
			this->events.push_back(e);
		fin1.close();
	}
	if (!file2.empty())
	{
		Person p;
		std::ifstream fin2(file2);
		while (fin2 >> p)
			this->persons.push_back(p);
		fin2.close();
	}
}

void Repository::saveToFile()
{
	std::string file1 = "events.txt";
	std::string file2 = "persons.txt";

	if (!file1.empty())
	{
		std::ofstream fout1(file1);
		for (auto e : this->events)
			fout1 << e;
		fout1.close();
	}
	if (!file2.empty())
	{
		std::ofstream fout2(file2);
		for (auto p : this->persons)
			fout2 << p;
		fout2.close();
	}
}