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

	t->run("XML 1: Parse de rap1.xml.", testParseFile1);
	t->run("XML 2: Parse de rap2.xml.", testParseFile2);
	t->end();

	return 0;
}

