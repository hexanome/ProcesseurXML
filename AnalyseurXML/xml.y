%{

using namespace std;
#include "commun.h"
#include <stdio.h>
#include <string.h>

int xmlwrap(void);
void xmlerror(char** dtd_name,char *msg);
int xmllex(void);

%}

%parse-param {char** dtd_name}

%union {
   char * s;
   ElementName * en;  /* le nom d'un element avec son namespace */
}

%token EQ SLASH CLOSE CLOSESPECIAL DOCTYPE
%token <s> ENCODING STRING DATA COMMENT IDENT NSIDENT
%token <en> NSSTART START STARTSPECIAL END NSEND

%%

document
 : declarations_opt xml_element misc_seq_opt 
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
 ;
 
declaration
 : DOCTYPE IDENT IDENT STRING CLOSE {strcpy (*date_name,$4);}
 ;

xml_element
 : start attributes_opt empty_or_content 
 ;
start
 : START		
 | NSSTART	
 ;
attributes_opt
 : attributes_opt attribute
 | /*empty*/
 ;
attribute
 : IDENT EQ STRING
 ;
empty_or_content
 : SLASH CLOSE	
 | close_content_and_end CLOSE 
 ;
close_content_and_end
 : CLOSE	content_opt END 
 ;
content_opt 
 : content_opt DATA		
 | content_opt comment        
 | content_opt xml_element      
 | /*empty*/         
 ;
%%

int main(int argc, char **argv)
{
  int err;
  char* dtd_name;
  dtd_name = (char*)malloc(50*sizeof(char));
  xmldebug = 1; // pour enlever l'affichage de l'éxécution du parser, commenter cette ligne

  err = xmlparse(&dtd_name);
  if (err != 0) printf("Parse ended with %d error(s)\n", err);
  	else  printf("Parse ended with success\n", err);
  return 0;
}

int xmlwrap(void)
{
  return 1;
}

void xmlerror(char *msg)
{
  fprintf(stderr, "%s\n", msg);
}

