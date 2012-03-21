#include "../Test/test.h"
#include "includes/common.h"
#include "dtd/model/Element.h"
#include "dtd/model/Attribut.h"
#include "dtd/model/Sequence.h"
#include "xml/model/ElementNode.h"
#include "xml/model/TextNode.h"

// Testing XML and DTD models on XML/DTD validation

bool modelValidate() {
  return true;
}
  

// Run the tests

int main(int argc, char ** argv) {
  int passed = 0;
  Test *test = new Test();
  //test->run("serializeElementMegaComplexe", serializeElementMegaComplexe);
  test->end();
  delete test;
  return 0;
}
