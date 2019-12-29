%{
#include <stdio.h>
#include "Memory.h"

extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}
%token BEG END IF FOR WHILE EVAL_FUNC STRUCTURE ID INT_TYPE FLOAT_TYPE CHAR_TYPE STRING_TYPE BOOL_TYPE BOOL_VALUE STRING_VALUE INT_VALUE CHAR_VALUE FLOAT_TYPE DEFINE ARRAY_TYPE STRLEN_FUNC

%start start
%%

start: declaratii BEG cod_main END declaratii{printf("Corect\n");}
     | BEG cod_main END declaratii
     | declaratii BEG cod_main END
     | BEG cod_main END
     ;

declaratii: declaratie_clasa 
          | declaratie_variabila
          | declaratie_functie
          | declaratie_clasa declaratii
          | declaratie_variabila declaratii
          | declaratie_functie declaratii
          ;

declaratie_clasa: TODO
                ;
declaratie_variabila: TODO
                    ;
declaratie_functie: TODO
                  ;
TODO:    {printf("NOT IMPLEMENTED\n");}
    ;

cod_main:
        ;
%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 

