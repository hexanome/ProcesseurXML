#include "ElementNode.h"


ElementNode::ElementNode(string ns, string n) {
  nodeName.first = ns;
  nodeName.second = n;
}

ElementNode::~ElementNode() {
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

string ElementNode::getAttribute(string name) {
  return attributes[name];
}

void ElementNode::setAttribute(string name, string value) {
  attributes[name] = value;
}

string ElementNode::serialize() {
  string s = "<" + nodeName.first + ":" + nodeName.second;
  for( map<string,string>::iterator ii = attributes.begin(); ii != attributes.end(); ++ii) {
    s += " " + (*ii).first + " \"" + (*ii).second + "\"";
  }
  s += ">";
  for(int i = 0 ; i < childNodes.size() ; i++) {
    s += childNodes[i]->serialize();
  }
  s += "</" + nodeName.first + ":" + nodeName.second + ">"; 
  return s;
}
