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
  cout << "THIS TEST WILL SEGFAULT BECAUSE OF rap2.dtd" << endl;
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

	t->run("Test de parse de stream DTD 1.", testParseFile1);
	//t->run("Test de parse de stream DTD 2.", testParseFile2);
	//t->run("Test de parse de stream DTD 3.", testParseFile3);
	t->end();

	return 0;
}



