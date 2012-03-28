#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "ElementNode.h"
#include "../../dtd/model/Doctype.h"

class Document {

  public:
    Document();
    ~Document();
    void setRoot(ElementNode *newRoot);
    bool isValid(Element * e);
    ElementNode* getRoot();
    string serialize();

  private:
    ElementNode *root;

};

#endif
