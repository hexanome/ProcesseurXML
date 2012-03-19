#include "Document.h"

Document::Document() {
}

Document::~Document() {
}

void Document::setRoot(ElementNode *newRoot) 
{
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