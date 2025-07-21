#ifndef UI_H
#define UI_H

#include "school_service.h"

class UI {
private:
    SchoolService& service;

public:
    UI(SchoolService& service);
    void run();
};

#endif
#pragma once
