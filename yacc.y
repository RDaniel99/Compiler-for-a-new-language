%{
#include <stdio.h>
#include "Messages.h"
#include "StackMemory.h"

extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}

%token BEG AND OR NOT DEF LR GR LRE GRE END LET CLASS IF FOR WHILE EVAL_FUNC STRUCTURE ID VOID_TYPE INT_TYPE CHAR_TYPE STRING_TYPE BOOL_TYPE BOOL_VALUE STRING_VALUE INT_VALUE CHAR_VALUE FLOAT_TYPE DEFINE ARRAY_TYPE STRLEN_FUNC

%start start
%%

start: declaratii BEG cod_main END declaratii  {printf("Corect\n");}
     | BEG cod_main END declaratii             {printf("Corect\n");}
     | declaratii BEG cod_main END             {printf("Corect\n");}
     | BEG cod_main END                        {printf("Corect\n");}
     ;

declaratii: declaratie_clasa';'
          | declaratie_variabila';'
          | declaratie_functie';'
          | declaratie_clasa';' declaratii
          | declaratie_variabila';' declaratii
          | declaratie_functie';' declaratii
          ;

tip: INT_TYPE
   | BOOL_TYPE
   | FLOAT_TYPE
   | CHAR_TYPE
   | VOID_TYPE
   | ARRAY_TYPE LR tip GR '[' INT_VALUE ']'
   ;

declaratie_clasa: CLASS ID BEG cod_clasa END {printf("declarare clasa\n");}
                ;

cod_clasa:declaratii {printf("codul din clasa\n");}
         ;

declaratie_variabila: LET lista_variabile_declarare
                    ;

lista_variabile_declarare: variabila_tip
               | variabila_tip ',' lista_variabile_declarare
               ;


variabila_tip: ID':'tip
         ;


declaratie_functie: DEF ID '('lista_variabile_declarare')' ':' tip BEG cod_functie END
                  | DEF ID '('')' ':' tip BEG EMPTY END
                  | DEF ID '('lista_variabile_declarare')' ':' tip BEG EMPTY END
                  | DEF ID '('')' ':' tip BEG EMPTY END
                  ;


cod_functie: declaratie_variabila';'
           | statement
           | declaratie_variabila';' cod_functie
           | statement cod_functie
           ;


statement: FOR '('for_params')' BEG cod_functie END
         | WHILE '('conditions')' BEG cod_functie END
         | IF '('conditions')' BEG cod_functie END
         | asignare';'
         | apelare';'
         ;


for_params:asignare ';' condition';'asignare
          ;


conditions: condition
          | condition logical_operator conditions
          ;


condition: BOOL_VALUE
         | ID
         | apelare
         ;


logical_operator: AND
                | OR
                | NOT
                | LRE
                | GRE
                | LR
                | GR
                ;


asignare: ID '=' value
        | ID '=' ID
        | ID '=' apelare
        | ID '=' classContent
        ;


classContent: ID'.'ID
            | ID'.'classContent
            | ID'.'apelare
            ;


apelare: ID '(' ')'           {printf("Apelat %d\n",$1);}
       | ID '('list_parametri')'
       ;


list_parametri: parametru
              | parametru',' list_parametri
              ;

parametru: value
         | ID
         | apelare
         ;

value: INT_VALUE
     | STRING_VALUE
     | CHAR_VALUE
     | BOOL_VALUE
     ;

EMPTY:
     ; 

TODO:    {printf("NOT IMPLEMENTED\n");}
    ;


cod_main: EMPTY
        | cod_functie
        ;


%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 

