#ifndef DOCTYPE_H
#define DOCTYPE_H

#include "Element.h"

class Doctype {

  public:
    Doctype();
    Doctype(string name);
    ~Doctype();
    string getName();

  private:
    string name;
    vector<Element*> *elements;
};

#endif
