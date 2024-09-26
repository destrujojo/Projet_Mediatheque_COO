//
// Created by jonathan.roy on 26/09/2024.
//

#include "Revues.h"
#include <iostream>

Revues::Revues(){}

Revues::Revues(std::string Auteur, std::string Collection, std::string Titre, std::string Resumer, std::string Editeur, std::string NomArticle[], int AnneePublication, int NombrePages){
	this->Auteur = Auteur;
    this->Collection = Collection;
    this->Titre = Titre;
    this->Resumer = Resumer;
    this->Editeur = Editeur;
    this->NomArticle = NomArticle;
    this->AnneePublication = AnneePublication;
    this->NombrePages = NombrePages;
}

Revues::~Revues(){}

void Revues::setEditeur(std::string Editeur){
  this->Editeur = Editeur;
}
void Revues::setNomArticle(std::string NomArticle[]){
  this->NomArticle = NomArticle;
}

std::string Revues::getEditeur(){
  return this->Editeur;
}
std::string Revues::getNomArticle(){
  return this->NomArticle;
}

void Revues::afficheInformation(){}



