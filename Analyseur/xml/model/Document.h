#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "ElementNode.h"

class Document {

  public:
    Document();
    ~Document();
    void setRoot(ElementNode *newRoot);
    ElementNode* getRoot();
    virtual string serialize();

  private:
    ElementNode *root;

};

#endif
