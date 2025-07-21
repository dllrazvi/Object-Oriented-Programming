#ifndef DEPARTMENTREPOSITORY_H
#define DEPARTMENTREPOSITORY_H

#include "Department.h"
#include <vector>

class DepartmentRepository {
private:
    std::vector<Department> departments;

public:
    void loadFromFile(const QString& filename);
    std::vector<Department>& getDepartments();
};

#endif // DEPARTMENTREPOSITORY_H
