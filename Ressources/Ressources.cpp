#include "Ressources.h"

Ressources::Ressources(std::string Auteur, std::string Collection, std::string Titre, std::string Resumer, int AnneePublication, int NombrePages, bool Etat, std::string NomEmprunteur)
{
    this->Auteur = Auteur;
    this->Collection = Collection;
    this->Titre = Titre;
    this->Resumer = Resumer;
    this->AnneePublication = AnneePublication;
    this->NombrePages = NombrePages;
    this->Etat = Etat;
    this->NomEmprunteur = NomEmprunteur;
}

Ressources::Ressources(std::string Auteur, std::string Collection, std::string Titre, std::string Resumer, std::string Editeur, int AnneePublication, int NombrePages, int NbArticles, bool Etat, std::string NomEmprunteur)
{
    this->Auteur = Auteur;
    this->Collection = Collection;
    this->Titre = Titre;
    this->Resumer = Resumer;
    this->Editeur = Editeur;
    this->AnneePublication = AnneePublication;
    this->NombrePages = NombrePages;
    this->NbArticles = NbArticles;
    this->Etat = Etat;
    this->NomEmprunteur = NomEmprunteur;
}

Ressources::Ressources(std::string Auteur, std::string MaisonProduction, float Duree, bool Etat, std::string NomEmprunteur)
{
    this->Auteur = Auteur;
    this->MaisonProduction = MaisonProduction;
    this->Duree = Duree;
    this->Etat = Etat;
    this->NomEmprunteur = NomEmprunteur;
}

Ressources::Ressources(std::string Auteur, std::string MaisonProduction, std::string Titre, float Duree, int NombrePistes, bool Etat, std::string NomEmprunteur)
{
    this->Auteur = Auteur;
    this->MaisonProduction = MaisonProduction;
    this->Titre = Titre;
    this->Duree = Duree;
    this->NombrePistes = NombrePistes;
    this->Etat = Etat;
    this->NomEmprunteur = NomEmprunteur;
}

Ressources::Ressources(std::string Auteur, std::string Type, std::string NomAcces, int Taille, bool Etat, std::string NomEmprunteur)
{
    this->Auteur = Auteur;
    this->Type = Type;
    this->NomAcces = NomAcces;
    this->Taille = Taille;
    this->Etat = Etat;
    this->NomEmprunteur = NomEmprunteur;
}

Ressources::Ressources(std::string Auteur, std::string MaisonProduction, float Duree, int NombrePistes, bool Etat, std::string NomEmprunteur)
{
    this->Auteur = Auteur;
    this->MaisonProduction = MaisonProduction;
    this->Duree = Duree;
    this->NombrePistes = NombrePistes;
    this->Etat = Etat;
    this->NomEmprunteur = NomEmprunteur;
}
