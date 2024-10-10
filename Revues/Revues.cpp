//
// Created by jonathan.roy on 26/09/2024.
//

#include "Revues.h"
#include <iostream>

Revues::Revues() {}

Revues::Revues(std::string Auteur, std::string Collection, std::string Titre, std::string Resumer, std::string Editeur, std::vector<std::string> NomArticle, int AnneePublication, int NombrePages, int NbArticle)
{
  this->Auteur = Auteur;
  this->Collection = Collection;
  this->Titre = Titre;
  this->Resumer = Resumer;
  this->Editeur = Editeur;
  this->NomArticle = NomArticle;
  this->AnneePublication = AnneePublication;
  this->NombrePages = NombrePages;
  this->NbArticle = NbArticle;
}

Revues::~Revues() {}

void Revues::setEditeur(std::string Editeur)
{
  this->Editeur = Editeur;
}
void Revues::setNomArticle(std::vector<std::string> NomArticle)
{
  this->NomArticle = NomArticle;
}
void Revues::setNbArticle(int NbArticle)
{
  this->NbArticle = NbArticle;
}

std::string Revues::getEditeur()
{
  return this->Editeur;
}
std::vector<std::string> Revues::getNomArticle()
{
  return this->NomArticle;
}
int Revues::getNbArticle()
{
  return this->NbArticle;
}

void Revues::afficheInformation()
{
  std::cout << "L'auteur est " << this->Auteur << " la collection est " << this->Collection << " le titre est " << this->Titre << " le resumer est " << this->Resumer << "l'annee depublication est " << this->AnneePublication << " le nombre de pages est " << this->NombrePages << " l'éditeur est " << this->Editeur << "Le nombre d'article est de " << this->NbArticle << std::endl;
}

void Revues::afficheNomArticle()
{
  for (long unsigned int i = 0; i < this->NomArticle.size(); i++)
  {
    std::cout << "Nom de l'article " << i + 1 << " : " << this->NomArticle[i] << std::endl;
  }
}
