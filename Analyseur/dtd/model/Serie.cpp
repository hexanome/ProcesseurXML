#include "Serie.h"

Serie::Serie() {
	this->contenu = new vector<ContenuCompose*>();
}

Serie::~Serie() {
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

vector<Element*> * Element::getElements() {
	vector<Element*> * els = new vector<Element*>();
	for (int i = 0; i < contenu->size(); i++) {
		vector<Element*> * subels += contenu->at(i)->getElements();
		int j = 0;
		while (j < subels->size()) {
			els->push_back(subels->at(j));
			j++;
		}
		if (j == 0) {
			els->push_back(contenu->at(i));
		}
	}
    return elements;
}

string Serie::serialize() {
	string s = "";
	for (int i = 0; i < contenu->size() ; i++) {
		s += contenu->at(i)->serialize();
	}
	return s;
}

