#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include "ContenuCompose.h"
#include "Attribut.h"

class Definitions {

  public:
    Definitions();
    ~Definitions();

  private:
  ContenuCompose *contenuCompose;
  vector<Attribut> *attributs;


};

#endif
