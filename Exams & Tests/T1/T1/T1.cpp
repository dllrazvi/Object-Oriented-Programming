#include "ui.h"
#include "school_service.h"
#include "repo.h"

int main() {
    SchoolRepo repo;
    SchoolService service(repo);

  
    service.addSchool("Avram_Iancu", 46.77, 23.60, "15.04.2022");
    service.addSchool("George_Cosbuc", 46.77, 23.58, "18.04.2022");
    service.addSchool("Alexandru_Vaida_Voicod", 46.77, 23.63, "23.04.2022");
    service.addSchool("Romulus_Guga", 46.53, 24.57, "04.05.2022");
    service.addSchool("Colegiul_Transilvania", 46.54, 24.57, "03.05.2022");

    UI ui(service);
    ui.run();
    return 0;
}