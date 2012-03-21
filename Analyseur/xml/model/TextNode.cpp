#include "TextNode.h"

TextNode::TextNode(string text) {
  this->text = text;
}

TextNode::~TextNode() {
}

string TextNode::serialize() {
  return text;
}
