#ifndef ELEMENTNODE_H
#define ELEMENTNODE_H

#include "commun.h"
#include "Node.h"

typedef vector<Node*> ChildNodes;

class ElementNode : public Node {

  public:
    ElementNode(string ns, string n);
    ~ElementNode();
    Node *firstChild();
    Node *lastChild();
    void appendChild(Node *n);
    string serialize();

  private:
    ElementName nodeName;
    AttList attributes;
    ChildNodes childNodes;

};

#endif
