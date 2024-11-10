#ifndef DVD_H
#define DVD_H

#include <string>
#include "../VHS/VHS.h"

class DVD : public VHS
{
public:
    DVD();
    DVD(std::string Auteur, std::string MaisonProduction, float Duree, int NbPistes);
    ~DVD();

    void setNbPistes(int NbPistes);

    int getNbPistes();

    void afficheInformation() const override;

    json to_json() const override;

private:
    int NbPistes;
};

#endif // DVD_H