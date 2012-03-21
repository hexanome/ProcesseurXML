#ifndef SERIE_H
#define SERIE_H

#include "ContenuCompose.h"
#include "Element.h"

class Serie : public ContenuCompose {

  public:
    Serie();
    ~Serie();
    string serialize();
    string getName();
    vector<Element*> * getElements();
    void addContenuCompose(ContenuCompose *co);

  protected:
    vector<ContenuCompose*> * contenu;
    string separator;

};

#endif

class Serie;
