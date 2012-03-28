#include "dtd.h"

Doctype* DtdParser::parseStream(FILE* fd)
{
	// Specify the stream to use by the parser.
	dtdFlushBuffer();
	dtdin = fd;

	// Start the parsing of the document.
	Doctype *ddoc = NULL;
	int dtdErr = dtdparse(&ddoc);

	return ddoc;
}
