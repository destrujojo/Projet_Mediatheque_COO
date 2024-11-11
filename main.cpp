#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include "Ressources/Ressources.h"
#include "Livres/Livres.h"
#include "Revues/Revues.h"
#include "VHS/VHS.h"
#include "CD/CD.h"
#include "DVD/DVD.h"
#include "RessourcesNumeriques/RessourcesNumeriques.h"
#include "json.hpp"

using json = nlohmann::json;

bool supprimerRessourceParPosition(size_t position, std::vector<Ressources *> &ressources)
{
    position -= 1;
    if (position >= ressources.size())
    {
        std::cout << "Position invalide." << std::endl;
        return false;
    }

    delete ressources[position];                     // Libère la mémoire de la ressource
    ressources.erase(ressources.begin() + position); // Supprime la ressource du vecteur
    std::cout << "Ressource supprimée avec succès." << std::endl;
    return true;
}

void emprunterRessourceParPosition(size_t position, std::vector<Ressources *> &ressources, const std::string &nomEmprunteur)
{
    position -= 1;
    if (position >= ressources.size())
    {
        std::cout << "Position invalide." << std::endl;
        return;
    }

    if (ressources[position]->getEtat())
    {
        std::cout << "Ressource déjà empruntée par " << ressources[position]->getNomEmprunteur() << std::endl;
        return;
    }

    if (ressources[position]->getNomEmprunteur() == "Reserv")
    {
        std::cout << "La resource est réserver" << std::endl;
        return;
    }

    ressources[position]->setEtat(true);
    ressources[position]->setNomEmprunteur(nomEmprunteur);
    std::cout << "Ressource empruntée avec succès." << std::endl;
}

void deposerRessourceParPosition(size_t position, std::vector<Ressources *> &ressources)
{
    position -= 1;
    if (position >= ressources.size())
    {
        std::cout << "Position invalide." << std::endl;
        return;
    }

    ressources[position]->setEtat(false);
    ressources[position]->setNomEmprunteur("");
    std::cout << "Ressource déposée avec succès." << std::endl;
}

void sauvegarderRessources(const std::vector<Ressources *> &ressources, const std::string &nomFichier)
{
    json jsonArray = json::array(); // Tableau JSON pour stocker chaque ressource

    for (const Ressources *ressource : ressources)
    {
        jsonArray.push_back(ressource->to_json()); // Appel de la méthode to_json() pour chaque ressource
    }

    std::ofstream fichier(nomFichier); // Ouvrir le fichier pour écrire le JSON
    fichier << jsonArray.dump(4);      // Sauvegarder avec indentation pour lecture aisée
    fichier.close();
}

void chargerRessources(std::vector<Ressources *> &ressources, const std::string &nomFichier)
{
    std::ifstream fichier(nomFichier);
    if (!fichier.is_open())
    {
        std::cerr << "Erreur: Impossible d'ouvrir le fichier " << nomFichier << std::endl;
        return;
    }

    json jsonArray;
    fichier >> jsonArray; // Lire le contenu du fichier JSON
    fichier.close();

    for (const auto &jsonRessource : jsonArray)
    {
        std::string type = jsonRessource.at("Type");

        if (type == "Livres")
        {
            ressources.push_back(new Livres(
                jsonRessource.at("Auteur"),
                jsonRessource.at("Collection"),
                jsonRessource.at("Titre"),
                jsonRessource.at("Resumer"),
                jsonRessource.at("AnneePublication"),
                jsonRessource.at("NombrePages"),
                jsonRessource.at("Etat"),
                jsonRessource.at("NomEmprunteur")));
        }
        else if (type == "Revues")
        {
            ressources.push_back(new Revues(
                jsonRessource.at("Auteur"),
                jsonRessource.at("Collection"),
                jsonRessource.at("Titre"),
                jsonRessource.at("Resumer"),
                jsonRessource.at("Editeur"),
                jsonRessource.at("AnneePublication"),
                jsonRessource.at("NombrePages"),
                jsonRessource.at("NbArticles"),
                jsonRessource.at("Etat"),
                jsonRessource.at("NomEmprunteur")));
        }
        else if (type == "VHS")
        {
            ressources.push_back(new VHS(
                jsonRessource.at("Auteur"),
                jsonRessource.at("MaisonProduction"),
                jsonRessource.at("Duree"),
                jsonRessource.at("Etat"),
                jsonRessource.at("NomEmprunteur")));
        }
        else if (type == "CD")
        {
            ressources.push_back(new CD(
                jsonRessource.at("Auteur"),
                jsonRessource.at("MaisonProduction"),
                jsonRessource.at("Titre"),
                jsonRessource.at("Duree"),
                jsonRessource.at("NbPistes"),
                jsonRessource.at("Etat"),
                jsonRessource.at("NomEmprunteur")));
        }
        else if (type == "DVD")
        {
            ressources.push_back(new DVD(
                jsonRessource.at("Auteur"),
                jsonRessource.at("MaisonProduction"),
                jsonRessource.at("Duree"),
                jsonRessource.at("NbPistes"),
                jsonRessource.at("Etat"),
                jsonRessource.at("NomEmprunteur")));
        }
        else if (type == "RessourcesNumeriques")
        {
            ressources.push_back(new RessourcesNumeriques(
                jsonRessource.at("Auteur"),
                jsonRessource.at("Types"),
                jsonRessource.at("NomAcces"),
                jsonRessource.at("Taille"),
                jsonRessource.at("Etat"),
                jsonRessource.at("NomEmprunteur")));
        }
        else
        {
            std::cerr << "Erreur: Type de ressource inconnu dans le fichier JSON" << std::endl;
        }
    }
}

std::vector<Ressources *> rechercherRessources(const std::vector<Ressources *> &ressources, const std::string &critere, const std::string &valeur)
{
    std::vector<Ressources *> resultats;

    for (const auto &ressource : ressources)
    {
        bool correspondance = false;

        // Comparaison selon le critère
        if (critere == "Titre")
        {
            correspondance = ressource->getTitre().find(valeur) != std::string::npos;
        }
        else if (critere == "Auteur")
        {
            correspondance = ressource->getAuteur().find(valeur) != std::string::npos;
        }
        else if (critere == "Collection")
        {
            correspondance = ressource->getCollection().find(valeur) != std::string::npos;
        }
        else if (critere == "Editeur")
        {
            correspondance = ressource->getEditeur().find(valeur) != std::string::npos;
        }
        else if (critere == "MaisonProduction")
        {
            correspondance = ressource->getMaisonProduction().find(valeur) != std::string::npos;
        }
        else if (critere == "Type")
        {
            correspondance = ressource->getType().find(valeur) != std::string::npos;
        }
        else if (critere == "NomAcces")
        {
            correspondance = ressource->getNomAcces().find(valeur) != std::string::npos;
        }
        else if (critere == "AnneePublication")
        {
            correspondance = std::to_string(ressource->getAnneePublication()).find(valeur) != std::string::npos;
        }
        else if (critere == "NombrePages")
        {
            correspondance = std::to_string(ressource->getNombrePages()).find(valeur) != std::string::npos;
        }
        else if (critere == "NbArticles")
        {
            correspondance = std::to_string(ressource->getNbArticles()).find(valeur) != std::string::npos;
        }
        else if (critere == "Duree")
        {
            correspondance = std::to_string(ressource->getDuree()).find(valeur) != std::string::npos;
        }
        else if (critere == "NombrePistes")
        {
            correspondance = std::to_string(ressource->getNombrePistes()).find(valeur) != std::string::npos;
        }
        else if (critere == "Taille")
        {
            correspondance = std::to_string(ressource->getTaille()).find(valeur) != std::string::npos;
        }

        if (correspondance)
        {
            resultats.push_back(ressource);
        }
    }

    return resultats;
}

int main()
{
    std::vector<Ressources *> ressources;
    std::vector<Ressources *> resultatsActuels;

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
            << "RES - Réserver Média" << std::endl
            << "EMP - Emprunter un Média" << std::endl
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

                ressources.push_back(new Livres(Auteur, Collection, Titre, Resumer, Annee, NbPages, false, ""));
            }
            else if (type == "Revues")
            {
                std::string Titre;
                std::string Auteur;
                std::string Resumer;
                std::string Collection;
                std::string Editeur;
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

                ressources.push_back(new Revues(Auteur, Collection, Titre, Resumer, Editeur, Annee, NbPages, NbArticles, false, ""));
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

                ressources.push_back(new VHS(Auteur, MaisonProduction, Duree, false, ""));
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

                ressources.push_back(new CD(Auteur, MaisonProduction, Titre, Duree, NombrePistes, false, ""));
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

                ressources.push_back(new DVD(Auteur, MaisonProduction, Duree, NbPistes, false, ""));
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

                ressources.push_back(new RessourcesNumeriques(Auteur, type, NomAcces, Taille, false, ""));
            }
            else
            {
                std::cout << "Type de ressource inconnu" << std::endl;
            }
        }

        if (input.substr(0, 3) == "SUP")
        {
            size_t position = std::stoi(input.substr(4));
            supprimerRessourceParPosition(position, ressources);
        }

        if (input.substr(0, 3) == "EMP")
        {
            size_t position = std::stoi(input.substr(4));
            std::cout << position << std::endl;
            std::string nomEmprunteur;
            std::cout << "Entrez le nom de l'emprunteur : ";
            std::getline(std::cin, nomEmprunteur);
            emprunterRessourceParPosition(position, ressources, nomEmprunteur);
        }

        if (input.substr(0, 3) == "RES")
        {
            size_t position = std::stoi(input.substr(4));
            std::string nomEmprunteur = "Reserv";
            emprunterRessourceParPosition(position, ressources, nomEmprunteur);
        }

        if (input.substr(0, 4) == "DEPO")
        {
            size_t position = std::stoi(input.substr(5));
            deposerRessourceParPosition(position, ressources);
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

        if (input == "SAV")
        {
            sauvegarderRessources(ressources, "ressources.json");
            std::cout << "Ressources sauvegardées dans ressources.json" << std::endl;
        }

        if (input == "CHARGE")
        {
            chargerRessources(ressources, "ressources.json");
            std::cout << "Les ressources ont été chargées à partir de ressources.json" << std::endl;
        }

        if (input == "SEARCH")
        {
            std::cout << "Entrez le critère de recherche (Titre, Auteur, etc.): ";
            std::string critere;
            std::getline(std::cin, critere);

            std::cout << "Entrez la valeur à rechercher : ";
            std::string valeur;
            std::getline(std::cin, valeur);

            // Effectuer la recherche sur les résultats actuels pour permettre la recherche incrémentale
            resultatsActuels = rechercherRessources(resultatsActuels, critere, valeur);

            // Affichage des résultats de recherche
            std::cout << "Résultats de la recherche : " << std::endl;
            for (const auto &ressource : resultatsActuels)
            {
                std::cout << ressource->getTitre() << std::endl;
                ressource->afficheInformation();
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
