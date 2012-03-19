#include "ElementNode.h"


// Constructor
ElementNode::ElementNode(string ns, string n) {
  nodeName.first = ns;
  nodeName.second = n;
}


// Destructor
ElementNode::~ElementNode() {
}


// Get the first subnode
Node *ElementNode::firstChild() {
  return childNodes.front();
}


// Get the last subnode
Node *ElementNode::lastChild() {
  return childNodes.back();
}


// Append another node to the content
void ElementNode::appendChild(Node *n) {
  childNodes.push_back(n);
}


// Get an XML element attribute
string ElementNode::getAttribute(string name) {
  return attributes[name];
}


// Set an XML element attribute
void ElementNode::setAttribute(string name, string value) {
  attributes[name] = value;
}


// Serialize structure to an XML string
string ElementNode::serialize() {

  // Tag name, with or without namespace
  string tag = (nodeName.first.length() > 0 ? nodeName.first + ":" : "") + nodeName.second;

  // Open tag
  string s = "<" + tag;
  for( map<string,string>::iterator ii = attributes.begin(); ii != attributes.end(); ++ii) {
    s += " " + (*ii).first + "=\"" + (*ii).second + "\"";
  }
  s += ">";

  // Content
  for(int i = 0 ; i < childNodes.size() ; i++) {
    s += childNodes[i]->serialize();
  }

  // End tag
  s += "</" + tag + ">"; 
  return s;
}
