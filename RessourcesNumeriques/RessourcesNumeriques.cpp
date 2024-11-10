#include "RessourcesNumeriques.h"
#include <iostream>

RessourcesNumeriques::RessourcesNumeriques() {}

RessourcesNumeriques::RessourcesNumeriques(std::string Auteur, std::string Type, std::string NomAcces, int Taille)
{
    this->Auteur = Auteur;
    this->Type = Type;
    this->NomAcces = NomAcces;
    this->Taille = Taille;
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

std::string RessourcesNumeriques::getAuteur()
{
    return this->Auteur;
}
std::string RessourcesNumeriques::getType()
{
    return this->Type;
}
std::string RessourcesNumeriques::getNomAcces()
{
    return this->NomAcces;
}
int RessourcesNumeriques::getTaille()
{
    return this->Taille;
}

void RessourcesNumeriques::afficheInformation() const
{
    std::cout << "L'auteur est " << this->Auteur << " le type est " << this->Type << " le nom d'accès est " << this->NomAcces << " la taille est " << this->Taille << std::endl;
}

json RessourcesNumeriques::to_json() const
{
    json j;
    j["Type"] = "RessourcesNumeriques";
    j["Auteur"] = this->Auteur;
    j["Types"] = this->Type;
    j["NomAcces"] = this->NomAcces;
    j["Taille"] = this->Taille;
    return j;
}