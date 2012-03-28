#include "../Test/test.h"
#include "includes/common.h"
#include "dtd/model/Element.h"
#include "dtd/model/Attribut.h"
#include "dtd/model/Sequence.h"
#include "xml/model/ElementNode.h"
#include "xml/model/TextNode.h"

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
  bool valid = element->isValid(e);

  delete text; delete element; delete e;
  return valid;
}
  
bool validateComplexDtd () {
	
	// XML 
  	TextNode *text = new TextNode("maison");
  	ElementNode *element = new ElementNode("CHANNEL", "to");
  	element->appendChild(text);	
  	
  	ElementNode *element2 = new ElementNode("TVSCHEDULE", "CHANNEL");
  	element2->appendChild(element);
  	
  	ElementNode *element3 = new ElementNode("", "TVSCHEDULE");
  	element3->appendChild(element2);
  	
  	element3->setAttribute("NAME","honneur");
  	element2->setAttribute("CHAN","32");
  		
	// DTD
	Element* e = new Element("TVSCHEDULE");
    Element* c = new Element("CHANNEL");
    Sequence* s = new Sequence();
    c->setCardinalite("+");
    s->addContenuCompose(c);
    e->setSerie(s);
   
    Sequence* s2 = new Sequence();    
    s2->addContenuCompose(new Element("to"));
  	s2->addContenuCompose(new Element("from"));
    c->setSerie(s2);
    c->addAttribut(new Attribut("CHANNEL","CHAN"));
    e->addAttribut(new Attribut("TVSCHEDULE","NAME"));

    // VALIDATE
    bool valid = element3->isValid(e);
  	delete text; delete element; delete element2; delete element3; delete s2; delete c; delete s;delete e;
  	return valid;    
  	
  	/*<!ELEMENT TVSCHEDULE (CHANNEL)>
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
// Run the tests

int main(int argc, char ** argv) {
  int passed = 0;
  Test *test = new Test();
  test->run("validateXmlDtd", validateXmlDtd);
  test->run("validateComplexDtd",validateComplexDtd);
  test->end();
  delete test;
  return 0;
}
