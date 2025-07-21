#include "ConsoleUI.h"
#include <iostream>

void ConsoleUI::run() {
    std::string command;
    while (true) {
        std::cout << "Enter command (add, remove, list, search, exit): ";
        std::cin >> command;

        if (command == "add") {
            std::string organism, name, sequence;
            std::cin.ignore();  // Ignore the newline character.
            std::cout << "Enter organism, name, and sequence: ";
            std::getline(std::cin, organism);
            std::getline(std::cin, name);
            std::getline(std::cin, sequence);
            Protein protein(organism, name, sequence);
            if (service.addProtein(protein)) {
                std::cout << "Protein added successfully." << std::endl;
            }
            else {
                std::cout << "Error: Protein already exists." << std::endl;
            }
        }
        if (command == "remove") {
            std::string organism, name;
            std::cin.ignore();  // Ignore the newline character.
            std::cout << "Enter organism and name separated by '|': ";
            std::getline(std::cin, organism, '|');
            std::getline(std::cin, name);
            if (service.removeProtein(organism, name)) {
                std::cout << "Protein removed successfully." << std::endl;
            }
            else {
                std::cout << "Protein not found." << std::endl;
            }
        }
        else if (command == "list") {
            service.listAllProteins();
        }
        else if (command == "search") {
            std::string sequence;
            std::cin.ignore(); // Ignore the newline character.
            std::cout << "Enter sequence to search: ";
            std::getline(std::cin, sequence);
            service.listProteinsBySequence(sequence);
        }
        else if (command == "exit") {
            break;
        }
        else {
            std::cout << "Unknown command!\n";
        }
    }
}
