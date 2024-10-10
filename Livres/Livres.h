//
// Created by jonathan.roy on 26/09/2024.
//
#ifndef LIVRES_H
#define LIVRES_H

#include "../Ressources/Ressources.h"
#include <iostream>

class Livres : public Ressources{
    public:
      Livres();
      Livres(std::string Auteur, std::string Collection, std::string Titre, std::string Resumer, int AnneePublication, int NombrePages);
      ~Livres();
      void setAuteur(std::string Auteur);
      void setCollection(std::string Collection);
      void setTitre(std::string Titre);
      void setResumer(std::string Resumer);
      void setAnneePublication(int AnneePublication);
      void setNombrePages(int NombrePages);
      std::string getAuteur();
      std::string getCollection();
      std::string getTitre();
      std::string getResumer();
      int getAnneePublication();
      int getNombrePages();
      void afficheInformation() override;

  protected:
      std::string Auteur;
      std::string Collection;
      std::string Titre;
      std::string Resumer;
      int AnneePublication;
      int NombrePages;
};
#endif //LIVRES_H
