#include "../../Test/test.h"
#include "xml.h"

bool testParseFile1()
{
	FILE *xmlfd = fopen("rap1.xml", "r");

	XmlParser::parseStream(xmlfd);

	fclose(xmlfd);

	return true;	
}

bool testParseFile2()
{
	FILE *xmlfd = fopen("rap2.xml", "r");

	XmlParser::parseStream(xmlfd);

	fclose(xmlfd);

	return true;
}

int main()
{
	Test *t = new Test();

	t->run("Test de parse de stream XML1.", testParseFile1);
	t->run("Test de parse de stream XML2.", testParseFile2);
	t->end();

	return 0;
}

