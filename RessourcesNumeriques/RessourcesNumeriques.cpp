#include "RessourcesNumeriques.h"
#include <iostream>

RessourcesNumeriques::RessourcesNumeriques() {}

RessourcesNumeriques::RessourcesNumeriques(std::string Auteur, std::string Type, std::string NomAcces, int Taille, bool Etat, std::string NomEmprunteur) : Ressources(Auteur, Type, NomAcces, Taille, Etat, NomEmprunteur)
{
    this->Auteur = Auteur;
    this->Type = Type;
    this->NomAcces = NomAcces;
    this->Taille = Taille;
    this->Etat = Etat;
    this->NomEmprunteur = NomEmprunteur;
}

RessourcesNumeriques::~RessourcesNumeriques() {}

void RessourcesNumeriques::setAuteur(std::string Auteur)
{
    this->Auteur = Auteur;
}
void RessourcesNumeriques::setType(std::string Type)
{
    this->Type = Type;
}
void RessourcesNumeriques::setNomAcces(std::string NomAcces)
{
    this->NomAcces = NomAcces;
}
void RessourcesNumeriques::setTaille(int Taille)
{
    this->Taille = Taille;
}

void RessourcesNumeriques::setEtat(bool etat) { this->Etat = etat; };
void RessourcesNumeriques::setNomEmprunteur(std::string NomEmprunteur) { this->NomEmprunteur = NomEmprunteur; };

std::string RessourcesNumeriques::getAuteur() const { return this->Auteur; };
std::string RessourcesNumeriques::getCollection() const { return ""; };
std::string RessourcesNumeriques::getTitre() const { return ""; };
std::string RessourcesNumeriques::getResumer() const { return ""; };
std::string RessourcesNumeriques::getEditeur() const { return ""; };
std::string RessourcesNumeriques::getMaisonProduction() const { return ""; };
std::string RessourcesNumeriques::getTypes() const { return this->Type; };
std::string RessourcesNumeriques::getNomAcces() const { return this->NomAcces; };
std::string RessourcesNumeriques::getType() const { return "RessourcesNumeriques"; };

int RessourcesNumeriques::getAnneePublication() const { return 0; };
int RessourcesNumeriques::getNombrePages() const { return 0; };
int RessourcesNumeriques::getTaille() const { return this->Taille; };
int RessourcesNumeriques::getNombrePistes() const { return 0; };
int RessourcesNumeriques::getNbArticles() const { return 0; };
float RessourcesNumeriques::getDuree() const { return 0; };
bool RessourcesNumeriques::getEtat() const { return this->Etat; };
std::string RessourcesNumeriques::getNomEmprunteur() const { return this->NomEmprunteur; };

// std::string RessourcesNumeriques::getAuteur() const
// {
//     return this->Auteur;
// }
// std::string RessourcesNumeriques::getType() const
// {
//     return this->Type;
// }
// std::string RessourcesNumeriques::getNomAcces() const
// {
//     return this->NomAcces;
// }
// int RessourcesNumeriques::getTaille() const
// {
//     return this->Taille;
// }

void RessourcesNumeriques::afficheInformation() const
{
    std::cout << "L'auteur est " << this->Auteur << " le type est " << this->Type << " le nom d'accès est " << this->NomAcces << " la taille est " << this->Taille << " Etat de l'emprunt " << this->Etat << " Nom de l'emprunteur " << this->NomEmprunteur << std::endl;
}

json RessourcesNumeriques::to_json() const
{
    json j;
    j["Type"] = "RessourcesNumeriques";
    j["Auteur"] = this->Auteur;
    j["Types"] = this->Type;
    j["NomAcces"] = this->NomAcces;
    j["Taille"] = this->Taille;
    j["Etat"] = this->Etat;
    j["NomEmprunteur"] = this->NomEmprunteur;
    return j;
}