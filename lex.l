%{
#include <stdio.h>
#include "y.tab.h"
%}
%option noyywrap
%%

"/\*(.|\n)+\*/" ; 

"int" {return INT_TYPE;}
"bool" {return BOOL_TYPE;}
"string" {return STRING_TYPE;}
"char" {return CHAR_TYPE;}
"float" {return FLOAT_TYPE;}

"true"|"false" {return BOOL_VALUE;}

[A-Za-z][A-Za-z0-9]* {return ID;}
-?[1-9][0-9]*|0 {return NR;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}