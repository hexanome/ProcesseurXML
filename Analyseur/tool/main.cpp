#include "main.h"

int main(int argc, char **argv)
{
	// We start by reading the command line arguments.
	string xmlFile = "";
	string dtdFile = "";
	string xslFile = "";


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
    		xslFile = argv[i + 1];
    	}
    }

    // First step of the parsing process: The XML file.
    FILE *xmlfd = fopen(xmlFile.c_str(), "r");

    if (xmlfd == 0)
    {
        return XML_FILE_NOT_FOUND;
    }

    Document *xdoc = XmlParser::parseStream(xmlfd);
    fclose(xmlfd);

    // Now, if no DTD file was specified, we read the XML document to see if it specifies one.
    if (dtdFile == "" && xdoc->getDtdFile() != "")
    {
        dtdFile = xdoc->getDtdFile();
    }

    // If we now have a DTD file, we load it and validate the XML file against it.
    if (dtdFile != "")
    {
        FILE *dtdfd = fopen(dtdFile.c_str(), "r");

        if (dtdfd == 0)
        {
            return DTD_FILE_NOT_FOUND;
        }

        Doctype *ddoc = DtdParser::parseStream(dtdfd);
        fclose(dtdfd);

        // We try to validate the XML document against the DTD.
        if (!xdoc->isValid(ddoc))
        {
            return INVALID_FILE;
        }
    }

    // Finally, if an xls schema file was specified, we load it as an XML file, and transform our original file.
    if (xslFile != "")
    {
        FILE *xslfd = fopen(xslFile.c_str(), "r");

        if (xslfd == 0)
        {
            return XSL_FILE_NOT_FOUND;
        }

        Document *xslDoc = XmlParser::parseStream(xslfd);
        fclose(xslfd);

        // We now transform our original file using this schema.
        Transformer * transformer = new Transformer(xslDoc);
        Document * transformedDoc = transformer->transformXML(xdoc);

        // We print the result on the standard output.
        cout << transformedDoc->serialize() << endl; 
    }

	return SUCCESS;
}