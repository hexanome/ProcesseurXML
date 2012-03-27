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
  	TextNode *text = new TextNode("bonjour");
  	ElementNode *element = new ElementNode("", "element");
  	element->appendChild(text);	
	
	// DTD
	Element* e = new Element("TVSCHEDULE");
    Element* c = new Element("CHANNEL");
    Sequence* s = new Sequence();
    c->setCardinalite("+");
    s->addContenuCompose(c);
    e->setSerie(s);
   
    Sequence* s2 = new Sequence();    
    s2->addContenuCompose(new Element("to","(#PCDATA)"));
  	s2->addContenuCompose(new Element("from","(#PCDATA)"));
    c->setSerie(s2);
    c->addAttribut(new Attribut("CHANNEL","CHAN"));
    e->addAttribut(new Attribut("TVSCHEDULE","NAME"));
    
    
}
// Run the tests

int main(int argc, char ** argv) {
  int passed = 0;
  Test *test = new Test();
  test->run("validateXmlDtd", validateXmlDtd);
  test->end();
  delete test;
  return 0;
}
