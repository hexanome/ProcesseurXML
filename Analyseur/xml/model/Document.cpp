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

bool Document::isValid(Element * e)
{
	return root->isValid(e);
}
