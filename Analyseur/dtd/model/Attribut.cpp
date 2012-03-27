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
string Attribut::getElementName(){
    return this->elementName;
}
string Attribut::getAttributeName(){
    return this->attributeName;
}
string Attribut::serialize(){
    cout<<"oki"<<endl;
  string s = "<!ATTLIST";
  s += " " + elementName + " " + attributeName + " " + attributeType + " " + defaultValue;
  s += ">";
  return s;
}

