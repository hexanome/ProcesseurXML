#include "../../Test/test.h"
#include "xml.h"

bool testParseFile1()
{
	FILE *xmlfd = fopen("rap1.xml", "r");

	Document *xdoc = XmlParser::parseStream(xmlfd);

	fclose(xmlfd);

	return (xdoc != NULL);	
}

bool testParseFile2()
{
	FILE *xmlfd = fopen("rap2.xml", "r");

	Document *xdoc = XmlParser::parseStream(xmlfd);

	fclose(xmlfd);

	return (xdoc != NULL);
}

int main()
{
	Test *t = new Test();

	t->run("Test de parse de stream XML 1.", testParseFile1);
	t->run("Test de parse de stream XML 2.", testParseFile2);
	t->end();

	return 0;
}

