#include "Revues.h"
#include <iostream>

Revues::Revues() {}

Revues::Revues(std::string Auteur, std::string Collection, std::string Titre, std::string Resumer, std::string Editeur, int AnneePublication, int NombrePages, int NbArticle, bool Etat, std::string NomEmprunteur) : Livres(Auteur, Collection, Titre, Resumer, AnneePublication, NombrePages, Etat, NomEmprunteur), Editeur(Editeur), NbArticle(NbArticle)
{
  this->Auteur = Auteur;
  this->Collection = Collection;
  this->Titre = Titre;
  this->Resumer = Resumer;
  this->Editeur = Editeur;
  this->AnneePublication = AnneePublication;
  this->NombrePages = NombrePages;
  this->NbArticle = NbArticle;
  this->Etat = Etat;
  this->NomEmprunteur = NomEmprunteur;
}

Revues::~Revues() {}

void Revues::setEditeur(std::string Editeur)
{
  this->Editeur = Editeur;
}

void Revues::setNbArticles(int NbArticle)
{
  this->NbArticle = NbArticle;
}

void Revues::setEtat(bool etat) { this->Etat = etat; };
void Revues::setNomEmprunteur(std::string NomEmprunteur) { this->NomEmprunteur = NomEmprunteur; };

void Revues::afficheInformation() const
{
  std::cout << "L'auteur est " << this->Auteur << " la collection est " << this->Collection << " le titre est " << this->Titre << " le resumer est " << this->Resumer << " l'annee depublication est " << this->AnneePublication << " le nombre de pages est " << this->NombrePages << " l'éditeur est " << this->Editeur << "Le nombre d'article est de " << this->NbArticle << " Etat de l'emprunt " << this->Etat << " Nom de l'emprunteur " << this->NomEmprunteur << std::endl;
}

std::string Revues::getEditeur() const { return this->Editeur; };
std::string Revues::getType() const { return "Revues"; };
bool Revues::getEtat() const { return this->Etat; };
std::string Revues::getNomEmprunteur() const { return this->NomEmprunteur; };

int Revues::getNbArticles() const { return this->NbArticle; };

json Revues::to_json() const
{
  json j;
  j["Type"] = "Revues";
  j["Auteur"] = this->Auteur;
  j["Collection"] = this->Collection;
  j["Titre"] = this->Titre;
  j["Resumer"] = this->Resumer;
  j["Editeur"] = this->Editeur;
  j["AnneePublication"] = this->AnneePublication;
  j["NombrePages"] = this->NombrePages;
  j["NbArticle"] = this->NbArticle;
  j["Etat"] = this->Etat;
  j["NomEmprunteur"] = this->NomEmprunteur;
  return j;
}