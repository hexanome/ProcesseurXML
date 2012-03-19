#include "../../Test/test.h"

bool testParseStream()
{
	return true;	
}

int main()
{
	Test *t = new Test();

	t->run("Test de parse de stream XML.", testParseStream);
	t->end();

	return 0;
}