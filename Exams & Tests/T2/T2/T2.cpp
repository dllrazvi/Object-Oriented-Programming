#include "Service.h"
#include "Refrigerator.h"
#include "DishWasher.h"
#include <iostream>
#include <limits>

int main() {
    Service applianceService;
    bool running = true;

    Refrigerator* fridge1 = new Refrigerator("RF123", "A++", true);

    Refrigerator* fridge2 = new Refrigerator("RF124", "A", false);

    DishWasher* dishwasher1 = new DishWasher("DW123", 1.5);

    applianceService.addAppliance(fridge1);

    applianceService.addAppliance(fridge2);

    applianceService.addAppliance(dishwasher1);

    while (running) {
        std::cout << "\nAppliance Management System\n";
        std::cout << "1. Add Refrigerator\n";
        std::cout << "2. Add Dish Washer\n";
        std::cout << "3. Show all appliances\n";
        std::cout << "4. Show appliances with consumption less than a value\n";
        std::cout << "5. Save appliances to file\n";
        std::cout << "6. Show all inefficient appliances\n";
        std::cout << "7. Exit\n";
        std::cout << "Choose an option: ";

        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore last input
            std::cout << "You can only enter numbers.\n";
            continue;
        }

        switch (choice) {
        case 1: {
            std::string id, usageClass;
            bool hasFreezer;
            std::cout << "Enter refrigerator ID: ";
            std::cin >> id;
            std::cout << "Enter electricity usage class (A or A++): ";
            std::cin >> usageClass;
            std::cout << "Does it have a freezer? (1 for yes, 0 for no): ";
            std::cin >> hasFreezer;

            Refrigerator* fridge = new Refrigerator(id, usageClass, hasFreezer);
            applianceService.addAppliance(fridge);
            std::cout << "Refrigerator added.\n";
            break;
        }
        case 2: {
            std::string id;
            double consumedElectricityForOneHour;
            std::cout << "Enter dish washer ID: ";
            std::cin >> id;
            std::cout << "Enter consumed electricity for one hour (KW): ";
            std::cin >> consumedElectricityForOneHour;

            DishWasher* washer = new DishWasher(id, consumedElectricityForOneHour);
            applianceService.addAppliance(washer);
            std::cout << "Dish Washer added.\n";
            break;
        }
        case 3: {
            std::vector<Appliance*> appliances = applianceService.getAllAppliances();
            for (const auto& appliance : appliances) {
                std::cout << appliance->toString() << std::endl;
            }
            break;
        }
        case 4: {
            double maxElectricity;
            std::cout << "Enter the maximum consumed electricity (KW): ";
            std::cin >> maxElectricity;
            std::vector<Appliance*> lowConsumingAppliances = applianceService.getAppliancesWithConsumptionLessThan(maxElectricity);
            for (const auto& appliance : lowConsumingAppliances) {
                std::cout << appliance->toString() << std::endl;
            }
            break;
        }
        case 5: {
            double maxElectricity;
            std::string filename;
            std::cout << "Enter the maximum consumed electricity (KW) for saving: ";
            std::cin >> maxElectricity;
            std::cout << "Enter the filename to save appliances to: ";
            std::cin >> filename;
            applianceService.writeFileWithAppliancesWithConsumptionLessThan(maxElectricity, filename);
            std::cout << "Appliances saved to " << filename << ".\n";
            break;
        }
        
        case 6: {
            std::vector<Appliance*> inefficientAppliances = applianceService.getInefficientAppliances();
            std::cout << "Inefficient Appliances:\n";
            for (const auto& appliance : inefficientAppliances) {
                std::cout << appliance->toString() << std::endl;
            }
            if (inefficientAppliances.empty()) {
                std::cout << "No inefficient appliances found.\n";
            }
            break;
        }
        case 7: {
            running = false;
            break;
        }
        default: {
            std::cout << "Invalid option. Please try again.\n";
        }
        }
        

    }

    return 0;
}
