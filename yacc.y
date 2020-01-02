%{
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

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

%token BEG AND OR NOT DEF LR GR LRE GRE END LET CLASS IF FOR WHILE EVAL_FUNC STRUCTURE VOID_TYPE INT_TYPE CHAR_TYPE STRING_TYPE BOOL_TYPE FLOAT_TYPE DEFINE ARRAY_TYPE STRLEN_FUNC

%type<strval> variabila_tip
%type<strval> lista_variabile_declarare
%type<strval> list_parametri
%type<strval> tip
%type<strval> class_type
%type<strval> classContent
%type<strval> classApelare
%type<strval> value
%type<strval> asignare
%type<strval> apelare
%type<strval> parametru
%type<intval> expr

%left '+' '-'
%left '*' '/'

%token<strval> BOOL_VALUE
%token<strval> STRING_VALUE
%token<strval> INT_VALUE
%token<strval> FLOAT_VALUE
%token<strval> CHAR_VALUE

%start start
%%



start: declaratii BEG cod_main END';' declaratii  {printf("Corect\n");}
     | BEG cod_main END';' declaratii             {printf("Corect\n");}
     | declaratii BEG cod_main END';'             {printf("Corect\n");}
     | BEG cod_main END';'                        {printf("Corect\n");}
     ;

expr : expr '+' expr { $$ = $1 + $3; } 
| expr '-' expr { $$ = $1 - $3; } 
| expr '*' expr { $$ = $1 * $3; } 
| expr '/' expr { $$ = $1 / $3; } 
| '-' INT_VALUE { $$ = -atoi($2); } 
| '-' ID { $$ = 0; } 
| '(' expr ')' { $$ = $2; } 
| INT_VALUE { $$ = atoi($1); } 
| ID { $$ = 0; }; 
;


declaratii: declaratie_clasa';'
          | declaratie_variabila';'
          | declaratie_functie';'
          | declaratie_clasa';' declaratii
          | declaratie_variabila';' declaratii
          | declaratie_functie';' declaratii
          ;

tip: INT_TYPE                                     {$$="INT";}
   | BOOL_TYPE                                    {$$="BOOL";}
   | FLOAT_TYPE                                   {$$="FLOAT";}
   | CHAR_TYPE                                    {$$="CHAR";}
   | VOID_TYPE                                    {$$="VOID";}
   | ARRAY_TYPE LR tip GR '[' INT_VALUE ']'       {$$="ARRAY";}
   | class_type                                   {$$=$1;}
   ;

class_type: ID {$$=$1; printf("de verificat daca exista clasa \n");}
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
                    char aux2[]=":";
                    strcat($$,aux);
                    strcat($$,$3);                  
               }
               ;


variabila_tip: ID':'tip
               {
                    char* aux =(char*) malloc(1024);
                    sprintf(aux,"%s:%s",$$,$3);
                    $$=aux;
                    
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
                       printf("functia %s declarata cu tipul %s si parametrii %s\n",$2,$7,$4);
                  }
                  | DEF ID '('')' ':' tip BEG EMPTY END                                
                  {
                         ///DECLARARE TODO
                       printf("functia %s declarata cu tipul %s fara parametri\n",$2,$6);
                  }
                  | DEF ID '('lista_variabile_declarare')' ':' tip BEG EMPTY END       
                  { 
                          ///DECLARARE TODO
                       printf("functia %s declarata cu tipul %s si parametrii %s\n",$2,$7,$4);
                  }
                  | DEF ID '('')' ':' tip BEG cod_functie END                          
                  { 
                     ///DECLARARE TODO
                       printf("functia %s declarata cu tipul %s fara parametri\n",$2,$6);
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
         | classApelare';'
         ;


for_params:asignare ';' condition';'asignare {}
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


///TODO: de verificat tipurile si daca ID este valid
asignare: ID '=' value                       {printf(" 1 | %s<-%s\n",$1,$3);}
        | ID '=' ID                          {printf(" 2 | %s<-%s\n",$1,$3);}
        | ID '=' apelare                     {printf(" 3 | %s<-%s\n",$1,$3);}
        | ID '=' classApelare                {printf(" 4 | %s<-%s\n",$1,$3);}
        | ID '=' classContent                {printf(" 5 | %s<-%s\n",$1,$3);}
        | classContent '=' value             {printf(" 6 | %s<-%s\n",$1,$3);}
        | classContent '=' ID                {printf(" 7 | %s<-%s\n",$1,$3);}
        | classContent '=' apelare           {printf(" 8 | %s<-%s\n",$1,$3);}
        | classContent '=' classApelare      {printf(" 9 | %s<-%s\n",$1,$3);}
        | classContent '=' classContent      {printf("10 | %s<-%s\n",$1,$3);}
        ;



classContent: ID'.'ID
               {
                    strcat($$,".");
                    strcat($$,$3);
               }
            | ID'.'classContent    
               {
                    strcat($$,".");
                    strcat($$,$3);
               }
            ;

classApelare: ID'.'classApelare
               {
                    strcat($$,".");
                    strcat($$,$3);
               }
            | ID'.'apelare
               {
                    strcat($$,".");
                    strcat($$,$3);
               }
            ;

       apelare: ID '(' ')'         {strcat($$,"()");}
       | ID '('list_parametri')'   {strcat($$,"(");strcat($$,$3);strcat($$,")");}
       | EVAL_FUNC '('expr')'      {printf("valoarea este: %d\n",$3);}
       ;


list_parametri: parametru          {}
              | parametru',' list_parametri {strcat($$,",");strcat($$,$3);}
              ;

parametru: value   {$$=strdup($1);}
         | ID      {$$=strdup($1);}
         | apelare {$$=strdup($1);}
         | classApelare {$$=strdup($1);}
         | classContent {$$=strdup($1);}
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

