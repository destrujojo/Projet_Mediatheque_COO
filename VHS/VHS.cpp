#include "VHS.h"
#include <iostream>

VHS::VHS(std::string Auteur, std::string MaisonProduction, float Duree, bool Etat, std::string NomEmprunteur) : Ressources(Auteur, MaisonProduction, Duree, Etat, NomEmprunteur)
{
  this->Auteur = Auteur;
  this->MaisonProduction = MaisonProduction;
  this->Duree = Duree;
  this->Etat = Etat;
  this->NomEmprunteur = NomEmprunteur;
}

VHS::~VHS() {}

void VHS::setAuteur(std::string Auteur)
{
  this->Auteur = Auteur;
}
void VHS::setMaisonProduction(std::string MaisonProduction)
{
  this->MaisonProduction = MaisonProduction;
}
void VHS::setDuree(float Duree)
{
  this->Duree = Duree;
}

void VHS::setEtat(bool Etat) { this->Etat = Etat; };
void VHS::setNomEmprunteur(std::string NomEmprunteur) { this->NomEmprunteur = NomEmprunteur; };

std::string VHS::getAuteur() const { return this->Auteur; };
std::string VHS::getCollection() const { return ""; };
std::string VHS::getTitre() const { return ""; };
std::string VHS::getResumer() const { return ""; };
std::string VHS::getEditeur() const { return ""; };
std::string VHS::getMaisonProduction() const { return this->MaisonProduction; };
std::string VHS::getTypes() const { return ""; };
std::string VHS::getNomAcces() const { return ""; };
std::string VHS::getType() const { return "VHS"; };

int VHS::getAnneePublication() const { return 0; };
int VHS::getNombrePages() const { return 0; };
int VHS::getTaille() const { return 0; };
int VHS::getNombrePistes() const { return 0; };
int VHS::getNbArticles() const { return 0; };
float VHS::getDuree() const { return this->Duree; };
bool VHS::getEtat() const { return this->Etat; };
std::string VHS::getNomEmprunteur() const { return this->NomEmprunteur; };

// std::string VHS::getAuteur() const
// {
//   return this->Auteur;
// }
// std::string VHS::getMaisonProduction() const
// {
//   return this->MaisonProduction;
// }
// float VHS::getDuree() const
// {
//   return this->Duree;
// }

void VHS::afficheInformation() const
{
  std::cout << "L'auteur est " << this->Auteur << " la maison de production est " << this->MaisonProduction << " la durée est " << this->Duree << " Etat de l'emprunt " << this->Etat << " Nom de l'emprunteur " << this->NomEmprunteur << std::endl;
}

json VHS::to_json() const
{
  json j;
  j["Type"] = "VHS";
  j["Auteur"] = this->Auteur;
  j["MaisonProduction"] = this->MaisonProduction;
  j["Duree"] = this->Duree;
  j["Etat"] = this->Etat;
  j["NomEmprunteur"] = this->NomEmprunteur;
  return j;
}