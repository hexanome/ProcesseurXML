#include "Element.h"

Element::Element(string name) {
    this->name = name;
    this->attributs = new vector<Attribut*>();    
}

Element::~Element(){
    delete attributs;
}

Element::Element(string name, string cat) {
    this->name = name;
    this->setCategory(cat);
    this->attributs = new vector<Attribut*>();
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
    for (int i = 0; i < attributs->size() ; i++) {
        s += attributs->at(i)->serialize();
    }
   return s;
}
