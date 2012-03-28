#include "main.h"

int main(int argc, char **argv)
{
	// We start by reading the command line arguments.
	string xmlFile = "";
	string dtdFile = "";
	string xlsFile = "";


    for (int i = 0; i < argc; i++)
    {
    	if (i == 1) 
    	{
    		xmlFile = argv[i];
    	}
    	else if (((string)"-d").compare(argv[i]) == 0 && i + 1 < argc)
    	{
    		dtdFile = argv[i + 1];
    	}
    	else if (((string)"-s").compare(argv[i]) == 0 && i + 1 < argc)
    	{
    		xlsFile = argv[i + 1];
    	}
    }

    cout << "HEY HEY" << endl;

    // First step of the parsing process: The XML file.
    FILE *xmlfd = fopen(xmlFile.c_str(), "r");

    if (xmlfd < 0)
    {
        return FILE_NOT_FOUND;
    }

    Document *xdoc = XmlParser::parseStream(xmlfd);
    fclose(xmlfd);

    cout << "HAHA" << endl;

	return SUCCESS;
}