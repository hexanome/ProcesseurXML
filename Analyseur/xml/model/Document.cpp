#include "Document.h"

Document::Document() {
	root = new ElementNode("","");
}

Document::~Document() {
	delete root;
}

void Document::setRoot(ElementNode *newRoot) 
{
	delete root;
	root = newRoot;
}

ElementNode* Document::getRoot()
{
	return root;
}

string Document::serialize()
{
	return root->serialize();
}

bool Document::isValid(Doctype * d)
{
	Element * e = new Element(root->getName().second);// FIXME should be d->getName());
	Sequence * s = new Sequence();
	for (int i = 0 ; i < d->getElements()->size() ; i++) {
		s->addContenuCompose(d->getElements()->at(i));
	}
	e->setSerie(s);
	bool valid = root->isValid(e);
	return valid;
}
