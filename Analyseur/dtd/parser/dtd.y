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
    // We create a new Element with a "Mixed" Serie.
    Element * newEl = new Element();
    newEl.setMixed($1);

    $$ = newEl;
  }
  | children
  {
    // We create a new Element and add the Serie to it.
    Element * newEl = new Element();
    newEl.setSerie($1);

    $$ = newEl;
  }
  ;

children
  : choice card
  {
    // We set the card of the choice Serie.
    Serie * choiceSerie = $1;
    choiceSerie.setCardinalite($2);

    $$ = choiceSerie;
  }
  | sequence card
  {
    // We set the card of the sequence Serie.
    Serie * choiceSerie = $1;
    choiceSerie.setCardinalite($2);

    $$ = choiceSerie;
  }
  ;
 
item_card
  : item card
  {
    ContenuCompose * contenu = $1;
    contenu.setCardinalite($2);

    $$ = contenu;
  }
  ; 
 
item
  : choice
  {
    $$ = $1;
  }
  | sequence
  {
    $$ = $1;
  }
  | IDENT
  {
    // We create a ...
    Element * newEl = new Element();
    newEl.setName($1);

    $$ = newEl;
  }
  ;
 
card
  : PLUS 
  | QMARK
  | AST
  | /*empty*/ 
  {
    $$ = "";
  }
  ;

choice
  : OPENPAR list_choice_plus CLOSEPAR
  {
    $$ = $2;
  }
  ;

list_choice_plus
  : item_card PIPE list_choice
  {
    Serie * choiceSerie = $3;
    choiceSerie.addContenuCompose($1);

    $$ = choiceSerie;
  }
  ;
 
list_choice
  : list_choice PIPE item_card
  {
    Serie * choiceSerie = $1;
    choiceSerie.addContenuCompose($3);

    $$ = choiceSerie;
  }
  | item_card
  {
    // We create a new Choice Serie with this item.
    Choice * choiceSerie = new Choice();
    choiceSerie.addContenuCompose($1);

    $$ = choiceSerie;
  }
  ;
    
sequence
  : OPENPAR list_sequence CLOSEPAR
  {
    $$ = $2;
  }
  ;
 
list_sequence
  : list_sequence COMMA item_card
  {
    Serie * sequenceSerie = $1;
    sequenceSerie.addContenuCompose($2);

    $$ = sequenceSerie;
  }
  | item_card
  {
    Sequence * sequenceSerie = new Sequence();
    sequenceSerie.addContenuCompose($1);

    $$ = sequenceSerie;
  }
  ;
 
mixed
  : OPENPAR PCDATA mixed_content CLOSEPAR AST
  {
    $$ = $3;
  }
  | OPENPAR PCDATA CLOSEPAR
  {
    $$ = new vector<string>();
  }
  ;
 
mixed_content
  : mixed_content PIPE IDENT
  {
    vector<string> * mixed = $1;
    mixed.push_back($3);

    $$ = mixed;
  }
  | IDENT
  {
    vector<string> * mixed = new vector<string>();
    mixed.push_back($1);
  }
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
      Attribute * att = new Attribute();

      att.setAttributeName($1);
      att.setTypes($2);
      att.setDefaultValue($3);

      $$ = att;
  }
  ;

att_type
  : CDATA
  {
    vector<string> * types = new vector<string>();
    types.push_back("CDATA");

    $$ = types;
  }
  | TOKENTYPE
  | enumerate
  {
    $$ = $1;
  }
  ;

enumerate
  : OPENPAR enum_list_plus CLOSEPAR
  {
    $$ = $2;
  }
  ;

enum_list_plus
  : enum_list PIPE item_enum
  {
    vector<string> * types = $1;
    types.push_back($3);

    $$ = $1;
  }
  ;

enum_list
  : item_enum
  {
    vector<string> * types = new vector<string>();
    types.push_back($1);

    $$ = types;
  }              
  | enum_list PIPE item_enum
  {
    vector<string> * types = $1;
    types.push_back($3);

    $$ = types;
  }
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