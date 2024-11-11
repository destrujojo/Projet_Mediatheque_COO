#ifndef RESSOURCES_H
#define RESSOURCES_H

#include <iostream>
#include "../include/json.hpp"
using json = nlohmann::json;

class Ressources
{
public:
  virtual ~Ressources() {}
  Ressources() {}
  Ressources(std::string Auteur, std::string Collection, std::string Titre, std::string Resumer, int AnneePublication, int NombrePages, bool Etat, std::string NomEmprunteur);
  Ressources(std::string Auteur, std::string Collection, std::string Titre, std::string Resumer, std::string Editeur, int AnneePublication, int NombrePages, int NbArticles, bool Etat, std::string NomEmprunteur);
  Ressources(std::string Auteur, std::string MaisonProduction, float Duree, bool Etat, std::string NomEmprunteur);
  Ressources(std::string Auteur, std::string MaisonProduction, std::string Titre, float Duree, int NombrePistes, bool Etat, std::string NomEmprunteur);
  Ressources(std::string Auteur, std::string Type, std::string NomAcces, int Taille, bool Etat, std::string NomEmprunteur);
  Ressources(std::string Auteur, std::string MaisonProduction, float Duree, int NbPistes, bool Etat, std::string NomEmprunteur);

  virtual void afficheInformation() const = 0;
  virtual json to_json() const = 0;

  virtual std::string getTitre() const = 0;
  virtual std::string getAuteur() const = 0;
  virtual std::string getResumer() const = 0;
  virtual std::string getCollection() const = 0;
  virtual std::string getEditeur() const = 0;
  virtual std::string getMaisonProduction() const = 0;
  virtual std::string getTypes() const = 0;
  virtual std::string getNomAcces() const = 0;
  virtual std::string getType() const = 0;
  virtual int getAnneePublication() const = 0;
  virtual int getNombrePages() const = 0;
  virtual int getTaille() const = 0;
  virtual int getNombrePistes() const = 0;
  virtual int getNbArticles() const = 0;
  virtual float getDuree() const = 0;

  virtual void setEtat(bool etat) = 0;
  virtual void setNomEmprunteur(std::string NomEmprunteur) = 0;
  virtual bool getEtat() const = 0;
  virtual std::string getNomEmprunteur() const = 0;

private:
  std::string Auteur;
  std::string Collection;
  std::string Titre;
  std::string Resumer;
  std::string Editeur;
  std::string MaisonProduction;
  std::string Type;
  std::string NomAcces;
  int AnneePublication;
  int NombrePages;
  int Taille;
  int NombrePistes;
  int NbArticles;
  float Duree;
  bool Etat;
  std::string NomEmprunteur;
};

#endif // RESSOURCES_H
