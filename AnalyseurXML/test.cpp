#include "commun.h"
#include "ElementNode.h"
#include "TextNode.h"

int main(int argc, char ** argv) {
  TextNode text("blabla");
  ElementNode element("lol", "b");
  element.appendChild(text);
  cout << element.serialize() << endl;
  return 0;
}
