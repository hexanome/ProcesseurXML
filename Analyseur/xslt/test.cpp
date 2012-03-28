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
  
  return True;
}


// Run the tests

int main(int argc, char ** argv) {
  int passed = 0;
  Test *test = new Test();
  test->run("serializeTextNode", serializeTextNode);
  test->end();
  delete test;
  return 0;
}
