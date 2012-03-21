#include "Document.h"

Document::Document() {
	this->definitions = new vector<Definitions*>();
}

Document::~Document() {
	delete this->definitions;
}
