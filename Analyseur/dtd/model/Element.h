#ifndef ELEMENT_H
#define ELEMENT_H

#include "ContenuCompose.h"
#include "Serie.h"
#include "Attribut.h"

class Element : public ContenuCompose {

  public:
    Element(string name);
    Element(string name, string cat);
    ~Element();
    void setCategory(string category);
    void setSerie(Serie* s);
    void setMixed(vector<string> * m);
    void addAttribut(Attribut *a);
    void addMixed(string mixed);
    vector<Attribut*> * getAttributs();
    string getName();
    vector<Element*> * getElements();
    vector<string> * getMixed();
    string serialize();

  private:
    string name;
    string category;
    Serie* serie;
    vector<Attribut*> * attributs;
    vector<string> * mixed;
    

};

#endif

class Element;

