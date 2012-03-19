%{

using namespace std;
#include <ctype.h>
#include <string.h>
#include "../../includes/common.h"
#include "../model/Document.h"

void xmlerror(Document **xdoc, char *msg);
int xmllex(void);

%}

%parse-param { Document **xdoc }

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
 : DOCTYPE IDENT IDENT STRING CLOSE { *xdoc = new Document(); }
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

void xmlerror(Document **xdoc, char *msg)
{
  fprintf(stderr, "%s\n", msg);
}