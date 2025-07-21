#include "ProteinService.h"
#include <algorithm>
#include <iostream>

bool ProteinService::addProtein(const Protein& protein) {
    return repository.addProtein(protein);
}
bool ProteinService::removeProtein(const std::string& organism, const std::string& name) {
    return repository.removeProtein(organism, name);
}

void ProteinService::listAllProteins() const {
    std::vector<Protein> proteins = repository.getAllProteins();
    std::sort(proteins.begin(), proteins.end(), [](const Protein& a, const Protein& b) {
        return a.name < b.name; // Sort by protein name.
        });
    for (const Protein& p : proteins) {
        std::cout << p.organism << " | " << p.name << " | " << p.sequence << std::endl;
    }
}

void ProteinService::listProteinsBySequence(const std::string& sequence) const {
    std::vector<Protein> proteins = repository.getProteinsBySequence(sequence);
    if (proteins.empty()) {
        std::cout << "No proteins found with the given sequence." << std::endl;
        return;
    }

    // Sort proteins by name and then by sequence length if names are equal
    std::sort(proteins.begin(), proteins.end(),
        [](const Protein& a, const Protein& b) {
            if (a.name == b.name) {
                return a.sequence.length() < b.sequence.length();
            }
            return a.name < b.name;
        }
    );

    // Now the list is sorted, we can print it
    for (const Protein& p : proteins) {
        std::cout << p.organism << " | " << p.name << " | " << p.sequence.length() << " | " << p.sequence << std::endl;
    }
}
