#include "Attribut.h"

Attribut::Attribut() {
}
Attribut::Attribut(string elementName,string attributeName){
	this->elementName = elementName;
	this->attributeName = attributeName;
	this->attributeType = "CDATA";
	this->defaultValue = "#IMPLIED";
}
Attribut::~Attribut() {
}

string Attribut::serialize(){
  string s = "<!ATTLIST";
  s += " " + elementName + " " + attributeName + " " + attributeType + " " + defaultValue;
  s += ">";
  return s;
}

