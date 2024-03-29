#include "../../../Test/test.h"
#include "../../includes/common.h"
#include "Doctype.h"
#include "Element.h"
#include "Attribut.h"
#include "Sequence.h"

// Testing DTD services and serialization

bool serializeElementCategory() {
  Element* e = new Element("note");
  e->setCategory("ANY");
  string xml = e->serialize();
  delete e;
  return xml == "<!ELEMENT note ANY>";  
}

bool serializeElementComplexe() {
  Element* e = new Element("note");
  Sequence* s = new Sequence();
  s->addContenuCompose(new Element("to"));
  s->addContenuCompose(new Element("from"));
  s->addContenuCompose(new Element("heading"));
  s->addContenuCompose(new Element("body"));
  e->setSerie(s);  
  string xml = e->serialize();
  delete e;
  return xml == "<!ELEMENT note (to,from,heading,body)>";  
}

bool serializeElementMegaComplexe() {
  vector<Element*> * els = new vector<Element*>();

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

  els->push_back(e);
  els->push_back(c);

  Doctype * ddoc = new Doctype();
  ddoc->setElements(els);
    
  string xml = ddoc->serialize();
  delete e;
  return xml == "<!ELEMENT TVSCHEDULE (CHANNEL+)><!ATTLIST TVSCHEDULE NAME CDATA #IMPLIED><!ELEMENT CHANNEL (to,from)><!ATTLIST CHANNEL CHAN CDATA #IMPLIED>";  
}

bool serializeAttList() {
  Attribut* a = new Attribut("elementTest","taille");
  string xml = a->serialize();
  delete a;
  return xml == "<!ATTLIST elementTest taille CDATA #IMPLIED>";  
}

// Run the tests

int main(int argc, char ** argv) {
  int passed = 0;
  Test *test = new Test();
  test->run("Serialisation d'un Element avec Category", serializeElementCategory);
  test->run("Serialisation d'un Element Complexe", serializeElementComplexe);
  test->run("Serialisation d'une liste d'Attributs", serializeAttList);
  test->run("Serialisation d'une DTD complexe", serializeElementMegaComplexe);
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
 
 <!ATTLIST TVSCHEDULE  NAME CDATA #IMPLIED>
 <!ATTLIST CHANNEL  CHAN CDATA #IMPLIED>
 <!ATTLIST PROGRAMSLOT   VTR CDATA #IMPLIED>
 <!ATTLIST TITLE RATING CDATA #IMPLIED>
 <!ATTLIST TITLE LANGUAGE CDATA #IMPLIED> 
*/
