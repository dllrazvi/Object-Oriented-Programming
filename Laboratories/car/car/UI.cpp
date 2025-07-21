#include "UI.h"
#include <iostream>
#include <string>
#include "ElectricEngine.h"
#include "TurboEngine.h"
#include "Car.h"

using namespace std;

void UI::run() {
    // Initial cars
    service.addCar(new Car("Sedan", new TurboEngine()));
    service.addCar(new Car("Convertible", new ElectricEngine(200)));
    service.addCar(new Car("Sedan", new ElectricEngine(150)));

    while (true) {
        cout << "\n1. Add car\n2. Show all cars\n3. Save cars cheaper than price\n0. Exit\n";
        int option;
        cin >> option;

        if (option == 0) break;

        if (option == 1) {
            string bodyStyle, engineType;
            cout << "Body style (Sedan/Convertible): ";
            cin >> bodyStyle;

            cout << "Engine type (Electric/Turbo): ";
            cin >> engineType;

            Engine* engine = nullptr;

            if (engineType == "Electric") {
                int autonomy;
                cout << "Autonomy: ";
                cin >> autonomy;
                engine = new ElectricEngine(autonomy);
            }
            else if (engineType == "Turbo") {
                engine = new TurboEngine();
            }
            else {
                cout << "Invalid engine type!\n";
                continue;
            }

            Car* car = new Car(bodyStyle, engine);
            service.addCar(car);

            cout << "Car added! Price: " << car->getPrice() << "\n";
        }
        else if (option == 2) {
            for (auto car : service.getAllCars()) {
                cout << car->toString() << "\n";
            }
        }
        else if (option == 3) {
            double priceLimit;
            string filename;
            cout << "Enter price limit: ";
            cin >> priceLimit;
            cout << "Enter filename: ";
            cin >> filename;
            service.saveCarsCheaperThan(priceLimit, filename);
            cout << "Cars saved to file.\n";
        }
        else {
            cout << "Invalid option!\n";
        }
    }
}
