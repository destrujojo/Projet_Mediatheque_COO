#include <iostream>
#include "Livres/Livres.h"

int main() {

    Livres* livres = new Livres("Nathan", "NathanCollection", "Le Monde de Nathan", "L'histoire du rêve de nathan pendant son coma suite à un accident", 2024, 4070);

    livres->afficheInformation();
    std::cout << "Hello, World!" << std::endl;
    delete livres;
    return 0;
}
