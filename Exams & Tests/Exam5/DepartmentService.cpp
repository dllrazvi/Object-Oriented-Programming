#include "DepartmentService.h"

DepartmentService::DepartmentService(DepartmentRepository& repo) : repo(repo) {}

std::vector<Department> DepartmentService::getAllDepartments() const {
    return repo.getDepartments();
}
