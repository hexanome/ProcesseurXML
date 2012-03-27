#ifndef ATTRIBUT_H
#define ATTRIBUT_H
#include "../../includes/common.h"


class Attribut {

  public:
    Attribut();
    ~Attribut();
    Attribut(string elementName, string attributeName);
    string serialize();
    void setElementName(string elementName);
    void setAttributeName(string attributeName);
    void addType(string type);
    string getElementName();
    string getAttributeName();
    vector<string> * getTypes();

  private:
    string elementName;
    string attributeName;
    vector<string> * attributeTypes;
    string defaultValue;
  
};

#endif
