#ifndef ELEMENT_H
#define ELEMENT_H

#include "ContenuCompose.h"
#include "ContenuMixte.h"

class Element : public ContenuCompose {

  public:
    Element(string name);
    void setCategory(string category);
    void addElement(Element * element);
    void addElements(vector<string> elements);
	string getName();
    ~Element();
    string serialize();

  private:
  string name;
  string category;
  vector<Element*> elements;
  vector<ContenuMixte*> contenuMixte;

};

#endif
