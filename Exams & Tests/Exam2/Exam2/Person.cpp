#include "Person.h"
#include <sstream>

std::string Person::toString() const {
    std::ostringstream os;
    os << name << " [" << latitude << "," << longitude << "]";
    if (organiser)
        os << " (organiser)";
    return os.str();
}
