#include "../../Test/test.h"
#include "dtd.h"

bool testParseFile1()
{
	FILE *dtdfd = fopen("rap1.dtd", "r");
	Document *ddoc = DtdParser::parseStream(dtdfd);

	fclose(dtdfd);

	return (ddoc != NULL);	
}

int main()
{
	Test *t = new Test();

	t->run("Test de parse de stream DTD1.", testParseFile1);
	t->end();

	return 0;
}
