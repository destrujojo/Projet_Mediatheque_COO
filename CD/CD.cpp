#include "CD.h"
#include <iostream>

CD::CD() {};

CD::CD(std::string Auteur, std::string MaisonProduction, std::string Titre, float Duree, int NombrePistes)
{
  this->Auteur = Auteur;
  this->MaisonProduction = MaisonProduction;
  this->Titre = Titre;
  this->Duree = Duree;
  this->NombrePistes = NombrePistes;
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

std::string CD::getAuteur()
{
  return this->Auteur;
}

std::string CD::getMaisonProduction()
{
  return this->MaisonProduction;
}

std::string CD::getTitre()
{
  return this->Titre;
}

float CD::getDuree()
{
  return this->Duree;
}

int CD::getNombrePistes()
{
  return this->NombrePistes;
}

void CD::afficheInformation() const
{
  std::cout << "L'auteur est " << this->Auteur << " la maison de production est " << this->MaisonProduction << " le titre est " << this->Titre << " la durée est " << this->Duree << " le nombre de pistes est " << this->NombrePistes << std::endl;
}