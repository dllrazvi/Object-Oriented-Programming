#include "ui.h"
#include <iostream>

UI::UI(SchoolService& service) : service(service) {}

void UI::run() {
    int cmd;
    while (true) {
        std::cout << "\n1. Add School\n2. Show All Schools\n3. Show Closest Schools\n0. Exit\n> ";
        std::cin >> cmd;
        if (cmd == 0) break;
        if (cmd == 1) {
            std::string name, date;
            double lat, lon;
            std::cout << "Name: "; std::cin >> name;
            std::cout << "Latitude: "; std::cin >> lat;
            std::cout << "Longitude: "; std::cin >> lon;
            std::cout << "Date: "; std::cin >> date;
            if (service.addSchool(name, lat, lon, date))
                std::cout << "Added successfully!\n";
            else
                std::cout << "School already exists.\n";
        }
        else if (cmd == 2) {
            for (const auto& s : service.getAllSchools()) {
                std::cout << s.toString() << "\n";
            }
        }
        else if (cmd == 3) {
            double lat, lon;
            std::cout << "Enter your location (lat lon): ";
            std::cin >> lat >> lon;
            for (const auto& s : service.getClosestSchools(lat, lon)) {
                std::cout << s.toString() << "\n";
            }
        }
    }
}
