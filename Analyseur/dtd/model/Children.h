#ifndef CHILDREN_H
#define CHILDREN_H

#include "ContenuCompose.h"

class Children : public ContenuCompose {

  public:
    Children();
    ~Children();

  private:
  vector<ContenuCompose*> contenu;

};

#endif