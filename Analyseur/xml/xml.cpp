#include "xml.h"

Document* XmlParser::parseStream(FILE* fd)
{
	// Specify the stream to use by the parser.
	xmlin = fd;

	// Start the parsing of the document.
	Document* xdoc;
	int xmlErr = xmlparse(&xdoc);

	cout << xdoc->serialize() << endl;

	return xdoc;
}