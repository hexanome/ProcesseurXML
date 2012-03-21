#include "Document.h"

Document::Document() {
	root = NULL;
}

Document::~Document() {
	delete root;
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
	if (root == NULL)
	{
		return "";
	}

	return root->serialize();
}

bool Document::isValid(Element * e)
{
	return root->isValid(e);
}
