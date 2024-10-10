#ifndef RESSOURCESNUMERIQUES_H
#define RESSOURCESNUMERIQUES_H

#include "../Ressources/Ressources.h"
#include <iostream>

class RessourcesNumeriques : public Ressources
{
public:
    RessourcesNumeriques();
    RessourcesNumeriques(std::string Auteur, std::string Type, std::string NomAcces, int Taille);
    ~RessourcesNumeriques();

    void setAuteur(std::string Auteur);
    void setType(std::string Type);
    void setNomAcces(std::string NomAcces);
    void setTaille(int Taille);

    std::string getAuteur();
    std::string getType();
    std::string getNomAcces();
    int getTaille();

    void afficheInformation() override;

private:
    std::string Auteur;
    std::string Type;
    std::string NomAcces;
    int Taille;
};

#endif // RESSOURCESNUMERIQUES_H