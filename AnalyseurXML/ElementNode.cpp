#include "ElementNode.h"


ElementNode::ElementNode(ElementName name, AttList attlist) {
}

ElementNode::~ElementNode() {
}

Node ElementNode::firstChild() {
}

Node ElementNode::lastChild() {
}

void ElementNode::appendChild(Node n) {
}

string ElementNode::serialize() {
  string s = "<" + name.first() + ":" name.second();
  for(AttList::iterator it = attlist.
  return 
}
