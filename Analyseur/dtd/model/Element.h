#ifndef ELEMENT_H
#define ELEMENT_H

#include "ContenuCompose.h"
#include "ContenuMixte.h"

class Element : public ContenuCompose {

  public:
    Element();
    ~Element();
    string serialize();

  private:
  vector<ContenuMixte*> contenuMixte;

};

#endif
