%{
#include <stdio.h>
#include "y.tab.h"
#include "shared.h"

int aux=0;
int aux2=0;

%}
%option noyywrap
%%

"/\*(.|\n)+\*/" ; 

"endDef"   {SetIsInFunction(false); SetCurrentFunctionName(nullptr); scoateMem(); return ENDDEF;   }
"endClass" {SetIsInClass(false);    SetCurrentClassName(nullptr);               return ENDCLASS; }

"begin" { if(aux==2 || aux2==2) {aux=0;aux2=0;}else{adaugaMem(); std::cout<<"Memorie noua la linia "<<yylineno<<"\n";}return BEG;}
"end"   { scoateMem(); return END;}
"def"   {SetIsInFunction(true);aux=1;adaugaMem(); return DEF;}
"And"   {return AND;}
"Or"    {return OR;}
"Not"   {return NOT;}
"Let"   {return LET;}
"Define" {return DEFINE;}
"Class"  {SetIsInClass(true); aux2=1; SetCurrentClassName(nullptr);                      return CLASS;}
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

([A-Za-z][A-Za-z0-9]*\.[A-Za-z][A-Za-z0-9]*)*|[A-Za-z][A-Za-z0-9]* {
                        yylval.strval=strdup(yytext);
                        if(GetIsInFunction()==true && aux==1)
                        {
                           SetCurrentFunctionName(yytext);
                           aux=2;
                        }
                        if(GetIsInClass()==true && aux2==1)
                        {
                           SetCurrentClassName(yytext);
                           clasa c;
                           c.nume = std::string(yytext);
                           c.membrii.clear();
                           c.functii.clear();
                           
                           if(adaugaClasa(c))
                           {

                           }
                           else
                           {
                                 printf("Clasa %s n-a fost adaugata.\n", yytext);
                                 exit(0);
                           }

                           aux2=2;
                        }
                        return ID;
                     }
[ \t] ;
\n {yylineno++;}
. {return yytext[0];}
