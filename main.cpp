#include <iostream>
#include <vector>
#include "Ressources/Ressources.h"
#include "Livres/Livres.h"
#include "Revues/Revues.h"
#include "VHS/VHS.h"
#include "CD/CD.h"
#include "DVD/DVD.h"
#include "RessourcesNumeriques/RessourcesNumeriques.h"

int main()
{
    std::vector<Ressources *> ressources;

    while (1)
    {
        std::cout
            << std::endl
            << "ADD - Ajout Média" << std::endl
            << "SUP - SUPPRIMER Média" << std::endl
            << "LIST - Lister les Médias" << std::endl
            << "SAV - Sauvegarde les Médias" << std::endl
            << "CHARGE - Charge les Médias" << std::endl
            << "SEARCH - Recherche Média" << std::endl
            << "RESERV - Réserver Média" << std::endl
            << "EMPRUNT - Emprunter un Média" << std::endl
            << "DEPO - Rendre Média" << std::endl
            << "BYE - Quitter" << std::endl;
        std::string input;
        std::getline(std::cin, input);

        if (input.substr(0, 3) == "ADD")
        {
            std::string type = input.substr(4);
            std::cout << "Type de ressource: " << type << std::endl;

            if (type == "Livres")
            {
                std::string Titre;
                std::string Auteur;
                std::string Resumer;
                std::string Collection;
                int Annee;
                int NbPages;

                std::cout << "Entrer le Titre: ";
                std::getline(std::cin, Titre);
                std::cout << "Entrer l'Auteur: ";
                std::getline(std::cin, Auteur);
                std::cout << "Entrer le Resumer: ";
                std::getline(std::cin, Resumer);
                std::cout << "Entrer la Collection: ";
                std::getline(std::cin, Collection);
                std::cout << "Entrer l'Annee: ";
                std::cin >> Annee;
                std::cout << "Entrer le Nombre de Pages: ";
                std::cin >> NbPages;

                ressources.push_back(new Livres(Titre, Auteur, Resumer, Collection, Annee, NbPages));
            }
            else if (type == "Revues")
            {
                std::string Titre;
                std::string Auteur;
                std::string Resumer;
                std::string Collection;
                std::string Editeur;
                std::vector<std::string> Articles;
                int Annee;
                int NbPages;
                int NbArticles;

                std::cout << "Entrer le Titre: ";
                std::getline(std::cin, Titre);
                std::cout << "Entrer l'Auteur: ";
                std::getline(std::cin, Auteur);
                std::cout << "Entrer le Resumer: ";
                std::getline(std::cin, Resumer);
                std::cout << "Entrer la Collection: ";
                std::getline(std::cin, Collection);
                std::cout << "Entrer l'Editeur: ";
                std::getline(std::cin, Editeur);
                std::cout << "Entrer l'Annee: ";
                std::cin >> Annee;
                std::cout << "Entrer le Nombre de Pages: ";
                std::cin >> NbPages;
                std::cout << "Entrer le Nombre d'Articles: ";
                std::cin >> NbArticles;

                ressources.push_back(new Revues(Titre, Auteur, Resumer, Collection, Editeur, Articles, Annee, NbPages, NbArticles));
            }
            else if (type == "VHS")
            {
                std::string Auteur;
                std::string MaisonProduction;
                float Duree;

                std::cout << "Entrer l'Auteur: ";
                std::getline(std::cin, Auteur);
                std::cout << "Entrer la Maison de Production: ";
                std::getline(std::cin, MaisonProduction);
                std::cout << "Entrer la Duree: ";
                std::cin >> Duree;

                ressources.push_back(new VHS(Auteur, MaisonProduction, Duree));
            }
            else if (type == "CD")
            {
                std::string Auteur;
                std::string MaisonProduction;
                std::string Titre;
                float Duree;
                int NombrePistes;

                std::cout << "Entrer l'Auteur: ";
                std::getline(std::cin, Auteur);
                std::cout << "Entrer la Maison de Production: ";
                std::getline(std::cin, MaisonProduction);
                std::cout << "Entrer le Titre: ";
                std::getline(std::cin, Titre);
                std::cout << "Entrer la Duree: ";
                std::cin >> Duree;
                std::cout << "Entrer le Nombre de Pistes: ";
                std::cin >> NombrePistes;

                ressources.push_back(new CD(Auteur, MaisonProduction, Titre, Duree, NombrePistes));
            }
            else if (type == "DVD")
            {
                std::string Auteur;
                std::string MaisonProduction;
                float Duree;
                int NbPistes;

                std::cout << "Entrer l'Auteur: ";
                std::getline(std::cin, Auteur);
                std::cout << "Entrer la Maison de Production: ";
                std::getline(std::cin, MaisonProduction);
                std::cout << "Entrer la Duree: ";
                std::cin >> Duree;
                std::cout << "Entrer le Nombre de Pistes: ";
                std::cin >> NbPistes;

                ressources.push_back(new DVD(Auteur, MaisonProduction, Duree, NbPistes));
            }
            else if (type == "RessourcesNumeriques")
            {
                std::string Auteur;
                std::string type;
                std::string NomAcces;
                int Taille;

                std::cout << "Entrer l'Auteur: ";
                std::getline(std::cin, Auteur);
                std::cout << "Entrer le Type: ";
                std::getline(std::cin, type);
                std::cout << "Entrer le Nom d'Acces: ";
                std::getline(std::cin, NomAcces);
                std::cout << "Entrer la Taille: ";
                std::cin >> Taille;

                ressources.push_back(new RessourcesNumeriques(Auteur, type, NomAcces, Taille));
            }
            else
            {
                std::cout << "Type de ressource inconnu" << std::endl;
            }
        }

        if (input == "LIST")
        {
            std::cout << "Liste des Médias:\n";
            for (const auto *ressource : ressources)
            {
                ressource->afficheInformation();
                std::cout << "-----------------------------\n";
            }
        }

        if (input == "BYE")
        {
            break;
        }
    }

    for (auto *ressource : ressources)
    {
        delete ressource;
    }

    return 0;
}
