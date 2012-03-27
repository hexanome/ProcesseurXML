#ifndef DOCTYPE_H
#define DOCTYPE_H

#include "Element.h"

class Doctype {

  public:
    Doctype();
    Doctype(string name);
    ~Doctype();
    void setElements(vector<Element*> * els);
    string getName();

  private:
    string name;
    vector<Element*> *elements;
};

#endif
