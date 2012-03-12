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
  for(AttList::iterator i = attlist.begin() ; i != attlist.end() ; i++) {
    s += " " + *i.first() + " \"" + *i.second() + "\"";
  }
  s += ">";
  for(Children::iterator i = children.begin() ; i != children.end() ; i++) {
    s += *i.serialize();
  }
  s += "</" + name.first() + ":" name.second() + ">"; 
  return s;
}
