
class TextNode : public Node {

  public:
    TextNode(std::string text);
    ~TextNode();

  private:
    std::string text;

}
