//
// Created by jonathan.roy on 26/09/2024.
//

#ifndef CD_H
#define CD_H

#include "../Ressources/Ressources.h"
#include <iostream>


class CD : public Ressources {
    public:
        CD();
        CD(std::string Auteur, std::string MaisonProduction, std::string Titre, float Duree, int NombrePistes);
        ~CD();
        void setAuteur(std::string Auteur);
        void setMaisonProduction(std::string MaisonProduction);
        void setTitre(std::string Titre);
        void setDuree(float Duree);
        void setNombrePistes(int NombrePistes);

        std::string getAuteur();
        std::string getMaisonProduction();
        std::string getTitre();
        float getDuree();
        int getNombrePistes();
    private:
        std::string Auteur;
        std::string MaisonProduction;
        std::string Titre;
        float Durree;
        int NombrePistes;
};



#endif //CD_H