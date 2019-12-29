%{
#include <stdio.h>
#include "y.tab.h"
%}
%option noyywrap
%%

"/\*(.|\n)+\*/" ; 

"begin" {return BEG;}
"int" {return INT_TYPE;}
"bool" {return BOOL_TYPE;}
"string" {return STRING_TYPE;}
"char" {return CHAR_TYPE;}
"float" {return FLOAT_TYPE;}
"structure" {return STRUCTURE;}
"Eval" {return EVAL;}
"if" {return IF;}
"for" {return FOR;}
"while" {return WHILE;}

"true"|"false" {return BOOL_VALUE;}
\"[^\"]+\" {return STRING_VALUE;}
-?[1-9][0-9]*|0 {return INT_VALUE;}
'.' {return CHAR_VALUE;}
-?[1-9][0-9]*\.[0-9]*|-?0\.[0-9]* {return FLOAT_TYPE;}

[A-Za-z][A-Za-z0-9]* {return ID;}
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
