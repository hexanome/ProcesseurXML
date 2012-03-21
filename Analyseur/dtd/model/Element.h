#ifndef ELEMENT_H
#define ELEMENT_H

#include "Serie.h"
#include "Attribut.h"

class Element : public ContenuCompose {

  public:
    Element(string name);
    Element(string name, string cat);
    ~Element();
    void setCategory(string category);
    void setSerie(Serie* s);
    void addAttribut(Attribut *a);
    vector<Attribut*> *getAttribut();
	string getName();
    string serialize();

  private:
  	string name;
  	string category;
  	Serie* serie;
    vector<Attribut*> *attribut;
    

};

#endif
