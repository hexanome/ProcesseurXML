#include "transformer.h"

Transformer::Transformer(Document* xslt)
{
  this->xslt=xslt;
  templates = new vector<ElementNode*>();
  setTemplates();
}

Document* Transformer::transformXML(Document *xml)
{
  Document *result = new Document();
  ElementNode *root=xml->root;
  
  ElementNode* rootTemplate;
  for (vector<ElementNode*>::iterator ik = templates->begin(); ik != templates->end(); ++ik) {
    if((*ik)->getAttribute("match").compare("//")==0)
    {
      result->setRoot(transformTemplate(*ik,root));
    }
  }
  return NULL;
}

vector<ElementNode*> * Transformer::transformTemplate(ElementNode* template, ElementNode* xmlChild)
{
  vector<Node*> children = template->getChildren();
  ElementNode* result = new vector<ElementNode*>();
  for (vector<Node*>::iterator ii = children->begin(); ii != children->end(); ++ii) {
	ElementNode * child = dynamic_cast<ElementNode*>(childNodes->at(i));
	if (child) {
	  if(child->getName().first.compare("xsl")==0)
	  {
	    if(child->getName().second.compare("apply-templates")==0)
	    {
	      vector<Node*> subChildren = xmlChild->getChildren();
	      for (vector<Node*>::iterator ij = subChildren->begin(); ij != subChildren->end(); ++ij) {
		for (vector<ElementNode*>::iterator ik = templates->begin(); ik != templates->end(); ++ik) {
		  if((*ii)->getName().second.compare((*ik).getAttribute("match"))
		  {
		    ElementNode* subResult = transformTemplate(*ik,*ij);
		    result->insert(result->end(), subResult->begin(), subResult->end());
		  }
		}
	      }
	    }
	  }
	  else
	  {
	    ElementNode* node = new ElementNode(child.first,child.second);
	    node.seAttributes(new map<string,string>(node.getAttributes()));
	    vector<Node*> subChildren = node->getChildren();
	    for (vector<Node*>::iterator ij = subChildren->begin(); ij != subChildren->end(); ++ij) {
	      ElementNode* subResult = transformTemplate(*ij,xmlChild);
	      result->insert(result->end(), subResult->begin(), subResult->end());
	    }
	}
	else
	{
	  result->push_back(*ii);
	}
}

void Transformer::setTemplates()
{
  ElementNode *root=xslt->root;
  vector<Node*> children = root->getChildren();
  for (vector<Node*>::iterator ii = children->begin(); ii != children->end(); ++ii) {
	if(ii->getName.first.compare("xsl")==0 && ii->getName.second.compare("template")==0)
	{
	  templates.push_back(ii*);
	}
  }
}