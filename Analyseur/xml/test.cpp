#include "../../Test/test.h"
#include "xml.h"

bool testParseStream()
{
	FILE *xmlfd = fopen("rap1.xml", "r");

	XmlParser::parseStream(xmlfd);

	fclose(xmlfd);

	return true;	
}

int main()
{
	Test *t = new Test();

	t->run("Test de parse de stream XML.", testParseStream);
	t->end();

	return 0;
}

