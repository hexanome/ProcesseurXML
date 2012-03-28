#include "../../../Test/test.h"
#include "../../includes/common.h"
#include "ElementNode.h"
#include "TextNode.h"
#include "Document.h"

bool transformXML() {
  Document * xml = new Document();
  ElementNode * root = new ElementNode("livre");
  xml->setRoot(root);
  ElementNode * titre = new ElementNode"titre");
  root->appendChild(titre);
  ElementNode * auteur = new ElementNode("auteur");
  titre->appendChild(auteur);
  ElementNode * chapitre = new ElementNode("chapitre");
  root->appendChild(chapitre);
  ElementNode * paragraphe = new ElementNode("paragraphe");
  chapitre->appendChild(paragraphe);

  Document * xsl = new Document();
  ElementNode * root = new ElementNode("xsl","stylesheet");
  xsl->setRoot(root);
  ElementNode * template1 = new ElementNode("xsl","template");
  template1->setAttribute("match","/");
  root->appendChild(template1);
  
  ElementNode * html = new ElementNode("", "html");
  d->setRoot(html);
  ElementNode * head = new ElementNode("", "head");
  html->appendChild(head);
  ElementNode * title = new ElementNode("", "title");
  head->appendChild(title);
  ElementNode * body = new ElementNode("", "body");
  html->appendChild(body);
  template1->appendChild(html);
  
  Transformer * transformer = new Transformer(xsl);
  Document* xHtml = transformer->transformXML(xml);
  
  string test = xHtml->serialize();
  cout<<test<<endl;
  
  return True;
}


// Run the tests

int main(int argc, char ** argv) {
  int passed = 0;
  Test *test = new Test();
  test->run("transformXML", transformXML);
  test->end();
  delete test;
  return 0;
}
