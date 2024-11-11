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
  Revues(std::string Auteur, std::string Collection, std::string Titre, std::string Resumer, std::string Editeur, int AnneePublication, int NombrePages, int NbArticle, bool Etat, std::string NomEmprunteur);
  ~Revues();
  void setEditeur(std::string Editeur);
  void setNbArticles(int NbArticle);
  void setEtat(bool etat) override;
  void setNomEmprunteur(std::string NomEmprunteur) override;

  std::string getEditeur() const override;
  std::string getType() const override;
  int getNbArticles() const override;
  bool getEtat() const override;
  std::string getNomEmprunteur() const override;

  void afficheInformation() const override;
  json to_json() const override;

private:
  std::string Editeur;
  int NbArticle;
};

#endif // REVUES_H
