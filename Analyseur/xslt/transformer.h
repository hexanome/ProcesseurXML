#ifndef XSLT_SERVICES_H
#define XSLT_SERVICES_H

#include "../xml/model/Document.h"

class Transformer
{
	public:
		Transformer(Document* xslt);
		~Transformer();
		Document* transformXML(Document *xml);
	private:
		Document *xslt;
		Document *xml;
		vector<ElementNode*> *templates;
		
		void setTemplates();
		ElementNode * transformTemplate(ElementNode* template, ElementNode* xmlChild);
	
};

#endif
