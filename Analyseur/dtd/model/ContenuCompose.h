#ifndef CONTENUCOMPOSE_H
#define CONTENUCOMPOSE_H

#include "../../includes/common.h"

class ContenuCompose {

  public:
    virtual string serialize() = 0 ;
    virtual string getName() = 0 ;
    void setCardinalite(string card);
        
  protected:
    string cardinalite;
};

#endif

class ContenuCompose;

