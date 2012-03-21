#include "xml.h"

Document* XmlParser::parseStream(FILE* fd)
{
	// Specify the stream to use by the parser.
	xmlFlushBuffer();
	xmlin = fd;

	// Start the parsing of the document.
	Document *xdoc = NULL;
	int xmlErr = xmlparse(&xdoc);

	if (xdoc != NULL) 
	{
		cout << xdoc->serialize() << endl;
	}

	return xdoc;
}
