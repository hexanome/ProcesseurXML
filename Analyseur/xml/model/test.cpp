#include "../../../Test/test.h"
#include "../../includes/common.h"
#include "ElementNode.h"
#include "TextNode.h"
#include "Document.h"

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
  delete element;
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
  delete e;
  return xml == "<yo:dawg>foo<awesome>bar</awesome>baz</yo:dawg>";
}

bool serializeHtml() {
  Document * d = new Document();
  ElementNode * html = new ElementNode("", "html");
  d->setRoot(html);
  ElementNode * head = new ElementNode("", "head");
  html->appendChild(head);
  ElementNode * title = new ElementNode("", "title");
  head->appendChild(title);
  ElementNode * body = new ElementNode("", "body");
  html->appendChild(body);
  ElementNode * h1 = new ElementNode("", "h1");
  body->appendChild(h1);
  TextNode * text1 = new TextNode("bonjour");
  title->appendChild(text1);
  TextNode * text2 = new TextNode("titre");
  h1->appendChild(text2);

  string xml = d->serialize();
   delete d;
  return xml == "<html><head><title>bonjour</title></head><body><h1>titre</h1></body></html>";
}

bool serializeElementNodeWithAttList() {
  TextNode *textNode1 = new TextNode("beau temps");
  ElementNode *elementNode1 = new ElementNode("","Date");
  elementNode1->setAttribute("Annee","2013");
  elementNode1->setAttribute("Heure","13");
  elementNode1->appendChild(textNode1);
  
  string xml = elementNode1->serialize();
  delete elementNode1;
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
  test->run("serializeHtml", serializeHtml);
  test->end();
  delete test;
  return 0;
}
