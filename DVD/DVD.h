#ifndef DVD_H
#define DVD_H

#include <string>
#include "../VHS/VHS.h"

class DVD : public VHS
{
public:
    DVD();
    DVD(std::string Auteur, std::string MaisonProduction, float Duree, int NbPistes, bool Etat, std::string NomEmprunteur);
    ~DVD();

    void setNbPistes(int NbPistes);
    void setEtat(bool Etat) override;
    void setNomEmprunteur(std::string NomEmprunteur) override;

    std::string getType() const override;
    int getNombrePistes() const override;
    bool getEtat() const override;
    std::string getNomEmprunteur() const override;

    void afficheInformation() const override;

    json to_json() const override;

private:
    int NbPistes;
};

#endif // DVD_H