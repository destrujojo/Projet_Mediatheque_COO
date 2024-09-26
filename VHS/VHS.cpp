//
// Created by jonathan.roy on 26/09/2024.
//

#include "VHS.h"
#include <iostream>

VHS::VHS(std::string Auteur, std::string MaisonProduction, float Duree){
    this->Auteur = Auteur;
    this->MaisonProduction = MaisonProduction;
    this->Duree = Duree;
}

VHS::~VHS(){}

void VHS::setAuteur(std::string Auteur){
  this->Auteur = Auteur;
}
void VHS::setMaisonProduction(std::string MaisonProduction){
  this->MaisonProduction = MaisonProduction;
}
void VHS::setDuree(float Duree){
  this->Duree = Duree;
}

std::string VHS::getAuteur(){
  return this->Auteur;
}
std::string VHS::getMaisonProduction(){
  this->MaisonProduction = this->MaisonProduction;
}
std::string VHS::getDuree(){
  return this->Duree;
}
