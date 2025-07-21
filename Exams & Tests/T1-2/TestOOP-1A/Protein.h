#pragma once
#ifndef PROTEIN_H
#define PROTEIN_H

#include <string>

class Protein {
public:
    std::string organism;
    std::string name;
    std::string sequence;

    Protein(const std::string& org, const std::string& name, const std::string& seq)
        : organism(org), name(name), sequence(seq) {}
};

#endif // PROTEIN_H
