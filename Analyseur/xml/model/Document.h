#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "../includes/common.h"
#include "ElementNode.h"

class Document {

  public:
    Document();
    ~Document();

  private:
    ElementNode *root;

};

#endif
