#ifndef LIVRES_H
#define LIVRES_H

#include "../Ressources/Ressources.h"
#include <iostream>
#include "../include/json.hpp"
using json = nlohmann::json;

class Livres : public Ressources
{
public:
    Livres();
    Livres(std::string Auteur, std::string Collection, std::string Titre, std::string Resumer, int AnneePublication, int NombrePages, bool Etat, std::string NomEmprunteur);
    ~Livres();
    void setAuteur(std::string Auteur);
    void setCollection(std::string Collection);
    void setTitre(std::string Titre);
    void setResumer(std::string Resumer);
    void setAnneePublication(int AnneePublication);
    void setNombrePages(int NombrePages);
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
    std::string Collection;
    std::string Titre;
    std::string Resumer;
    int AnneePublication;
    int NombrePages;
    bool Etat;
    std::string NomEmprunteur;
};
#endif // LIVRES_H
