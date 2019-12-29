%{
#include <stdio.h>

extern FILE* yyin;
extern char* yytext;
extern int yylineno;
%}
%token BEG DEF END LET CLASS IF FOR WHILE EVAL_FUNC STRUCTURE ID INT_TYPE FLOAT_TYPE CHAR_TYPE STRING_TYPE BOOL_TYPE BOOL_VALUE STRING_VALUE INT_VALUE CHAR_VALUE FLOAT_TYPE DEFINE ARRAY_TYPE STRLEN_FUNC

%start start
%%

start: declaratii BEG cod_main END declaratii  {printf("Corect\n");}
     | BEG cod_main END declaratii             {printf("Corect\n");}
     | declaratii BEG cod_main END             {printf("Corect\n");}
     | BEG cod_main END                        {printf("Corect\n");}
     ;

declaratii: declaratie_clasa 
          | declaratie_variabila
          | declaratie_functie
          | declaratie_clasa declaratii
          | declaratie_variabila declaratii
          | declaratie_functie declaratii
          ;

tip: INT_TYPE
   | BOOL_TYPE
   | FLOAT_TYPE
   | CHAR_TYPE
   ;

declaratie_clasa: CLASS ID BEG cod_clasa END
                ;

cod_clasa:declaratii
         ;

declaratie_variabila: LET lista_variabile_declarare ';'
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


cod_functie: declaratie_variabila 
           | statement
           | declaratie_variabila cod_functie
           | statement cod_functie
           ;

statement: FOR BEG cod_functie END
         | WHILE BEG cod_functie END
         | IF BEG cod_functie END
         | asignare
         | apelare 
         ;

asignare: ID '=' value';'
        | ID '=' ID';'
        | ID '=' apelare
        ;

apelare: ID '(' ')' ';'
       | ID '('list_parametri')' ';'
       ;

list_parametri: parametru
              | parametru',' list_parametri
              ;
parametru: value
         | ID
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

