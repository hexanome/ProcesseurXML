#ifndef DOCTYPE_H
#define DOCTYPE_H

#include "../../includes/common.h"
#include "Element.h"

class Doctype {

  public:
    Doctype();
    Doctype(string name);
    ~Doctype();
    void addElement(Element * e);
    void setElements(vector<Element*> * els);
    vector<Element*> * getElements();
    Element * getElementByName(string name);
    string getName();
    string serialize();

  private:
    string name;
    vector<Element*> *elements;
};

#endif
