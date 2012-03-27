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
  

// Run the tests

int main(int argc, char ** argv) {
  int passed = 0;
  Test *test = new Test();
  test->run("validateXmlDtd", validateXmlDtd);
  test->end();
  delete test;
  return 0;
}
