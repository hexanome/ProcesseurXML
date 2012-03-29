#ifndef DOCUMENT_H
#define DOCUMENT_H

#include "ElementNode.h"
#include "../../dtd/model/Doctype.h"
#include "../../dtd/model/Sequence.h"

class Document {

  public:
    Document();
    ~Document();
    void setDtdFile(string dtd);
    string getDtdFile();
    void setRoot(ElementNode *newRoot);
    bool isValid(Doctype * d);
    ElementNode* getRoot();
    string serialize();

  private:
  	string dtdFile;
    ElementNode *root;

};

#endif
