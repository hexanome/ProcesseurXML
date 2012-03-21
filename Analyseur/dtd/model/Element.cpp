#include "Element.h"

Element::Element(string name) {
    this->name = name;
    this->attribut = new vector<Attribut*>();    
}

Element::~Element(){
    delete attribut;
}

Element::Element(string name, string cat) {
    this->name = name;
    this->setCategory(cat);
    this->attribut = new vector<Attribut*>();
}

vector<Attribut*>* Element::getAttribut(){
    return this->attribut;
}

Element::~Element() {
}

void Element::setCategory(string category) {
  this->category = category;
}

void  Element::setSerie(Serie* s) {
	this->serie = s;	
}

void Element::addAttribut(Attribut *a){
    this->attribut->push_back(a);
}

vector<Element*> * Element::getElements() {
	if(category != "") {
		return new vector<Element*>();
	}
    return serie->getElements();
}

string Element::getName() {
  return this->name;
}

string Element::serialize() {
	 string s = "<!ELEMENT " + name + " ";
	 if(category != "") {
	 	s += category + ">";	 
	 } else {
	 	s += serie->getName() + ">" + serie->serialize();
	 }
    for (int i = 0; i < attribut->size() ; i++) {
        s += attribut->at(i)->serialize();
    }
	 return s;
}
