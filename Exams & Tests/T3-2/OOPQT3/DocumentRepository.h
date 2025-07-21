#pragma once
#include "Document.h"
#include <vector>

class DocumentRepository {
private:
    std::vector<Document> docs;
public:
    void loadFromFile(const QString& filename);
    const std::vector<Document>& getAll() const;
};
