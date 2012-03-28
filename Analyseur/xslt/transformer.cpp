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
  ElementNode *root=xml->getRoot();
  
  ElementNode* rootTemplate;
  for (vector<ElementNode*>::iterator ik = templates->begin(); ik != templates->end(); ++ik) {
    if((*ik)->getAttribute("match").compare("//")==0)
    {
      result->setRoot((ElementNode*)transformTemplate(*ik,root)->back());
    }
  }
  return result;
}

vector<Node*> * Transformer::transformTemplate(ElementNode* unTemplate, ElementNode* xmlChild)
{
  vector<Node*> *children = unTemplate->getChildren();
  vector<Node*>* result = new vector<Node*>();
  for (vector<Node*>::iterator ii = children->begin(); ii != children->end(); ++ii) {
	ElementNode * child = dynamic_cast<ElementNode*>(*ii);
	if (child) {
	  if(child->getName().first.compare("xsl")==0)
	  {
	    if(child->getName().second.compare("apply-templates")==0)
	    {
	      vector<Node*>* subChildren = xmlChild->getChildren();
	      for (vector<Node*>::iterator ij = subChildren->begin(); ij != subChildren->end(); ++ij) {
		ElementNode * childNode = dynamic_cast<ElementNode*>(*ij);
		if (childNode) {
		  for (vector<ElementNode*>::iterator ik = templates->begin(); ik != templates->end(); ++ik) {
		    if(child->getName().second.compare((*ik)->getAttribute("match")))
		    {
		      vector<Node*> * subResult = transformTemplate(*ik,childNode);
		      result->insert(result->end(), subResult->begin(), subResult->end());
		    }
		  }
		}
	      }
	    }
	  }
	  else 
	  {
	    ElementNode* node = new ElementNode(child->getName().first,child->getName().second);
	    node->setAttributes(new map<string,string>(*(child->getAttributes())));
	    vector<Node*>* subChildren = child->getChildren();
	    vector<Node*> * subNode = new vector<Node*>();
	    for (vector<Node*>::iterator ij = subChildren->begin(); ij != subChildren->end(); ++ij) {
	      ElementNode * subChild = dynamic_cast<ElementNode*>(*ij);
	      if (subChild) {
	      vector<Node*>* subResult = transformTemplate(subChild,xmlChild);
	      subNode->insert(subNode->end(), subResult->begin(), subResult->end());
	      }
	      else
	      {
		subNode->push_back(*ii);
	      }
	    }
	    node->setNodes(subNode);
	    result->push_back(node);
	  }
	}
	else
	{
	  result->push_back(*ii);
	}
    }
    return result;
}

void Transformer::setTemplates()
{
  ElementNode *root=xslt->getRoot();
  vector<Node*>* children = root->getChildren();
  for (vector<Node*>::iterator ii = children->begin(); ii != children->end(); ++ii) {
	ElementNode * child = dynamic_cast<ElementNode*>(*ii);
	if (child) {
	  if(child->getName().first.compare("xsl")==0 && child->getName().second.compare("template")==0)
	  {
	    templates->push_back(child);
	  }
	}
  }
}