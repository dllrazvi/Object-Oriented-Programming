#include "ProteinRepository.h"
#include "ProteinService.h"
#include "ConsoleUI.h"

int main() {
    ProteinRepository repository;
    Protein p("org","name","seq");
    Protein p2("org1", "name1", "seq1");
    Protein p3("org2", "name2", "seq2");
    Protein p4("org3", "name3", "seq3");
    Protein p5("org3", "name3", "seq3");
    repository.addProtein(p);
    repository.addProtein(p2);
    repository.addProtein(p3);
    repository.addProtein(p4);
    repository.addProtein(p5);
    ProteinService service(repository);
    ConsoleUI console(service);
    console.run();
    return 0;
}
