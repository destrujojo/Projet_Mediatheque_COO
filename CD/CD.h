#ifndef CD_H
#define CD_H

#include "../Ressources/Ressources.h"
#include <iostream>
#include "../include/json.hpp"
using json = nlohmann::json;

class CD : public Ressources
{
public:
    CD();
    CD(std::string Auteur, std::string MaisonProduction, std::string Titre, float Duree, int NombrePistes, bool Etat, std::string NomEmprunteur);
    ~CD();
    void setAuteur(std::string Auteur);
    void setMaisonProduction(std::string MaisonProduction);
    void setTitre(std::string Titre);
    void setDuree(float Duree);
    void setNombrePistes(int NombrePistes);
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

private:
    std::string Auteur;
    std::string MaisonProduction;
    std::string Titre;
    float Duree;
    int NombrePistes;
    bool Etat;
    std::string NomEmprunteur;
};

#endif // CD_H
