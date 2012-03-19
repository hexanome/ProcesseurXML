#ifndef ELEMENT_H
#define ELEMENT_H

#include "ContenuCompose.h"
#include "ContenuMixte.h"

class Element : public ContenuCompose {

  public:
    Element(string name,string category);
    Element(string name,vector<string> elements);
    ~Element();
    string serialize();

  private:
  string name;
  string category;
  vector<Element*> elements;
  vector<ContenuMixte*> contenuMixte;

};

#endif
