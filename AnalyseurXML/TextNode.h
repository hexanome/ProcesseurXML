#include "commun.h"
#include "Node.h"

class TextNode : public Node {

  public:
    TextNode(string text);
    ~TextNode();

  private:
    string text;

}
