#include "ProteinRepository.h"
#include <locale>

bool ProteinRepository::addProtein(const Protein& protein) {
    for (const auto& existing_protein : proteins) {
        if (existing_protein.organism == protein.organism && existing_protein.name == protein.name) {
            return false;  // Protein already exists.
        }
    }
    proteins.push_back(protein);
    return true;
}

bool ProteinRepository::removeProtein(const std::string& organism, const std::string& name) {
    auto it = std::find_if(proteins.begin(), proteins.end(),
        [&organism, &name](const Protein& p) {
            return p.organism == organism && p.name == name;
        });
    if (it != proteins.end()) {
        proteins.erase(it);
        return true;
    }
    return false;
}

std::vector<Protein> ProteinRepository::getAllProteins() const {
    return proteins;
}

std::vector<Protein> ProteinRepository::getProteinsBySequence(const std::string& sequence) const {
    std::vector<Protein> filtered_proteins;
    std::copy_if(proteins.begin(), proteins.end(), std::back_inserter(filtered_proteins), [&sequence](const Protein& p) {
        return p.sequence.find(sequence) != std::string::npos;
        });
    return filtered_proteins;
}
