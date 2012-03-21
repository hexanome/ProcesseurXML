#ifndef ELEMENT_H
#define ELEMENT_H

#include "ContenuCompose.h"
#include "Serie.h"

class Element : public ContenuCompose {

  public:
    Element(string name);
    Element(string name, string cat);
    ~Element();
    void setCategory(string category);
    void setSerie(Serie* s);
	string getName();
	vector<Element*> * getElements();
    string serialize();

  private:
  	string name;
  	string category;
  	Serie* serie;

};

#endif

class Element;
