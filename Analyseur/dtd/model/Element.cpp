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
	 	s += "(";
	 	for (int i = 0; i < elements.size(); i++){
	 		if (i > 0) {
	 			s += ",";
	 		}
	 		s += elements[i]->getName();
	 	}
	 	s += ")";
	 }
	 s += ">";
	 for (int i = 0; i < elements.size(); i++){
 		s += "\n" + elements[i]->serialize();
 	}
	 return s;
}
