#include "../../../Test/test.h"
#include "../../includes/common.h"
#include "ElementNode.h"
#include "TextNode.h"

// Testing XML services and serialization

bool serializeTextNode() {
  TextNode *text = new TextNode("bonjour");

  string xml = text->serialize();
  delete text;
  return xml == "bonjour";
}

bool serializeElementNode() {
  ElementNode *element = new ElementNode("ns", "element");

  string xml = element->serialize();
  delete element;
  return xml == "<ns:element></ns:element>";
}

bool serializeBoth() {
  TextNode *text = new TextNode("bonjour");
  ElementNode *element = new ElementNode("", "element");
  element->appendChild(text);

  string xml = element->serialize();
  delete text; delete element;
  return xml == "<element>bonjour</element>";
}

bool serializeComplex() {
  TextNode *foo = new TextNode("foo");
  TextNode *bar = new TextNode("bar");
  TextNode *baz = new TextNode("baz");

  ElementNode *ebar = new ElementNode("","awesome");
  ebar->appendChild(bar);

  ElementNode *e = new ElementNode("yo","dawg");
  e->appendChild(foo);
  e->appendChild(ebar);
  e->appendChild(baz);

  string xml = e->serialize();
  delete e; delete ebar; delete foo; delete bar; delete baz;
  return xml == "<yo:dawg>foo<awesome>bar</awesome>baz</yo:dawg>";
}

bool serializeElementNodeWithAttList() {
  TextNode *textNode1 = new TextNode("beau temps");
  ElementNode *elementNode1 = new ElementNode("","Date");
  elementNode1->setAttribute("Annee","2013");
  elementNode1->setAttribute("Heure","13");
  elementNode1->appendChild(textNode1);
  
  string xml = elementNode1->serialize();
  delete elementNode1;
  delete textNode1;
  cout << endl << xml << endl;
  return xml == "<Date Annee=\"2013\" Heure=\"13\">beau temps</Date>";
}

// Run the tests

int main(int argc, char ** argv) {
  int passed = 0;
  Test *test = new Test();
  test->run("serializeTextNode", serializeTextNode);
  test->run("serializeElementNode", serializeElementNode);
  test->run("serializeBoth", serializeBoth);
  test->run("serializeComplex", serializeComplex);
  test->run("serializeElementNodeWithAttList", serializeElementNodeWithAttList);
  test->end();
  delete test;
  return 0;
}
