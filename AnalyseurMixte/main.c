#include "main.h"

int main(int argc, char **argv)
{
	FILE *xmlfd = fopen("rap1.xml", "r");
	if (!xmlfd)
	{
		cout << "Y U NO OPEN THE FILE!\n";
	}

	xmlin = xmlfd;

	char * xmlContent = new char[10000];
	int xmlErr = xmlparse(&xmlContent);

	fclose(xmlfd);

	// Exploitation du fichier.
	cout << "Nom de la DTD: " << xmlContent << '\n';

	// Lecture de la DTD.
	FILE *dtdfd = fopen(xmlContent, "r");
	if (!dtdfd)
	{
		cout << "FU\n";
	}

	dtdin = dtdfd;

	int dtdErr = dtdparse();

	fclose(dtdfd);

	cout << "So much win!!!\n";

	return 0;
}
