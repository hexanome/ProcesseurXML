#include "Element.h"

Element::Element() {
  this->name = "";
  this->serie = NULL;
  this->setCategory("");
  this->attributs = new vector<Attribut*>();
  this->mixed = new vector<string>();
}

Element::Element(string name) {
  this->name = name;
  this->serie = NULL;
  this->setCategory("");
  this->attributs = new vector<Attribut*>();
  this->mixed = new vector<string>();
}

Element::Element(string name, string cat) {
  this->name = name;
  this->serie = NULL;
  this->setCategory(cat);
  this->attributs = new vector<Attribut*>();
  this->mixed = new vector<string>();
}

Element::~Element(){
	for (int i = 0 ; i < attributs->size() ; i++) {
		delete attributs->at(i);
	}
  delete attributs;
  delete mixed;
}

vector<Attribut*>* Element::getAttributs(){
  return this->attributs;
}

void Element::setName(string name) {
  this->name = name;
}

void Element::setCategory(string category) {
  this->category = category;
}

void  Element::setSerie(Serie* s) {
  this->serie = s;  
}

void Element::setMixed(vector<string> * m) {
  delete this->mixed;
  this->mixed = m;
}

void Element::addAttribut(Attribut *a){
    this->attributs->push_back(a);
}

void Element::addMixed(string mixed) {
  this->mixed->push_back(mixed);
}

vector<Element*> * Element::getElements() {
	cout << "Element::getElements " << category << " " << serie;
	for (int i = 0; i < mixed->size(); i++) {
		cout << " " << mixed->at(i);
	}
	cout << endl; 
  if (category == "" && serie != NULL) { 
    return serie->getElements();
  } else {
  	return new vector<Element*>();
  }
}

vector<string> * Element::getMixed() {
  return this->mixed;
}

string Element::getName() {
  return this->name + this->cardinalite;
}

string Element::serialize() {
  string s = "<!ELEMENT " + name + " ";
  if(category != "") {
    s += category + ">";   
  } else if (serie != NULL && serie->getElements()->size() > 0) {
    s += serie->getName() + ">";
  } else {
    s += "(#PCDATA";
    for (int i = 0; i < mixed->size(); i++) {
      s += "|" + mixed->at(i);
    }
    s += ")>";
  }
  
  for (int i = 0; i < attributs->size(); i++) {
    s += attributs->at(i)->serialize();
  }

  return s;
}
