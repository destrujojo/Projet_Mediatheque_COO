#ifndef RESSOURCES_H
#define RESSOURCES_H

#include <iostream>
#include "../include/json.hpp"
using json = nlohmann::json;

class Ressources
{
public:
  virtual ~Ressources() {}
  virtual void afficheInformation() const = 0;
  virtual json to_json() const = 0;
};

#endif // RESSOURCES_H
