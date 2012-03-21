#include "../../includes/common.h"
#include "Element.h"
#include "Attribut.h"
#include "Sequence.h"
// ..mettre les autres includes.
#include "../../../Test/test.h"


bool serializeElementCategory() {
	Element* e = new Element("note");
	e->setCategory("ANY");
	string xml = e->serialize();
	delete e;
	cout<<endl<<xml<<endl;
	return xml == "<!ELEMENT note ANY>";	
}

bool serializeElementComplexe() {
	Element* e = new Element("note");
	Sequence* s = new Sequence();
	s->addContenuCompose(new Element("to","(#PCDATA)"));
	s->addContenuCompose(new Element("from","(#PCDATA)"));
	s->addContenuCompose(new Element("heading","(#PCDATA)"));
	s->addContenuCompose(new Element("body","(#PCDATA)"));
	e->setSerie(s);	
	string xml = e->serialize();
	cout<<endl<<xml<<endl;
	delete e;
	return xml == "<!ELEMENT note (to,from,heading,body)><!ELEMENT to (#PCDATA)><!ELEMENT from (#PCDATA)><!ELEMENT heading (#PCDATA)><!ELEMENT body (#PCDATA)>";	
}

bool serializeAttList() {
	Attribut* a = new Attribut("elementTest","taille");
	string xml = a->serialize();
	delete a;
	return xml == "<!ATTLIST elementTest taille CDATA #IMPLIED>";	
}

int main(int argc, char ** argv) {
  int passed = 0;
  Test *test = new Test();
  test->run("serializeElementCategory", serializeElementCategory);
  test->run("serializeElementComplexe", serializeElementComplexe);
  test->run("serializeAttribut", serializeAttList);
  test->end();
	delete test;
  return 0;
}
