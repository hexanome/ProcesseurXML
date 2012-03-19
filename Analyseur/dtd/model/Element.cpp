#include "Element.h"

Element::Element(string name) {
  this->name = name;
}

void Element::setCategory(string category) {
  this->category = category;
}

void Element::addElement(Element * element) {
  this->elements.push_back(element);
}

void Element::addElements(vector<string> elements) {
  for (int i = 0; i < elements.size(); i++) {
    this->addElement(new Element(elements[i]));
  }
}

string Element::getName() {
  return this->name;
}

Element::~Element() {
}


string Element::serialize() {
	 string s = "<!ELEMENT " + name + " ";
	 if(category != "") {
	 	s += category;	 
	 } else {
	 	contenuMixte->serialize();
	 }
	 s += ">";
	 for (int i = 0; i < elements.size(); i++){
 		s += "\n" + elements[i]->serialize();
 	}
	 return s;
}
