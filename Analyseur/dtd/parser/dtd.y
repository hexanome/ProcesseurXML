%{

using namespace std;
#include <ctype.h>
#include <string.h>
#include "../../includes/common.h"
#include "../model/Document.h"

void dtderror(char *msg);
int dtdlex(void);
  
%}

%error-verbose
%parse-param { Document **ddoc }

%union {
  char *s;
}

%token ELEMENT ATTLIST CLOSE OPENPAR CLOSEPAR COMMA PIPE FIXED EMPTY ANY PCDATA AST QMARK PLUS CDATA
%token <s> IDENT TOKENTYPE DECLARATION STRING
%%

main: dtd_list_opt
    ;

dtd_list_opt
: dtd_list_opt ELEMENT IDENT content_spec CLOSE
| dtd_list_opt ATTLIST IDENT att_definition_opt CLOSE            
| /* empty */                     
;

content_spec
 : ANY
 | EMPTY
 | mixed
 | children
 ;

children
 : choice card
 | sequence card
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
| /* empty */
;

attribute
: IDENT att_type default_declaration
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