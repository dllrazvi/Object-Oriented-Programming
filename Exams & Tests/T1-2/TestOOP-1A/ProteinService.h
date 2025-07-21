#ifndef PROTEINSERVICE_H
#define PROTEINSERVICE_H

#include "ProteinRepository.h"

class ProteinService {
    ProteinRepository& repository;

public:
    ProteinService(ProteinRepository& repo) : repository(repo) {}
    bool addProtein(const Protein& protein);
    bool removeProtein(const std::string& organism, const std::string& name);
    void listAllProteins() const;
    void listProteinsBySequence(const std::string& sequence) const;
};

#endif // PROTEINSERVICE_H
