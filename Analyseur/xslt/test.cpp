#include "../../Test/test.h"
#include "../includes/common.h"
#include "../xml/model/Document.h"
#include "../xml/model/TextNode.h"
#include "../xml/model/ElementNode.h"
#include "transformer.h"

bool transformXMLlight() {
  Document * xml = new Document();
  ElementNode * root = new ElementNode("livre");
  xml->setRoot(root);
  ElementNode * titre = new ElementNode("titre");
  root->appendChild(titre);
  ElementNode * auteur = new ElementNode("auteur");
  titre->appendChild(auteur);
  ElementNode * chapitre = new ElementNode("chapitre");
  root->appendChild(chapitre);
  ElementNode * paragraphe = new ElementNode("paragraphe");
  chapitre->appendChild(paragraphe);

  Document * xsl = new Document();
  ElementNode * rootXSL = new ElementNode("xsl","stylesheet");
  
  xsl->setRoot(rootXSL);
  ElementNode * template1 = new ElementNode("xsl","template");
  template1->setAttribute("match","/");
  
  rootXSL->appendChild(template1);
  
  ElementNode * html = new ElementNode("html");
  template1->appendChild(html);
  ElementNode * head = new ElementNode("head");
  html->appendChild(head);
  ElementNode * title = new ElementNode("title");
  head->appendChild(title);
  ElementNode * body = new ElementNode("body");
  html->appendChild(body);
  
  
  Transformer * transformer = new Transformer(xsl);
  Document* xHtml = transformer->transformXML(xml);
  string test = xHtml->serialize();
  cout<<test<<endl;
  
  return true;
}

bool transformXMLhard() {
  Document * xml = new Document();
  ElementNode * root = new ElementNode("livre");
  xml->setRoot(root);
  ElementNode * titre = new ElementNode("titre");
  root->appendChild(titre);
  ElementNode * auteur = new ElementNode("auteur");
  titre->appendChild(auteur);
  ElementNode * chapitre = new ElementNode("chapitre");
  root->appendChild(chapitre);
  ElementNode * paragraphe1 = new ElementNode("paragraphe");
  chapitre->appendChild(paragraphe1);
  ElementNode * paragraphe2 = new ElementNode("paragraphe");
  chapitre->appendChild(paragraphe2);
  
  Document * xsl = new Document();
  ElementNode * rootXSL = new ElementNode("xsl","stylesheet");
  xsl->setRoot(rootXSL);
  ElementNode * template1 = new ElementNode("xsl","template");
  template1->setAttribute("match","/");
  rootXSL->appendChild(template1);
  
  ElementNode * html = new ElementNode("html");
  template1->appendChild(html);
  ElementNode * head = new ElementNode("head");
  html->appendChild(head);
  ElementNode * title = new ElementNode("title");
  head->appendChild(title);
  ElementNode * body = new ElementNode("body");
  html->appendChild(body);
  ElementNode * apply = new ElementNode("xsl","apply-templates");
  body->appendChild(apply);
  
  ElementNode * template2 = new ElementNode("xsl","template");
  template2->setAttribute("match","titre");
  Node* nodeTitre = new TextNode("ceci est un titre<br>");
  template2->appendChild(nodeTitre);
  ElementNode * apply2 = new ElementNode("xsl", "apply-templates");
  template2->appendChild(apply2);
  rootXSL->appendChild(template2);
  
  ElementNode * template3 = new ElementNode("xsl","template");
  template3->setAttribute("match","chapitre");
  template3->appendChild(new TextNode("ceci est un chapitre<br><br>"));
  ElementNode * apply3 = new ElementNode("xsl", "apply-templates");
  template3->appendChild(apply3);
  rootXSL->appendChild(template3);
  
  ElementNode * template4 = new ElementNode("xsl","template");
  template4->setAttribute("match","paragraphe");
  template4->appendChild(new TextNode("ceci est un paragraphe<br>"));
  rootXSL->appendChild(template4);
  
  ElementNode * template5 = new ElementNode("xsl","template");
  template5->setAttribute("match","auteur");
  template5->appendChild(new TextNode("ceci est un auteur<br><br>"));
  rootXSL->appendChild(template5);
  
  
  Transformer * transformer = new Transformer(xsl);
  Document* xHtml = transformer->transformXML(xml);
  
  string test = xHtml->serialize();
  cout<<test<<endl;
  
  return true;
}


// Run the tests

int main(int argc, char ** argv) {
  int passed = 0;
  Test *test = new Test();
  test->run("transformXMLlight", transformXMLlight);
  test->run("transformXMLhard", transformXMLhard);
  test->end();
  delete test;
  return 0;
}
