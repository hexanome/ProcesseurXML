%{

using namespace std;
#include <ctype.h>
#include <string.h>
#include "../../includes/common.h"
#include "../model/Document.h"
#include "../model/TextNode.h"

void xmlerror(Document **xdoc, char *msg);
int xmllex(void);
extern int xmllineno;

%}

%error-verbose
%parse-param { Document **xdoc }

%union {
   char * s;
   ElementName * en;  /* le nom d'un element avec son namespace */
   ElementNode * elNode;
   vector<Node*> * nodeList;
   AttList * attList;
}

%token EQ SLASH CLOSE CLOSESPECIAL DOCTYPE
%token <s> ENCODING STRING DATA COMMENT IDENT NSIDENT
%token <en> NSSTART START STARTSPECIAL END NSEND

%type <s> declarations_opt declaration attributeName
%type <elNode> xml_element
%type <en> start attribute
%type <nodeList> content_opt close_content_and_end empty_or_content
%type <attList> attributes_opt

%%

document
  : declarations_opt xml_element misc_seq_opt 
  { 
    *xdoc = new Document(); 
    (*xdoc)->setDtdFile($1);
    (*xdoc)->setRoot($2);
  }
  ;

misc_seq_opt
  : misc_seq_opt comment
  | /*empty*/
  ;

comment
  : COMMENT
  ;

declarations_opt
  : declaration
  | /*empty*/
  {
    $$ = "";
  }
  ;
 
declaration
  : DOCTYPE IDENT IDENT STRING CLOSE
  {
    $$ = $4;
  }
  ;

xml_element
  : start attributes_opt empty_or_content 
  { 
    ElementNode *xnode = new ElementNode($1->first, $1->second);
    
    xnode->setAttributes($2);
    xnode->setNodes($3);

    $$ = xnode;
  }
  ;

start
  : START
  | NSSTART
  ;

attributes_opt
  : attributes_opt attribute
  {
    AttList *attList = $1;

    attList->insert(*($2));

    $$ = attList;
  }
  | /*empty*/
  {
    $$ = new AttList();
  }
  ;

attribute
  : attributeName EQ STRING
  {
    $$ = new ElementName($1, $3);
  }
  ;

attributeName
  : IDENT
  | NSIDENT
  ;

empty_or_content
  : SLASH CLOSE	
  {
    $$ = NULL;
  }
  | close_content_and_end CLOSE 
  {
    $$ = $1;
  }
  ;

close_content_and_end
  : CLOSE content_opt end
  {
    $$ = $2;
  }
  ;

end
  : END
  | NSEND
  ;

content_opt 
  : content_opt DATA
  {
    TextNode *textNode = new TextNode($2);

    vector<Node*> * nodes = $1;
    nodes->push_back(textNode);

    $$ = nodes;
  }
  | content_opt comment
  {
    $$ = $1;
  }   
  | content_opt xml_element   
  {
    ElementNode *elementNode = $2;
    vector<Node*> * nodes = $1;

    nodes->push_back(elementNode);

    $$ = nodes;
  }   
  | /*empty*/   
  {
    $$ = new vector<Node*>();
  }      
  ;

%%

void xmlerror(Document **xdoc, char *msg)
{
  fprintf(stderr, "line %d, %s\n", xmllineno, msg);
}
