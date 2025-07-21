#pragma once
#define PROTEINREPOSITORY_H

#include "Protein.h"
#include <vector>
#include <algorithm>

class ProteinRepository {
    std::vector<Protein> proteins;

public:
    bool addProtein(const Protein& protein);
    bool removeProtein(const std::string& organism, const std::string& name);
    std::vector<Protein> getAllProteins() const;
    std::vector<Protein> getProteinsBySequence(const std::string& sequence) const;
};

