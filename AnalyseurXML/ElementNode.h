#ifndef ELEMENTNODE_H
#define ELEMENTNODE_H

#include "commun.h"
#include "Node.h"

typedef list<Node> Children;

class ElementNode : public Node {

  public:
    ElementNode(ElementName name, AttList attlist);
    ~ElementNode();
    Node firstChild();
    Node lastChild();
    void appendChild(Node n);
    string serialize();

  private:
    ElementName name;
    AttList attlist;
    Children children;

}

#endif
