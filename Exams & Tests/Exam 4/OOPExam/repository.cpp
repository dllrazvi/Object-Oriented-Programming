#include "repository.h"
#include <fstream>
#include <sstream>


void repository::read_E_from_file()
{
	ifstream file("events.txt");
	string line;
	while (getline(file, line))
	{
		stringstream ss(line);
		string o, n, d, la, lo, date;
		getline(ss, o, ',');
		getline(ss, n, ',');
		getline(ss, d, ',');
		getline(ss, la, ',');
		getline(ss, lo, ',');
		getline(ss, date, ',');

		add_event(o, n, d, stoi(la), stoi(lo), date);
	}
}

void repository::read_P_from_file()
{
	ifstream file("people.txt");
	string line;

	while (getline(file, line))
	{
		stringstream ss(line);
		string name, la, lo, status;
		getline(ss, name, ',');
		getline(ss, la, ',');
		getline(ss, lo, ',');
		getline(ss, status, ',');

		add_person(name, stoi(la), stoi(lo), stoi(status));



	}
}

void repository::write_E_to_file()
{

}

void repository::write_P_to_file()
{
}

void repository::add_event(string o, string n, string d, int la, int lo, string date)
{
	event E { o, n, d, la, lo, date };
	EList.push_back(E);
}

void repository::add_person(string n, int la, int lo, int s)
{
	person P(n, la, lo, s);
	PList.push_back(P);
}