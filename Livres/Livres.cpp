#include "Livres.h"
#include <iostream>

Livres::Livres() {}

Livres::Livres(std::string Auteur, std::string Collection, std::string Titre, std::string Resumer, int AnneePublication, int NombrePages, bool Etat, std::string NomEmprunteur) : Ressources(Auteur, Collection, Titre, Resumer, AnneePublication, NombrePages, Etat, NomEmprunteur)
{
  this->Auteur = Auteur;
  this->Collection = Collection;
  this->Titre = Titre;
  this->Resumer = Resumer;
  this->AnneePublication = AnneePublication;
  this->NombrePages = NombrePages;
  this->Etat = Etat;
  this->NomEmprunteur = NomEmprunteur;
}

Livres::~Livres() {}

// Setter de la classe Livres
void Livres::setAuteur(std::string Auteur)
{
  this->Auteur = Auteur;
}

void Livres::setCollection(std::string Collection)
{
  this->Collection = Collection;
}

void Livres::setTitre(std::string Titre)
{
  this->Titre = Titre;
}

void Livres::setResumer(std::string Resumer)
{
  this->Resumer = Resumer;
}

void Livres::setAnneePublication(int AnneePublication)
{
  this->AnneePublication = AnneePublication;
}

void Livres::setNombrePages(int NombrePages)
{
  this->NombrePages = NombrePages;
}

void Livres::setEtat(bool Etat) { this->Etat = Etat; };
void Livres::setNomEmprunteur(std::string NomEmprunteur) { this->NomEmprunteur = NomEmprunteur; };

std::string Livres::getAuteur() const { return this->Auteur; };
std::string Livres::getCollection() const { return this->Collection; };
std::string Livres::getTitre() const { return this->Titre; };
std::string Livres::getResumer() const { return this->Resumer; };
std::string Livres::getEditeur() const { return ""; };
std::string Livres::getMaisonProduction() const { return ""; };
std::string Livres::getTypes() const { return ""; };
std::string Livres::getNomAcces() const { return ""; };
std::string Livres::getType() const { return "Livres"; };

int Livres::getAnneePublication() const { return this->AnneePublication; };
int Livres::getNombrePages() const { return this->NombrePages; };
int Livres::getTaille() const { return 0; };
int Livres::getNombrePistes() const { return 0; };
int Livres::getNbArticles() const { return 0; };
float Livres::getDuree() const { return 0; };
bool Livres::getEtat() const { return this->Etat; };
std::string Livres::getNomEmprunteur() const { return this->NomEmprunteur; };

// Getter de la classe Livres
// std::string Livres::getAuteur() const
// {
//   return this->Auteur;
// }

// std::string Livres::getCollection() const
// {
//   return this->Collection;
// }
// std::string Livres::getTitre() const
// {
//   return this->Titre;
// }
// std::string Livres::getResumer() const
// {
//   return this->Resumer;
// }
// int Livres::getAnneePublication() const
// {
//   return this->AnneePublication;
// }
// int Livres::getNombrePages() const
// {
//   return this->NombrePages;
// }

// fonction d'affichage de toute les données de la classe Livres
void Livres::afficheInformation() const
{
  std::cout << "L'auteur est " << this->Auteur << " la collection est " << this->Collection << " le titre est " << this->Titre << " le resumer est " << this->Resumer << " l'annee depublication est " << this->AnneePublication << " le nombre de pages est " << this->NombrePages << " Etat de l'emprunt " << this->Etat << " Nom de l'emprunteur " << this->NomEmprunteur << std::endl;
}

// fonction de conversion de la classe Livres en json
json Livres::to_json() const
{
  json j;
  j["Type"] = "Livres";
  j["Auteur"] = this->Auteur;
  j["Collection"] = this->Collection;
  j["Titre"] = this->Titre;
  j["Resumer"] = this->Resumer;
  j["AnneePublication"] = this->AnneePublication;
  j["NombrePages"] = this->NombrePages;
  j["Etat"] = this->Etat;
  j["NomEmprunteur"] = this->NomEmprunteur;
  return j;
}