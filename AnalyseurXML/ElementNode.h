#include "commun.h"
#include "Node.h"

class ElementNode : public Node {

  public:
    ElementNode(ElementName name, AttList attlist);
    ~ElementNode();
    Node firstChild();
    Node lastChild();
    void appendChild(Node n);
    string serialize();

  private:
    ElementName name;
    AttList attlist;
    list<Node> children;

}
