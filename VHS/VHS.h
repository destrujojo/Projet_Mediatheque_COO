#ifndef VHS_H
#define VHS_H

#include <iostream>
#include "../Ressources/Ressources.h"
#include "../include/json.hpp"
using json = nlohmann::json;

class VHS : public Ressources
{
public:
    VHS() = default;
    VHS(std::string Auteur, std::string MaisonProduction, float Duree);
    ~VHS();

    void setAuteur(std::string Auteur);
    void setMaisonProduction(std::string MaisonProduction);
    void setDuree(float Duree);

    std::string getAuteur();
    std::string getMaisonProduction();
    float getDuree();

    void afficheInformation() const override;
    json to_json() const override;

protected:
    std::string Auteur;
    std::string MaisonProduction;
    float Duree;
};

#endif // VHS_H
