//
// Created by jonathan.roy on 26/09/2024.
//

#ifndef REVUES_H
#define REVUES_H

#include "../Livres/Livres.h"
#include "../Ressources/Ressources.h"
#include <iostream>
#include <vector>

class Revues : public Livres
{
public:
  Revues();
  Revues(std::string Auteur, std::string Collection, std::string Titre, std::string Resumer, std::string Editeur, std::vector<std::string> NomArticle, int AnneePublication, int NombrePages, int NbArticle);
  ~Revues();
  void setEditeur(std::string Editeur);
  void setNomArticle(std::vector<std::string> NomArticle);
  void setNbArticle(int NbArticle);
  std::string getEditeur();
  std::vector<std::string> getNomArticle();
  int getNbArticle();
  void afficheNomArticle();
  void afficheInformation() override;

private:
  std::string Editeur;
  std::vector<std::string> NomArticle;
  int NbArticle;
};

#endif // REVUES_H
