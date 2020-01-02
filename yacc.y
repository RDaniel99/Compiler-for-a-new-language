%{
#include <stdio.h>
#include <iostream>

#include "y.tab.h"

#include "Messages.h"
#include "StackMemory.h"
#include "Converter.h"

typedef struct expr_info {
	int intvalue;
        char* strvalue;
	int type;
} expr_info;

expr_info* create_int_expr(int value);
expr_info* create_str_expr(char* value1, char* value2);
void free_expr(expr_info* expr);
void print_expr(expr_info* expr); 

extern FILE* yyin;

extern char* yytext;
extern int yylineno;

extern int yylex (void);

StackMemory memory;

int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
return 1;
}

%}

%union {
float       floatval;
int         intval;
char*       strval;
}

%token <strval> ID

%token BEG AND OR NOT DEF LR GR LRE GRE END LET CLASS IF FOR WHILE EVAL_FUNC STRUCTURE VOID_TYPE INT_TYPE CHAR_TYPE STRING_TYPE BOOL_TYPE BOOL_VALUE STRING_VALUE INT_VALUE CHAR_VALUE FLOAT_TYPE DEFINE ARRAY_TYPE STRLEN_FUNC

%type<strval> variabila_tip
%type<strval> lista_variabile_declarare
%type<strval> tip

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

declaratie_clasa: CLASS ID BEG cod_clasa END   { }
                ;

cod_clasa:declaratii 
         ;

declaratie_variabila: LET lista_variabile_declarare {printf("au fost declarate variabilele: %s\n",$2);}
                    ;

lista_variabile_declarare: variabila_tip 
                         {
                         }
               | variabila_tip ',' lista_variabile_declarare 
               {
                    char aux[]=",";
                    strcat($$,aux);
                    strcat($$,$3);                    
               }
               ;


variabila_tip: ID':'tip
               {
                    variabila v;
                    v.nume    = std::string($1);
                    v.tip     = std::string($3);
                    v.valoare = "";
                    ///DECLARARE TODO
                    printf("variabila %s de tipul %s declarata\n",$1,$3);
               }
         ;

declaratie_functie: DEF ID '('lista_variabile_declarare')' ':' tip BEG cod_functie END 
                  { 
                       ///DECLARARE TODO
                       printf("functia %s declarata\n",$2);
                  }
                  | DEF ID '('')' ':' tip BEG EMPTY END                                
                  {
                         ///DECLARARE TODO
                        printf("functia %s declarata\n",$2);
                  }
                  | DEF ID '('lista_variabile_declarare')' ':' tip BEG EMPTY END       
                  { 
                          ///DECLARARE TODO
                       printf("functia %s declarata\n",$2);
                  }
                  | DEF ID '('')' ':' tip BEG cod_functie END                          
                  { 
                     ///DECLARARE TODO
                       printf("functia %s declarata\n",$2);
                  }
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


asignare: ID '=' value                       {    }
        | ID '=' ID                          {    }
        | ID '=' apelare                     {    }
        | ID '=' classApelare                {    }
        | ID '=' classContent                {    }
        | classContent '=' value             {    }
        | classContent '=' ID                {    }
        | classContent '=' apelare           {    }
        | classContent '=' classApelare      {    }
        | classContent '=' classContent      {    }
        ;



classContent: ID'.'ID
            | ID'.'classContent
            ;

classApelare: ID'.'classContent
            | ID'.'apelare
            ;

       apelare: ID '(' ')'           
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



cod_main: EMPTY
        | cod_functie
        ;


%%

#include <iostream>  

int main(int argc, char** argv){

yyin=fopen(argv[1],"r");
yyparse();
} 

