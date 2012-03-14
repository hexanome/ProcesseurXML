#include "commun.h"
#include "Node.h"

class TextNode : public Node {

  public:
    TextNode(string text);
    ~TextNode();
    string serialize();

  private:
    string text;

};
