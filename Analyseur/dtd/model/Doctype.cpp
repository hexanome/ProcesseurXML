#include "Doctype.h"

Doctype::Doctype() {
    this->elements = new vector<Element*>();
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
