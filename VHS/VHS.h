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
    VHS(std::string Auteur, std::string MaisonProduction, float Duree, bool Etat, std::string NomEmprunteur);
    ~VHS();

    void setAuteur(std::string Auteur);
    void setMaisonProduction(std::string MaisonProduction);
    void setDuree(float Duree);
    void setEtat(bool Etat) override;
    void setNomEmprunteur(std::string NomEmprunteur) override;

    std::string getAuteur() const override;
    std::string getCollection() const override;
    std::string getTitre() const override;
    std::string getResumer() const override;
    std::string getEditeur() const override;
    std::string getMaisonProduction() const override;
    std::string getTypes() const override;
    std::string getNomAcces() const override;
    std::string getType() const override;

    int getAnneePublication() const override;
    int getNombrePages() const override;
    int getTaille() const override;
    int getNombrePistes() const override;
    int getNbArticles() const override;
    float getDuree() const override;
    bool getEtat() const override;
    std::string getNomEmprunteur() const override;

    void afficheInformation() const override;
    json to_json() const override;

protected:
    std::string Auteur;
    std::string MaisonProduction;
    float Duree;
    bool Etat;
    std::string NomEmprunteur;
};

#endif // VHS_H
