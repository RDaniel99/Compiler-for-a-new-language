%{
#include <stdio.h>
#include "y.tab.h"
#include "shared.h"
%}
%option noyywrap
%%

"/\*(.|\n)+\*/" ; 

"endDef" {scoateMem(); return ENDDEF; }
"begin" {printf("BEGIN FOUND\n"); return BEG; }
"def"   {adaugaMem(); return DEF;}
"end"   {printf("END FOUND\n"); return END;}
"And"   {return AND;}
"Or"    {return OR;}
"Not"   {return NOT;}
"Let"   {return LET;}
"Define" {return DEFINE;}
"Class"  {return CLASS;}
"Array" {return ARRAY_TYPE;}
"Int" {return INT_TYPE;}
"Bool" {return BOOL_TYPE;}
"String" {return STRING_TYPE;}
"Char" {return CHAR_TYPE;}
"Float" {return FLOAT_TYPE;}
"Void"  {return VOID_TYPE;}
"Structure" {return STRUCTURE;}
"if" {return IF;}
"for" {return FOR;}
"while" {return WHILE;}


"strlen" {return STRLEN_FUNC;}
"eval" {return EVAL_FUNC;}

"<"    {return LR;}
">"    {return GR;}
"<="   {return LRE;}
">="   {return GRE;}

"True"|"False" { yylval.strval=strdup(yytext); return BOOL_VALUE;}
\"[^\"]+\" { yylval.strval=strdup(yytext); return STRING_VALUE;}
[1-9][0-9]*|0 {yylval.strval=strdup(yytext); return INT_VALUE;}
'.' {return CHAR_VALUE;}
-?[1-9][0-9]*\.[0-9]*|-?0\.[0-9]* {
                                     yylval.strval=strdup(yytext);
                                     return FLOAT_VALUE;}

[A-Za-z][A-Za-z0-9]* {
                        yylval.strval=strdup(yytext);
                        if(GetIsInFunction)
                        {
                           SetCurrentFunctionName(yytext);
                        }
                        return ID;
                     }
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
