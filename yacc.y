%{
#include <stdio.h>

extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}
%token ID NR INT_TYPE FLOAT_TYPE CHAR_TYPE STRING_TYPE BOOL_TYPE BOOL_VALUE
%start start
%%

start: {printf("Corect\n");}
     ;
%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 

