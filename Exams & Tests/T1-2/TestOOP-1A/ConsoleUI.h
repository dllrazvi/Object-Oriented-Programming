#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "ProteinService.h"
#include <iostream>

class ConsoleUI {
    ProteinService& service;

public:
    ConsoleUI(ProteinService& srv) : service(srv) {}

    void run();
};

#endif // CONSOLEUI_H
