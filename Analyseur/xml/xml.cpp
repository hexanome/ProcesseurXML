#include "xml.h"

Document* parseStream(FILE* fd)
{
	// Specify the stream to use by the parser.
	xmlin = fd;

	// Start the parsing of the document.
	Document* xdoc;
	int xmlErr = xmlparse(&xdoc);

	return xdoc;
}