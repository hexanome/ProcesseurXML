#include "Element.h"

Element::Element(string name) {
    this->name = name;
    this->serie = 0;
    this->setCategory("");
    this->attributs = new vector<Attribut*>();
    this->mixed = new vector<string>();
}

Element::Element(string name, string cat) {
    this->name = name;
    this->serie = 0;
    this->setCategory(cat);
    this->attributs = new vector<Attribut*>();
    this->mixed = new vector<string>();
}

Element::~Element(){
    delete attributs;
    delete mixed;
}

vector<Attribut*>* Element::getAttributs(){
    return this->attributs;
}

void Element::setCategory(string category) {
  this->category = category;
}

void  Element::setSerie(Serie* s) {
  this->serie = s;  
}

void Element::addAttribut(Attribut *a){
    this->attributs->push_back(a);
}

void Element::addMixed(string mixed) {
  this->mixed->push_back(mixed);
}

vector<Element*> * Element::getElements() {
  if(category != "") {
    return new vector<Element*>();
  }
  return serie->getElements();
}

vector<string> * Element::getMixed() {
  return this->mixed;
}

string Element::getName() {
  return this->name;
}

string Element::serialize() {
   string s = "<!ELEMENT " + name + " ";
   if(category != "") {
     s += category + ">";   
   } else if (serie != 0 && serie->getElements()->size() > 0) {
     s += serie->getName() + ">" + serie->serialize();
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
