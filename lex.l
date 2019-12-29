%{
#include <stdio.h>
#include "y.tab.h"
%}
%option noyywrap
%%

"/\*(.|\n)+\*/" ; 

"begin" {return BEG;}
"Define" {return DEFINE;}
"Array" {return ARRAY_TYPE;}
"Int" {return INT_TYPE;}
"Bool" {return BOOL_TYPE;}
"String" {return STRING_TYPE;}
"Char" {return CHAR_TYPE;}
"Float" {return FLOAT_TYPE;}
"Structure" {return STRUCTURE;}
"if" {return IF;}
"for" {return FOR;}
"while" {return WHILE;}


"strlen" {retrun STRLEN_FUNC;}
"eval" {return EVAL_FUNC;}

"True"|"False" {return BOOL_VALUE;}
\"[^\"]+\" {return STRING_VALUE;}
-?[1-9][0-9]*|0 {return INT_VALUE;}
'.' {return CHAR_VALUE;}
-?[1-9][0-9]*\.[0-9]*|-?0\.[0-9]* {return FLOAT_TYPE;}

[A-Za-z][A-Za-z0-9]* {return ID;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
