#include "school_service.h"
#include "repo.h"
#include <cassert>
#include <iostream>

void testAddSchool() {
    SchoolRepo repo;
    SchoolService service(repo);

    assert(service.addSchool("TestSchool", 10.0, 20.0, "01.01.2023") == true);  // valid
    assert(service.addSchool("TestSchool", 10.0, 20.0, "01.01.2023") == false); // duplicat
    std::cout << "testAddSchool passed \n";
}

void testGetClosestSchools() {
    SchoolRepo repo;
    SchoolService service(repo);

    service.addSchool("A", 0.0, 0.0, "01.01.2023");
    service.addSchool("B", 1.0, 1.0, "01.01.2023");
    service.addSchool("C", 2.0, 2.0, "01.01.2023");
    service.addSchool("D", 3.0, 3.0, "01.01.2023");

    auto closest = service.getClosestSchools(0.0, 0.0);
    assert(closest.size() == 3);
    assert(closest[0].getName() == "A");
    assert(closest[1].getName() == "B");
    assert(closest[2].getName() == "C");
    std::cout << "testGetClosestSchools passed \n";
}

int main() {
    testAddSchool();
    testGetClosestSchools();
    std::cout << "All tests passed! \n";
    return 0;
}
