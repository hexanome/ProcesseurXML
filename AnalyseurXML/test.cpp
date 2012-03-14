#include "commun.h"
#include "ElementNode.h"
#include "TextNode.h"

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

int test(string name, bool(*unitTest)()) {
  cout << "[test] " << name << " ";
  if (!unitTest()) {
    cout << "FAIL" << endl;
    return 0;
  }
  cout << "OK" << endl;
  return 1;
}

int main(int argc, char ** argv) {
  int passed = 0;
  passed += test("serializeTextNode", serializeTextNode);
  passed += test("serializeElementNode", serializeElementNode);
  passed += test("serializeBoth", serializeBoth);
  passed += test("serializeComplex", serializeComplex);
  cout << passed << "/4 tests passed" << endl;
  return 0;
}
