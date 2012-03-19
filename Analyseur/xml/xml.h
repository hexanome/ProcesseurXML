#ifndef XML_SERVICES_H
#define XML_SERVICES_H

#include "../includes/common.h"
#include "model/Document.h"

extern FILE* xmlin;
extern int xmlparse(Document **xdoc);

class XmlParser
{
	public:
		static Document* parseStream(FILE *fd);
};

#endif

