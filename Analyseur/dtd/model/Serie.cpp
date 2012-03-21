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

string Serie::serialize() {
	string s = "";
	for (int i = 0; i < contenu->size() ; i++) {
		s += contenu->at(i)->serialize();
	}
	return s;
}

