#include "ElementNode.h"


ElementNode::ElementNode(string ns, string n) {
  nodeName.first = ns;
  nodeName.second = n;
}

ElementNode::~ElementNode() {
  for
}

Node *ElementNode::firstChild() {
  return childNodes.front();
}

Node *ElementNode::lastChild() {
  return childNodes.back();
}

void ElementNode::appendChild(Node *n) {
  childNodes.push_back(n);
}

string ElementNode::serialize() {
  string s = "<" + nodeName.first() + ":" nodeName.second();
  for(int i = 0 ; i < attributes.size() ; i++) {
    s += " " + attributes[i].first() + " \"" + attributes[i].second() + "\"";
  }
  s += ">";
  for(int i = 0 ; i < childNodes.size() ; i++) {
    s += childNodes[i]->serialize();
  }
  s += "</" + nodeName.first() + ":" nodeName.second() + ">"; 
  return s;
}
