#include "commun.h"
#include "ElementNode.h"
#include "TextNode.h"
#include "../Test/test.h"

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


int main(int argc, char ** argv) {
  int passed = 0;
  Test *test = new Test();
  test->run("serializeTextNode", serializeTextNode);
  test->run("serializeElementNode", serializeElementNode);
  test->run("serializeBoth", serializeBoth);
  test->run("serializeComplex", serializeComplex);
  test->end();
	delete test;
  return 0;
}
