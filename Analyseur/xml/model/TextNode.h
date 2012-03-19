#ifndef TEXTNODE_H
#define TEXTNODE_H

#include "Node.h"

class TextNode : public Node {

  public:
    TextNode(string text);
    ~TextNode();
    string serialize();

  private:
    string text;

};

#endif
