%{

void yyerror(char *msg);
int yywrap(void);
int yylex(void);
%}

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
int main(int argc, char **argv)
{
  int err;

  yydebug = 1; // pour désactiver l'affichage de l'exécution du parser LALR, commenter cette ligne

  err = yyparse();
  if (err != 0) printf("Parse ended with %d error(s)\n", err);
        else  printf("Parse ended with success\n", err);
  return 0;
}
int yywrap(void)
{
  return 1;
}

void yyerror(char *msg)
{
  fprintf(stderr, "%s\n", msg);
}


