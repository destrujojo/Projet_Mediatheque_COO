//
// Created by jonathan.roy on 26/09/2024.
//

#ifndef REVUES_H
#define REVUES_H

#include "../Livres/Livres.h"
#include "../Ressources/Ressources.h"
#include <iostream>

class Revues : public Livres {
    public:
      Revues();
      Revues(std::string Auteur, std::string Collection, std::string Titre, std::string Resumer, std::string Editeur, std::string NomArticle[], int AnneePublication, int NombrePages);
      ~Revues();
      void setEditeur(std::string Editeur);
      void setNomArticle(std::string NomArticle[]);
      std::string getEditeur();
      std::string getNomArticle();

    private:
      std::string Editeur;
      std::string NomArticle[];
};

#endif //REVUES_H
