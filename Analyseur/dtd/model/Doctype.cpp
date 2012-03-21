#include "Doctype.h"

Doctype::Doctype() {
    this->elements = new vector<Element*>();
}

Doctype::Doctype(string name) {
    this->elements = new vector<Element*>();
    this->name = name;
}

Doctype::~Doctype() {
    delete elements;
}

string Doctype::getName() {
    return this->name;
}
