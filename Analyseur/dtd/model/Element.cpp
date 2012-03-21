#include "Element.h"

Element::Element(string name) {
  this->name = name;
}

Element::Element(string name, string cat) {
  this->name = name;
  this->setCategory(cat);
}

Element::~Element() {
}

void Element::setCategory(string category) {
  this->category = category;
}

void  Element::setSerie(Serie* s) {
	this->serie = s;	
}

string Element::getName() {
  return this->name;
}

vector<Element*> * Element::getElements() {
	if(category != "") {
		return new vector<Element*>();
	}
    return serie->getElements();
}

string Element::serialize() {
	 string s = "<!ELEMENT " + name + " ";
	 if(category != "") {
	 	s += category + ">";	 
	 } else {
	 	s += serie->getName() + ">" + serie->serialize();
	 }
	 return s;
}
