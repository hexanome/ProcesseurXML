#include "xml.h"

extern int xmllineno;

Document* XmlParser::parseStream(FILE* fd)
{
	// Specify the stream to use by the parser.
	xmlFlushBuffer();
	xmlin = fd;

	// Start the parsing of the document.
	Document *xdoc = NULL;
	int xmlErr = xmlparse(&xdoc);

	return xdoc;
}
