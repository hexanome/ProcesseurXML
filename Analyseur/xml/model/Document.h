#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "ElementNode.h"
#include "../../dtd/model/Doctype.h"
#include "../../dtd/model/Sequence.h"

class Document {

  public:
    Document();
    ~Document();
    void setRoot(ElementNode *newRoot);
    bool isValid(Doctype * d);
    ElementNode* getRoot();
    string serialize();

  private:
    ElementNode *root;

};

#endif
