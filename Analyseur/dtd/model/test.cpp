#include "../../includes/common.h"
#include "Element.h"
#include "Attribut.h"
// ..mettre les autres includes.
#include "../../../Test/test.h"


bool serializeElement() {
	Element* e = new Element("note");
	e->setCategory("ANY");
	string xml = e->serialize();
	delete e;
	return xml == "<!ELEMENT note ANY>";	
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
  test->run("serializeElement", serializeElement);
  test->run("serializeAttribut", serializeAttList);
  test->end();
	delete test;
  return 0;
}
