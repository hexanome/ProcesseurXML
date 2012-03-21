#ifndef ATTRIBUT_H
#define ATTRIBUT_H
#include "../../includes/common.h"


class Attribut {

  public:
    Attribut();
    ~Attribut();
    Attribut(string elementName, string attributeName);
    string serialize();
    string getAttributeName();

  private:
    string elementName;
    string attributeName;
    string attributeType;
    string defaultValue;
  
};

#endif
