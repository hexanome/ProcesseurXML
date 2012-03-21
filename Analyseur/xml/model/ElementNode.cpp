#include "ElementNode.h"


// Constructor
ElementNode::ElementNode(string ns, string n) {
  nodeName.first = ns;
  nodeName.second = n;

  childNodes = new vector<Node*>();
  attributes = new AttList();
}


// Destructor
ElementNode::~ElementNode() {
  delete childNodes;
  delete attributes;
}


// Get the first subnode
Node *ElementNode::firstChild() {
  return childNodes->front();
}


// Get the last subnode
Node *ElementNode::lastChild() {
  return childNodes->back();
}


// Append another node to the content
void ElementNode::appendChild(Node *n) {
  childNodes->push_back(n);
}


// Get an XML element attribute
string ElementNode::getAttribute(string name) {
  return (*attributes)[name];
}


// Set an XML element attribute
void ElementNode::setAttribute(string name, string value) {
  (*attributes)[name] = value;
}

// Set the collection of nodes
void ElementNode::setNodes(vector<Node*> * nodes)
{
  delete childNodes;

  if (nodes == NULL)
  {
    childNodes = new vector<Node*>();
    return;
  }

  childNodes = nodes;
}

// Set the collection of attributes
void ElementNode::setAttributes(AttList * attList)
{
  delete attributes;

  if (attList == NULL)
  {
    attributes = new AttList();
  }

  attributes = attList;
}

// Serialize structure to an XML string
string ElementNode::serialize() {

  // Tag name, with or without namespace
  string tag = (nodeName.first.length() > 0 ? nodeName.first + ":" : "") + nodeName.second;

  // Open tag
  string s = "<" + tag;
  for (map<string,string>::iterator ii = attributes->begin(); ii != attributes->end(); ++ii) {
    s += " " + (*ii).first + "=\"" + (*ii).second + "\"";
  }
  s += ">";

  // Content
  for (int i = 0 ; i < childNodes->size() ; i++) {
    s += childNodes->at(i)->serialize();
  }

  // End tag
  s += "</" + tag + ">";

  return s;
}
