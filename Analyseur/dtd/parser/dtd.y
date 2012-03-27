%{

using namespace std;
#include <ctype.h>
#include <string.h>
#include "../../includes/common.h"
#include "../model/Doctype.h"

void dtderror(char *msg);
int dtdlex(void);
  
%}

%error-verbose
%parse-param { Doctype **ddoc }

%union {
  char *s;
  Element * el;
  Serie * serie;
  Attribute * att;
  vector<Element*> * elList;
}

%token ELEMENT ATTLIST CLOSE OPENPAR CLOSEPAR COMMA PIPE FIXED EMPTY ANY PCDATA AST QMARK PLUS CDATA
%token <s> IDENT TOKENTYPE DECLARATION STRING

%type <el> content_spec children
%type <serie> 
%type <att> attribute
%type <elList> dtd_list_opt
%%

main: dtd_list_opt
  {
    // We create the document, and fill it.
    *ddoc = new Doctype();
    (*ddoc)->setElements($1);
  }
  ;

dtd_list_opt
  : dtd_list_opt ELEMENT IDENT content_spec CLOSE
  {
      // Retrieve the current collection.
      vector<Element*> * elements = $1;

      // We create a new Element and add it to the list.
      Element * newEl = $4;
      newEl.setName($3);

      elements.push_back(newEl);

      $$ = elements;
  }
  | dtd_list_opt ATTLIST IDENT att_definition_opt CLOSE
  {
      // Retrieve the current collection.
      vector<Element*> * elements = $1;

      // Create a new Attribute to add it to the collection.
      vector<Attribute*> * attributes = $4;

      // We find the corresponding element, and insert the attribute.
      for (int i = 0; i < elements.size(); i++)
      {
        Element * anEl = elements.at(i);
        if (anEl.getName() == $3)
        {
          for (int y = 0; y < attributes.size(); y++)
          {
            Attribute * anAtt = attributes.at(y);
            anAtt.setElementName(anEl.getName());
            anEl.addAttribut(anAtt);
          }
          break; 
        }
      }

      $$ = elements;
  }            
  | /* empty */    
  {
    // We create the Element Array.
    $$ = new vector<Element*>();
  }                 
  ;

content_spec
  : ANY
  {
    // We create a new Element with category "ANY".
    Element * newEl = new Element();
    newEl.setCategory("ANY");

    $$ = newEl;
  }
  | EMPTY
  {
    // We create a new Element with category "EMPTY".
    Element * newEl = new Element();
    newEl.setCategory("EMPTY");

    $$ = newEl;
  }
  | mixed
  {

  }
  | children
  ;

children
  : choice card
  {
    // We create a new Element with a Choice serie.
    Element * newEl = new Element();
    newEl.setSerie($1);
    newEl.setCardinalite($2);

    $$ = newEl;
  }
  | sequence card
  {
    // We create a new Element with a sequence serie.
    Element * newEl = new Element();
    newEl.setSerie($1);
    newEl.setCardinalite($2);

    $$ = newEl;
  }
  ;
 
item_card
 : item card
 ; 
 
item
 : choice
 | sequence
 | IDENT
 ;
 
card
 : PLUS 
 | QMARK
 | AST
 | /*empty*/ 
 ;

choice
 : OPENPAR list_choice_plus CLOSEPAR
 ;

list_choice_plus
 : item_card PIPE list_choice
 ;
 
list_choice
 : list_choice PIPE item_card
 | item_card
 ;
    
sequence
 : OPENPAR list_sequence CLOSEPAR
 ;
 
list_sequence
 : list_sequence COMMA item_card
 | item_card
 ;
 
mixed
 : OPENPAR PCDATA mixed_content CLOSEPAR AST
 | OPENPAR PCDATA CLOSEPAR
 ;
 
mixed_content
 : mixed_content PIPE IDENT
 | IDENT
 ;
 
att_definition_opt
  : att_definition_opt attribute
  {
    // We retrieve the current attribute collection.
    vector<Attribute*> * attList = $1;

    // We add the new attribute to the collection.
    attList->push_back($2);

    $$ = attList;
  }
  | /* empty */
  {
    // We create a new collection of attributes.
    $$ = new vector<Attribute*>();
  }
  ;

attribute
  : IDENT att_type default_declaration
  {
      Attribute * att = new Attribute($1, $2, $3);
  }
  ;

att_type
  : CDATA    
  | TOKENTYPE
  | enumerate
  ;

enumerate
  : OPENPAR enum_list_plus CLOSEPAR
  ;

enum_list_plus
  : enum_list PIPE item_enum
  ;

enum_list
  : item_enum               
  | enum_list PIPE item_enum
  ;

item_enum
  : IDENT
  ;

default_declaration
  : DECLARATION 
  | STRING     
  | FIXED STRING 
  ;

%%

void dtderror(char *msg)
{
  fprintf(stderr, "%s\n", msg);
}