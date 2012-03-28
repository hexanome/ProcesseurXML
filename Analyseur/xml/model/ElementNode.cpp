#include "ElementNode.h"


// Constructors
ElementNode::ElementNode(string ns, string n) {
  nodeName.first = ns;
  nodeName.second = n;

  childNodes = new vector<Node*>();
  attributes = new AttList();
}

ElementNode::ElementNode(string n) {
  nodeName.first = "";
  nodeName.second = n;

  childNodes = new vector<Node*>();
  attributes = new AttList();
}

// Destructor
ElementNode::~ElementNode() {
	for (int i = 0 ; i < childNodes->size() ; i++) {
		delete childNodes->at(i);
	}
  delete childNodes;
  delete attributes;
}


// Get the element's name with namespace
ElementName ElementNode::getName() {
	return nodeName;
}


// Get the first subnode
Node *ElementNode::firstChild() {
  return childNodes->front();
}


// Get the last subnode
Node *ElementNode::lastChild() {
  return childNodes->back();
}

vector<Node*> * ElementNode::getChildren()
{
  return childNodes;
}


// Append another node to the content
void ElementNode::appendChild(Node *n) {
  childNodes->push_back(n);
}


// Get an XML element attribute
string ElementNode::getAttribute(string name) {
  return (*attributes)[name];
}

AttList * ElementNode::getAttributes()
{
  return attributes;
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

bool ElementNode::isValid(Element * e)
{
	bool valid = nodeName.second == e->getName();
	
	vector<Attribut*>* att = e->getAttributs();
	for (map<string,string>::iterator ii = attributes->begin(); ii != attributes->end(); ++ii) {
		bool found = false;
		for (int i = 0 ; i < att->size() && !found ; i++) {
			found |= (*ii).first == att->at(i)->getAttributeName();
		}
		valid &= found;
	}
	
	vector<Element*> * els = e->getElements();
	for (int i = 0; i < childNodes->size(); i++) {
		ElementNode * child = dynamic_cast<ElementNode*>(childNodes->at(i));
		if (child) {
			bool found = false;
			for (int j = 0 ; j < els->size() && !found ; j++) {
				if (child->getName().second == els->at(j)->getName()) {
					valid &= child->isValid(els->at(j));
					found = true;
				}
			}
			valid &= found;
		}
	}
	
	return valid;
}

