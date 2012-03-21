#ifndef SERIE_H
#define SERIE_H

#include "ContenuCompose.h"

class Serie : public ContenuCompose {

  public:
    Serie();
    ~Serie();
    string serialize();
    string getName();
    void addContenuCompose(ContenuCompose *co);

  protected:
  vector<ContenuCompose*> *contenu;
  string separator;

};

#endif
