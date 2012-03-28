#include "Serie.h"

Serie::Serie() {
  this->contenu = new vector<ContenuCompose*>();
}

Serie::~Serie() {
	for (int i = 0 ; i < contenu->size() ; i++) {
		delete contenu->at(i);
	}
  delete this->contenu;
}

void Serie::addContenuCompose(ContenuCompose *co){
  this->contenu->push_back(co);
}

string Serie::getName() {
  string s = "(";
  for (int i = 0; i < contenu->size() ; i++) {
    if (i > 0) s += this->separator;
    s += contenu->at(i)->getName();
  }
  s += ")" + this->cardinalite;
  return s;
}

vector<Element*> * Serie::getElements() {
  vector<Element*> * els = new vector<Element*>();
  for (int i = 0; i < contenu->size(); i++) {
    Serie * s = dynamic_cast<Serie*>(contenu->at(i));
    if (s) {
      vector<Element*> * subels = s->getElements();
      int j = 0;
      while (j < subels->size()) {
        els->push_back(subels->at(j));
        j++;
      }
    } else {
      els->push_back((Element*)contenu->at(i));
    }
  }
    return els;
}

string Serie::serialize() {
  string s = "";
  for (int i = 0; i < contenu->size() ; i++) {
    s += contenu->at(i)->serialize();
  }
  return s;
}

