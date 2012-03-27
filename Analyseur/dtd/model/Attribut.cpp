#include "Attribut.h"

Attribut::Attribut() {
}

Attribut::Attribut(string elementName,string attributeName){
	this->elementName = elementName;
	this->attributeName = attributeName;
	this->attributeTypes = new vector<string>();
	this->defaultValue = "#IMPLIED";
}

Attribut::~Attribut() {
}

void Attribut::setElementName(string elementName) {
  this->elementName = elementName;
}

void Attribut::setAttributeName(string attributeName) {
  this->attributeName = attributeName;
}

void Attribut::addType(string type) {
  this->attributeTypes->push_back(type);
}

string Attribut::getElementName(){
    return this->elementName;
}

string Attribut::getAttributeName(){
    return this->attributeName;
}

vector<string> * Attribut::getTypes() {
  return this->attributeTypes;
}

string Attribut::serialize(){
  string s = "<!ATTLIST";
  s += " " + elementName + " " + attributeName + " ";
  if ( attributeTypes->size() > 1 ) {
    s += "(";
    for ( int i = 0; i < attributeTypes->size(); i++ ) {
      if (i > 0) s += ",";
      s += attributeTypes->at(i);
    }
    s += ")";
  } else if ( attributeTypes->size() == 1 ) {
    s += attributeTypes->at(0);
  } else {
    s += "CDATA";
  }
  s += " " + defaultValue;
  s += ">";
  return s;
}
