#ifndef SEQUENCE_H
#define SEQUENCE_H

#include "Children.h"

class Sequence : public Children {

  public:
    Sequence();
    ~Sequence();
    string serialize();
};

#endif
