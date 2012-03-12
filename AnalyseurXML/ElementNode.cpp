#include "ElementNode.h"


ElementNode::ElementNode(string ns, string n) {
  nodeName.first = ns;
  nodeName.second = n;
}

ElementNode::~ElementNode() {
}

Node ElementNode::firstChild() {
  return childNodes.front();
}

Node ElementNode::lastChild() {
  return childNodes.back();
}

void ElementNode::appendChild(Node & n) {
  childNodes.push_back(n);
}

string ElementNode::serialize() {
  string s = "<" + nodeName.first() + ":" nodeName.second();
  for(AttList::iterator i = attributes.begin() ; i != attributes.end() ; i++) {
    s += " " + *i.first() + " \"" + *i.second() + "\"";
  }
  s += ">";
  for(ChildNodes::iterator i = childNodes.begin() ; i != childNodes.end() ; i++) {
    s += *i.serialize();
  }
  s += "</" + nodeName.first() + ":" nodeName.second() + ">"; 
  return s;
}
