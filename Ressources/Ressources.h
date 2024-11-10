#ifndef RESSOURCES_H
#define RESSOURCES_H

#include <iostream>

class Ressources
{
public:
  virtual ~Ressources() {}
  virtual void afficheInformation() const = 0;
};

#endif // RESSOURCES_H
