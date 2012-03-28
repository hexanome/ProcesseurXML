#include "xml.h"

extern int xmllineno;

Document* XmlParser::parseStream(FILE* fd)
{
	// Specify the stream to use by the parser.
	xmlFlushBuffer();
	//YY_FLUSH_BUFFER();
	//printf("LINENO: %d\n", xmllineno);
	xmlin = fd;

	// Start the parsing of the document.
	Document *xdoc = NULL;
	int xmlErr = xmlparse(&xdoc);
	
	//if (xdoc != NULL) 
	//{
	//	cout << xdoc->serialize() << endl;
	//}

	return xdoc;
}
