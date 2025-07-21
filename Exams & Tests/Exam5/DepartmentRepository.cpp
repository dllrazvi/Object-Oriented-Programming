#include "DepartmentRepository.h"
#include <QFile>
#include <QTextStream>

void DepartmentRepository::loadFromFile(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        throw std::runtime_error("Unable to open the file.");

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(',');
        if (parts.size() >= 2) {
            departments.emplace_back(parts[0].trimmed(), parts[1].trimmed());
        }
    }
    file.close();
}

std::vector<Department>& DepartmentRepository::getDepartments() {
    return departments;
}
