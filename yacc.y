%{
#include <stdio.h>

extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}
%token BEG IF FOR WHILE EVAL_FUNC STRUCTURE ID INT_TYPE FLOAT_TYPE CHAR_TYPE STRING_TYPE BOOL_TYPE BOOL_VALUE STRING_VALUE INT_VALUE CHAR_VALUE FLOAT_TYPE DEFINE ARRAY_TYPE STRLEN_FUNC

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

