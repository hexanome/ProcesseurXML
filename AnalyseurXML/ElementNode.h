#include<string>

class ElementNode : public Node {

  public:
    ElementNode(std::string name, std::vector<string> attlist);
    ~ElementNode();
    ElementNode firstChild();
    virtual void appendChild(Node n);
    virtual string serialize();

  private:
    std::string name;
    std::vector<Node> children;
    std::vector<std::string> attlist;

}
