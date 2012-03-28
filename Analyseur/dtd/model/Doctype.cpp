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

void Doctype::addElement(Element * e) {
	this->elements->push_back(e);
}

void Doctype::setElements(vector<Element*> * els) {
	delete this->elements;
	this->elements = els;
}

vector<Element*> * Doctype::getElements() {
	return this->elements;
}

Element * Doctype::getElementByName(string name) {
	for (int i = 0; i < elements->size(); i++) {
		Element * el = elements->at(i);
		if (el->getNameSimple() == name) {
			return el;
		}
	}

	return NULL;
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
