#include "main.h"

int main(int argc, char **argv)
{
	// We start by reading the command line arguments.
	string xmlFile = "";
	string dtdFile = "";
	string xslFile = "";
    bool verbose = false;
    bool reservedIndex = 0;

    for (int i = 0; i < argc; i++)
    {
    	if (((string)"-d").compare(argv[i]) == 0 && i + 1 < argc && argv[i + 1][0] != '-')
    	{
    		dtdFile = argv[i + 1];
            reservedIndex = i + 1;
    	}
    	else if (((string)"-s").compare(argv[i]) == 0 && i + 1 < argc && argv[i + 1][0] != '-')
    	{
    		xslFile = argv[i + 1];
            reservedIndex = i + 1;
    	}
        else if (((string)"-v").compare(argv[i]) == 0)
        {
            verbose = true;
        }
        else if (xmlFile == "" && i != reservedIndex && argv[i][0] != '-')
        {
            xmlFile = argv[i];            
        }
    }

    if (verbose)
        cout << endl << "-- XML" << endl;

    if (xmlFile == "")
    {
        if (verbose)
            cout << "ERROR: No file was specified, aborting." << endl;

        return NO_FILE_SPECIFIED;
    }

    if (verbose)
        cout << "Trying to open XML file \"" << xmlFile << "\"." << endl;

    // First step of the parsing process: The XML file.
    FILE *xmlfd = fopen(xmlFile.c_str(), "r");

    if (xmlfd == 0)
    {
        if (verbose)
            cout << "ERROR: Can't find XML file \"" << xmlFile << "\"." << endl;

        return XML_FILE_NOT_FOUND;
    }

    if (verbose)
        cout << "XML file \"" << xmlFile << "\" was opened successfully." << endl;

    Document *xdoc = XmlParser::parseStream(xmlfd);
    fclose(xmlfd);

    // Now, if no DTD file was specified, we read the XML document to see if it specifies one.
    if (verbose)
        cout << endl << "-- DTD" << endl;

    if (dtdFile == "" && xdoc->getDtdFile() != "")
    {
        dtdFile = xdoc->getDtdFile();

        if (verbose)
            cout << "The DTD file \"" << dtdFile << "\" was specified in \"" << xmlFile << "\"." << endl << endl;
    }
    else if (dtdFile != "" && verbose)
    {
        cout << "The DTD file \"" << dtdFile << "\" was specified explicitly." << endl << endl;
    }

    // If we now have a DTD file, we load it and validate the XML file against it.
    if (dtdFile != "")
    {
        if (verbose)
            cout << "Trying to open DTD file \"" << dtdFile << "\"." << endl;

        FILE *dtdfd = fopen(dtdFile.c_str(), "r");

        if (dtdfd == 0)
        {
            if (verbose)
            cout << "ERROR: Can't find DTD file \"" << dtdFile << "\"." << endl;

            return DTD_FILE_NOT_FOUND;
        }

        Doctype *ddoc = DtdParser::parseStream(dtdfd);
        fclose(dtdfd);

        if (verbose)
        {
            cout << "DTD file \"" << xmlFile << "\" was opened successfully." << endl << endl;
            cout << "Trying to validate XML file \"" << xmlFile << "\" against DTD file \"" << dtdFile << "\"." << endl;
        }

        // We try to validate the XML document against the DTD.
        if (!xdoc->isValid(ddoc))
        {
            if (verbose)
                cout << "ERROR: XML file \"" << xmlFile << "\" failed validation against DTD file \"" << dtdFile << "\"." << endl;

            return INVALID_XML_FILE;
        }

        if (verbose)
            cout << "XML file \"" << xmlFile << "\" was successfully validated against DTD file \"" << dtdFile << "\"." << endl;
    }

    // Finally, if an xls schema file was specified, we load it as an XML file, and transform our original file.
    if (verbose)
        cout << endl << "-- XSL" << endl;

    if (xslFile != "")
    {
        if (verbose)
            cout << "Trying to open XSL file \"" << xslFile << "\"." << endl;

        FILE *xslfd = fopen(xslFile.c_str(), "r");

        if (xslfd == 0)
        {
            if (verbose)
                cout << "ERROR: Can't find XSL file \"" << xslFile << "\"." << endl;

            return XSL_FILE_NOT_FOUND;
        }

        Document *xslDoc = XmlParser::parseStream(xslfd);
        fclose(xslfd);

        /*
        FILE *xslDtdFd = fopen("xslt.dtd", "r");

        if (xslDtdFd == 0)
        {
            if (verbose)
                cout << "DTD file for XSL file not found, moving on..." << endl;
        }
        else
        {
            Doctype *xslDDoc = DtdParser::parseStream(xslDtdFd);
            fclose(xslDtdFd);

            if (verbose)
                cout << "DTD file for XSL file was opened successfully." << endl;

            if (!xslDoc->isValid(xslDDoc))
            {
                if (verbose)
                    cout << "ERROR: XSL file \"" << xslFile << "\" failed validation against the XSL DTD." << endl;

                return INVALID_XSL_FILE;
            }

            if (verbose)
                cout << "XSL file \"" << xslFile << "\" was successfully validated against the XSL DTD." << endl;
        }
        */

        if (verbose)
        {
            cout << "XSL file \"" << xslFile << "\" was opened successfully." << endl << endl;
            cout << "Transforming XML file \"" << xmlFile << "\" using XSL file \"" << xslFile << "\"." << endl;
        }

        // We now transform our original file using this schema.
        Transformer * transformer = new Transformer(xslDoc);
        Document * transformedDoc = transformer->transformXML(xdoc);

        if (verbose)
            cout << endl << "Resulting file:" << endl << endl;

        // We print the result on the standard output.
        cout << transformedDoc->serialize() << endl; 
    }

    if (verbose)
        cout << endl << "-- Completed." << endl << endl;

	return SUCCESS;
}