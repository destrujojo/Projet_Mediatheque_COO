#include "CD.h"
#include <iostream>

CD::CD() {};

CD::CD(std::string Auteur, std::string MaisonProduction, std::string Titre, float Duree, int NombrePistes, bool Etat, std::string NomEmprunteur) : Ressources(Auteur, MaisonProduction, Titre, Duree, NombrePistes, Etat, NomEmprunteur)
{
  this->Auteur = Auteur;
  this->MaisonProduction = MaisonProduction;
  this->Titre = Titre;
  this->Duree = Duree;
  this->NombrePistes = NombrePistes;
  this->Etat = Etat;
  this->NomEmprunteur = NomEmprunteur;
};

CD::~CD() {};

void CD::setAuteur(std::string Auteur)
{
  this->Auteur = Auteur;
}

void CD::setMaisonProduction(std::string MaisonProduction)
{
  this->MaisonProduction = MaisonProduction;
}

void CD::setTitre(std::string Titre)
{
  this->Titre = Titre;
}

void CD::setDuree(float Duree)
{
  this->Duree = Duree;
}

void CD::setNombrePistes(int NombrePistes)
{
  this->NombrePistes = NombrePistes;
}

void CD::setEtat(bool Etat) { this->Etat = Etat; };
void CD::setNomEmprunteur(std::string NomEmprunteur) { this->NomEmprunteur = NomEmprunteur; };

std::string CD::getAuteur() const { return this->Auteur; };
std::string CD::getCollection() const { return ""; };
std::string CD::getTitre() const { return this->Titre; };
std::string CD::getResumer() const { return ""; };
std::string CD::getEditeur() const { return ""; };
std::string CD::getMaisonProduction() const { return this->MaisonProduction; };
std::string CD::getTypes() const { return ""; };
std::string CD::getNomAcces() const { return ""; };
std::string CD::getType() const { return "CD"; };

int CD::getAnneePublication() const { return 0; };
int CD::getNombrePages() const { return 0; };
int CD::getTaille() const { return 0; };
int CD::getNombrePistes() const { return this->NombrePistes; };
int CD::getNbArticles() const { return 0; };
float CD::getDuree() const { return this->Duree; };

bool CD::getEtat() const { return this->Etat; };
std::string CD::getNomEmprunteur() const { return this->NomEmprunteur; };

// std::string CD::getAuteur() const
// {
//   return this->Auteur;
// }

// std::string CD::getMaisonProduction() const
// {
//   return this->MaisonProduction;
// }

// std::string CD::getTitre() const
// {
//   return this->Titre;
// }

// float CD::getDuree() const
// {
//   return this->Duree;
// }

// int CD::getNombrePistes() const
// {
//   return this->NombrePistes;
// }

void CD::afficheInformation() const
{
  std::cout << "L'auteur est " << this->Auteur << " la maison de production est " << this->MaisonProduction << " le titre est " << this->Titre << " la durée est " << this->Duree << " le nombre de pistes est " << this->NombrePistes << " Etat de l'emprunt " << this->Etat << " Nom de l'emprunteur " << this->NomEmprunteur << std::endl;
}

json CD::to_json() const
{
  json j;
  j["Type"] = "CD";
  j["Auteur"] = this->Auteur;
  j["MaisonProduction"] = this->MaisonProduction;
  j["Titre"] = this->Titre;
  j["Duree"] = this->Duree;
  j["NombrePistes"] = this->NombrePistes;
  j["Etat"] = this->Etat;
  j["NomEmprunteur"] = this->NomEmprunteur;
  return j;
}