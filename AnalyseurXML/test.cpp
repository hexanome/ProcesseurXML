#include "commun.h"
#include "ElementNode.h"
#include "TextNode.h"

bool serialize() {

  TextNode *text = new TextNode("blabla");
  ElementNode *element = new ElementNode("lol", "p");
  element->appendChild(text);

  string xml = element->serialize();

  delete text;
  delete element;

  return xml == "<lol:p>blabla</lol:p>";

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
  passed += test("serialize", serialize);
  cout << passed << "/1 tests passed" << endl;
  return 0;
}
