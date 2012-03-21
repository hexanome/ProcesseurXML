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

bool serializeElementMegaComplexe() {
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
    
	string xml = e->serialize();
	cout<<endl<<xml<<endl;
	delete e;
	return xml == "<!ELEMENT TVSCHEDULE (CHANNEL)><!ELEMENT CHANNEL (to,from)><!ELEMENT to (#PCDATA)><!ELEMENT from (#PCDATA)><!ATTLIST CHANNEL CHAN CDATA #IMPLIED><!ATTLIST TVSCHEDULE NAME CDATA #IMPLIED>";	
}

bool serializeAttList() {
	Attribut* a = new Attribut("elementTest","taille");
	string xml = a->serialize();
	delete a;
    cout<<endl<<xml<<endl;
	return xml == "<!ATTLIST elementTest taille CDATA #IMPLIED>";	
}

int main(int argc, char ** argv) {
  int passed = 0;
  Test *test = new Test();
  test->run("serializeElementCategory", serializeElementCategory);
  test->run("serializeElementComplexe", serializeElementComplexe);
  test->run("serializeAttribut", serializeAttList);
  test->run("serializeElementMegaComplexe", serializeElementMegaComplexe);
  test->end();
	delete test;
  return 0;
}


/*
 <!ELEMENT TVSCHEDULE (CHANNEL+)>
 <!ELEMENT CHANNEL (BANNER, DAY+)>
 <!ELEMENT BANNER (#PCDATA)>
 <!ELEMENT DAY ((DATE, HOLIDAY) | (DATE, PROGRAMSLOT+))+>
 <!ELEMENT HOLIDAY (#PCDATA)>
 <!ELEMENT DATE (#PCDATA)>
 <!ELEMENT PROGRAMSLOT (TIME, TITLE, DESCRIPTION?)>
 <!ELEMENT TIME (#PCDATA)>
 <!ELEMENT TITLE (#PCDATA)> 
 <!ELEMENT DESCRIPTION (#PCDATA)>
 
 <!ATTLIST TVSCHEDULE	NAME CDATA #IMPLIED>
 <!ATTLIST CHANNEL	CHAN CDATA #IMPLIED>
 <!ATTLIST PROGRAMSLOT	 VTR CDATA #IMPLIED>
 <!ATTLIST TITLE RATING CDATA #IMPLIED>
 <!ATTLIST TITLE LANGUAGE CDATA #IMPLIED> 
*/
