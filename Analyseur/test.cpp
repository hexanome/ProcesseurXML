#include "../Test/test.h"
#include "includes/common.h"
#include "dtd/model/Element.h"
#include "dtd/model/Attribut.h"
#include "dtd/model/Sequence.h"
#include "dtd/model/Doctype.h"
#include "dtd/dtd.h"
#include "xml/xml.h"
#include "xml/model/ElementNode.h"
#include "xml/model/TextNode.h"
#include "xml/model/Document.h"


// Testing XML and DTD models on XML/DTD validation

bool validateXmlDtd() {
    // XML 
    TextNode *text = new TextNode("bonjour");
    ElementNode *element = new ElementNode("", "element");
    element->appendChild(text);

    // DTD
    Element* e = new Element("element");
    e->setCategory("ANY");

    // Validate
    bool valid = element->isValid(e, NULL);

    delete element; delete e;
    return valid;
}

  
bool validateComplexDtd () {
	
	// XML 
  	TextNode *text = new TextNode("maison");
  	ElementNode *element = new ElementNode("to");
  	element->appendChild(text);	
  	
  	ElementNode *element2 = new ElementNode("CHANNEL");
  	element2->appendChild(element);
  	
  	ElementNode *element3 = new ElementNode("TVSCHEDULE");
  	element3->appendChild(element2);
  	
  	element3->setAttribute("NAME","honneur");
  	element2->setAttribute("CHAN","32");
  		
	// DTD
	Element* e = new Element("TVSCHEDULE");
    Element* c = new Element("CHANNEL");
    Sequence* s = new Sequence();
    s->addContenuCompose(c);
    e->setSerie(s);
   
    Sequence* s2 = new Sequence();    
    Element * toEl = new Element("to");
    Element * fromEl = new Element("from");
    s2->addContenuCompose(toEl);
  	s2->addContenuCompose(fromEl);

    c->setSerie(s2);
    c->addAttribut(new Attribut("CHANNEL","CHAN"));
    e->addAttribut(new Attribut("TVSCHEDULE","NAME"));

  Doctype* d = new Doctype();
  d->addElement(e);
  d->addElement(c);
  d->addElement(toEl);
  d->addElement(fromEl);

    // VALIDATE
    bool valid = element3->isValid(e, d);
  	delete element3;
  	return valid;    
  	
  	/*
    <!ELEMENT TVSCHEDULE (CHANNEL)>
	<!ELEMENT CHANNEL (to,from)>
	<!ELEMENT to (#PCDATA)>
	<!ELEMENT from (#PCDATA)>
	<!ATTLIST CHANNEL CHAN CDATA #IMPLIED>
	<!ATTLIST TVSCHEDULE NAME CDATA #IMPLIED>

	<TVSCHEDULE NAME="honneur">
	<CHANNEL CHAN="32">
	<to>maison</to>
	</CHANNEL>
	</TVSCHEDULE>*/

    
}

bool testValidationFile1() {
  FILE *dtdfd = fopen("rap1.dtd", "r");
  Doctype *ddoc = DtdParser::parseStream(dtdfd);

  FILE *xmlfd = fopen("rap1.xml", "r");
  Document *xdoc = XmlParser::parseStream(xmlfd);

  fclose(xmlfd);
  fclose(dtdfd);
  bool valid = xdoc->isValid(ddoc);
  delete ddoc; delete xdoc;

  return valid;
}

// Run the tests

int main(int argc, char ** argv) {
  int passed = 0;
  Test *test = new Test();
  test->run("Validation 1: Validation d'un élément XML simple par une DTD.", validateXmlDtd);
  test->run("Validation 2: Validation de plusieurs éléments XML par une DTD plus compliquée.",validateComplexDtd);
  test->run("Validation 3: Validation d'un fichier XML par une DTD présente dans un autre fichier.", testValidationFile1);
  test->end();
  delete test;
  return 0;
}
