#include "Doctype.h"

Doctype::Doctype() {
    this->elements = new vector<Element*>();
    this->name = "";
}

Doctype::Doctype(string name) {
    this->elements = new vector<Element*>();
    this->name = name;
}

Doctype::~Doctype() {
    delete this->elements;
}

void Doctype::setElements(vector<Element*> * els) {
	delete this->elements;
	this->elements = els;
}

string Doctype::getName() {
    return this->name;
}

string Doctype::serialize() {
	string s = "";

	// Content
	for (int i = 0 ; i < elements->size(); i++) {
		s += elements->at(i)->serialize();
	}

	return s;
}
