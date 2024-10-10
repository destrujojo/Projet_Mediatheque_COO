#ifndef VHS_H
#define VHS_H

#include <iostream>
#include "../Ressources/Ressources.h"

class VHS : public Ressources
{
public:
    VHS();
    VHS(std::string Auteur, std::string MaisonProduction, float Duree);
    ~VHS();

    void setAuteur(std::string Auteur);
    void setMaisonProduction(std::string MaisonProduction);
    void setDuree(float Duree);

    std::string getAuteur();
    std::string getMaisonProduction();
    float getDuree();

    void afficheInformation() override;

protected:
    std::string Auteur;
    std::string MaisonProduction;
    float Duree;
};

#endif // VHS_H
