#include "../../Test/test.h"
#include "dtd.h"

bool testParseFile1()
{
	FILE *dtdfd = fopen("rap1.dtd", "r");
	Doctype *ddoc = DtdParser::parseStream(dtdfd);

	fclose(dtdfd);

	return (ddoc != NULL);	
}

bool testParseFile2()
{
	FILE *dtdfd = fopen("rap2.dtd", "r");
	Doctype *ddoc = DtdParser::parseStream(dtdfd);

	fclose(dtdfd);

	return (ddoc != NULL);	
}

bool testParseFile3()
{
	FILE *dtdfd = fopen("rap3.dtd", "r");
	Doctype *ddoc = DtdParser::parseStream(dtdfd);

	fclose(dtdfd);

	return (ddoc != NULL);	
}

int main()
{
	Test *t = new Test();

	t->run("DTD 1: Parse de rap1.dtd.", testParseFile1);
	t->run("DTD 2: Parse de rap2.dtd (fichier non valide).", testParseFile2);
	t->run("DTD 3: Parse de rap3.dtd.", testParseFile3);
	t->end();

	return 0;
}



