#include "DVD.h"
#include <iostream>

DVD::DVD() {}

DVD::DVD(std::string Auteur, std::string MaisonProduction, float Duree, int NbPistes)
{
    this->Auteur = Auteur;
    this->MaisonProduction = MaisonProduction;
    this->Duree = Duree;
    this->NbPistes = NbPistes;
}

DVD::~DVD() {}

void DVD::setNbPistes(int NbPistes)
{
    this->NbPistes = NbPistes;
}

int DVD::getNbPistes()
{
    return this->NbPistes;
}

void DVD::afficheInformation() const
{
    std::cout << "L'auteur est " << this->Auteur << " la maison de production est " << this->MaisonProduction << " la durée est " << this->Duree << " le nombre de pistes est " << this->NbPistes << std::endl;
}

json DVD::to_json() const
{
    json j;
    j["Type"] = "DVD";
    j["Auteur"] = this->Auteur;
    j["MaisonProduction"] = this->MaisonProduction;
    j["Duree"] = this->Duree;
    j["NbPistes"] = this->NbPistes;
    return j;
}