#include "UI.h"
#include <iostream>
#include <string>
#include <iomanip>

UI::UI(SchoolService& service) : service_{ service } {}

void UI::run() {
    while (true) {
        displayMenu();
        int choice = getChoice();
        switch (choice) {
        case 1:
            addSchool();
            break;
        case 2:
            removeSchool();
            break;
        case 3:
            listAllSchools();
            break;
        case 4:
            listSchoolsByPlannedVisitDate();
            break;
        case 5:
            markSchoolAsVisited();
            break;
        case 0:
            std::cout << "Exiting application...\n";
            return;
        default:
            std::cout << "Invalid option. Please try again.\n";
            break;
        }
    }
}

void UI::displayMenu() const {
    std::cout << "\n--- Main Menu ---\n"
        << "1. Add school\n"
        << "2. Remove school\n"
        << "3. List all schools\n"
        << "4. List schools by planned visit date\n"
        << "5. Mark school as visited\n"
        << "0. Exit\n";
}

int UI::getChoice() const {
    int choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore(); // ignore newline character
    return choice;
}

void UI::addSchool() {
    std::string name;
    double latitude, longitude;
    std::string plannedVisitDate;

    std::cout << "Enter the name of the school: ";
    std::getline(std::cin, name);

    std::cout << "Enter the latitude of the school: ";
    std::cin >> latitude;

    std::cout << "Enter the longitude of the school: ";
    std::cin >> longitude;

    std::cout << "Enter the planned visit date of the school (YYYY-MM-DD): ";
    std::getline(std::cin, plannedVisitDate);

    service_.addSchool(name, latitude, longitude, plannedVisitDate);
}

void UI::removeSchool() {
    std::string name;
    double latitude, longitude;

    std::cout << "Enter the name of the school: ";
    std::getline(std::cin, name);

    std::cout << "Enter the latitude of the school: ";
    std::cin >> latitude;

    std::cout << "Enter the longitude of the school: ";
    std::cin >> longitude;

    service_.removeSchool(name, latitude, longitude);
}

void UI::listAllSchools() const {
    std::vector<School> schools = service_.getAllSchools();
    if (schools.empty()) {
        std::cout << "There are no schools to display.\n";
        return;
    }

    std::cout << std::setw(20) << std::left << "Name"
        << std::setw(15) << std::left << "Latitude"
        << std::setw(15) << std::left << "Longitude"
        << std::setw(20) << std::left << "Planned Visit Date"
        << std::setw(10) << std::left << "Visited\n";
    std::cout << std::setfill('-') << std::setw(80) << "\n" << std::setfill(' ');

    for (const auto& school : schools) {
        std::cout << std::setw(20) << std::left << school.getName()
            << std::setw(15) << std
