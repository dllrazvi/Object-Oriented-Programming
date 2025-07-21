#ifndef DEPARTMENTSERVICE_H
#define DEPARTMENTSERVICE_H

#include "DepartmentRepository.h"
#include <vector>

class DepartmentService {
private:
    DepartmentRepository& repo;

public:
    DepartmentService(DepartmentRepository& repo);
    std::vector<Department> getAllDepartments() const;
};

#endif // DEPARTMENTSERVICE_H
