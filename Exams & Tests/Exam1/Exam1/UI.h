#pragma once
#ifndef UI_HPP
#define UI_HPP

#include "Service.h"

class SchoolUI {
private:
    SchoolService& service;

public:
    SchoolUI(SchoolService& service);
    void run();
};

#endif // UI_HPP
