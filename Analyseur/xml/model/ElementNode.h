#ifndef ELEMENTNODE_H
#define ELEMENTNODE_H

#include "../../includes/common.h"
#include "../../dtd/model/Element.h"
#include "../../dtd/model/Attribut.h"
#include "Node.h"

typedef vector<Node*> ChildNodes;

class ElementNode : public Node {

  public:
    ElementNode(string ns, string n);
    ~ElementNode();
    ElementName getName();
    Node *firstChild();
    Node *lastChild();
    void appendChild(Node *n);
    string getAttribute(string name);
    void setAttribute(string name, string value);
    void setNodes(vector<Node*> * nodes);
    void setAttributes(AttList * attList);
    bool isValid(Element * e);
    string serialize();

  private:
    ElementName nodeName;
    AttList * attributes;
    ChildNodes * childNodes;

};

#endif
