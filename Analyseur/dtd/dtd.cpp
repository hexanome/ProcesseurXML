#include "dtd.h"

Document* DtdParser::parseStream(FILE* fd)
{
	// Specify the stream to use by the parser.
	dtdFlushBuffer();
	dtdin = fd;

	// Start the parsing of the document.
	Document *ddoc = NULL;
	int dtdErr = dtdparse(&ddoc);

	if (ddoc != NULL) 
	{
		// cout << ddoc->serialize() << endl;
	}

	//return ddoc;
}
