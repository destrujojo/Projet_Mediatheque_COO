#include "Livres.h"
#include <iostream>

Livres::Livres() {}

Livres::Livres(std::string Auteur, std::string Collection, std::string Titre, std::string Resumer, int AnneePublication, int NombrePages)
{
  this->Auteur = Auteur;
  this->Collection = Collection;
  this->Titre = Titre;
  this->Resumer = Resumer;
  this->AnneePublication = AnneePublication;
  this->NombrePages = NombrePages;
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

// Getter de la classe Livres
std::string Livres::getAuteur()
{
  return this->Auteur;
}

std::string Livres::getCollection()
{
  return this->Collection;
}
std::string Livres::getTitre()
{
  return this->Titre;
}
std::string Livres::getResumer()
{
  return this->Resumer;
}
int Livres::getAnneePublication()
{
  return this->AnneePublication;
}
int Livres::getNombrePages()
{
  return this->NombrePages;
}

// fonction d'affichage de toute les données de la classe Livres
void Livres::afficheInformation()
{
  std::cout << "L'auteur est " << this->Auteur << " la collection est " << this->Collection << " le titre est " << this->Titre << " le resumer est " << this->Resumer << "l'annee depublication est " << this->AnneePublication << " le nombre de pages est " << this->NombrePages << std::endl;
}
