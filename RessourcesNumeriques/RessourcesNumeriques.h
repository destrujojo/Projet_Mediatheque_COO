#ifndef RESSOURCESNUMERIQUES_H
#define RESSOURCESNUMERIQUES_H

#include "../Ressources/Ressources.h"
#include <iostream>
#include "../include/json.hpp"
using json = nlohmann::json;

class RessourcesNumeriques : public Ressources
{
public:
    RessourcesNumeriques();
    RessourcesNumeriques(std::string Auteur, std::string Type, std::string NomAcces, int Taille, bool Etat, std::string NomEmprunteur);
    ~RessourcesNumeriques();

    void setAuteur(std::string Auteur);
    void setType(std::string Type);
    void setNomAcces(std::string NomAcces);
    void setTaille(int Taille);
    void setEtat(bool etat) override;
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
    std::string Type;
    std::string NomAcces;
    int Taille;
    bool Etat;
    std::string NomEmprunteur;
};

#endif // RESSOURCESNUMERIQUES_H