#include "DocumentRepository.h"
#include <QFile>
#include <QTextStream>

void DocumentRepository::loadFromFile(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split("|", Qt::SkipEmptyParts);
        if (parts.size() >= 2) {
            QString name = parts[0].trimmed();
            QString content;
            for (int i = 1; i < parts.size(); ++i)
                content += parts[i].trimmed() + " ";
            docs.emplace_back(name, content.trimmed());
        }
    }
    file.close();
}

const std::vector<Document>& DocumentRepository::getAll() const {
    return docs;
}
