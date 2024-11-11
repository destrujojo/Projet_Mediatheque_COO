#include "DVD.h"
#include <iostream>

DVD::DVD() {}

DVD::DVD(std::string Auteur, std::string MaisonProduction, float Duree, int NbPistes, bool Etat, std::string NomEmprunteur) : VHS(Auteur, MaisonProduction, Duree, Etat, NomEmprunteur)
{
    this->Auteur = Auteur;
    this->MaisonProduction = MaisonProduction;
    this->Duree = Duree;
    this->NbPistes = NbPistes;
    this->Etat = Etat;
    this->NomEmprunteur = NomEmprunteur;
}

DVD::~DVD() {}

void DVD::setNbPistes(int NbPistes)
{
    this->NbPistes = NbPistes;
}

void DVD::setEtat(bool Etat) { this->Etat = Etat; };
void DVD::setNomEmprunteur(std::string NomEmprunteur) { this->NomEmprunteur = NomEmprunteur; };

std::string DVD::getType() const { return "VHS"; };
int DVD::getNombrePistes() const { return this->NbPistes; };
bool DVD::getEtat() const { return this->Etat; };
std::string DVD::getNomEmprunteur() const { return this->NomEmprunteur; };

// int DVD::getNombrePistes() const
// {
//     return this->NbPistes;
// }

void DVD::afficheInformation() const
{
    std::cout << "L'auteur est " << this->Auteur << " la maison de production est " << this->MaisonProduction << " la durée est " << this->Duree << " le nombre de pistes est " << this->NbPistes << " Etat de l'emprunt " << this->Etat << " Nom de l'emprunteur " << this->NomEmprunteur << std::endl;
}

json DVD::to_json() const
{
    json j;
    j["Type"] = "DVD";
    j["Auteur"] = this->Auteur;
    j["MaisonProduction"] = this->MaisonProduction;
    j["Duree"] = this->Duree;
    j["NbPistes"] = this->NbPistes;
    j["Etat"] = this->Etat;
    j["NomEmprunteur"] = this->NomEmprunteur;
    return j;
}