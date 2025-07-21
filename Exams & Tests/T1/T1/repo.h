#ifndef SCHOOL_REPO_H
#define SCHOOL_REPO_H

#include <vector>
#include "school.h"

class SchoolRepo {
private:
    std::vector<School> schools;

public:
    bool addSchool(const School& school);
    const std::vector<School>& getAll() const;
};

#endif
#pragma once
