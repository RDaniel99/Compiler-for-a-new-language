%{
#include <stdio.h>
#include <iostream>

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

int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

%}
%union {
int intval;
char* strval;
struct expr_info* expr_ptr;
}

%token <strval> ID

%token<strval> BEG AND OR NOT DEF LR GR LRE GRE END LET CLASS IF FOR WHILE EVAL_FUNC STRUCTURE VOID_TYPE INT_TYPE CHAR_TYPE STRING_TYPE BOOL_TYPE BOOL_VALUE STRING_VALUE INT_VALUE CHAR_VALUE FLOAT_TYPE DEFINE ARRAY_TYPE STRLEN_FUNC



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

declaratie_clasa: CLASS ID BEG cod_clasa END 
                ;

cod_clasa:declaratii 
         ;

declaratie_variabila: LET lista_variabile_declarare
                    ;

lista_variabile_declarare: variabila_tip{printf("ultima variabila de pe linia %d  declarata\n",yylineno);}
               | variabila_tip ',' lista_variabile_declarare {printf("variabila declarata pe linia %d\n",yylineno);}
               ;


variabila_tip: ID':'tip
               {
                    std::cout << $1 <<" Declarata" <<'\n';
               }
         ;


declaratie_functie: DEF ID '('lista_variabile_declarare')' ':' tip BEG cod_functie END
                  | DEF ID '('')' ':' tip BEG EMPTY END
                  | DEF ID '('lista_variabile_declarare')' ':' tip BEG EMPTY END
                  | DEF ID '('')' ':' tip BEG cod_functie END
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


asignare: ID '=' value {std::cout<<$1<<"asignare\n";}
        | ID '=' ID
        | ID '=' apelare
        | ID '=' classContent
        ;


classContent: ID'.'ID
            | ID'.'classContent
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

expr_info* create_int_expr(int value)
{
       
   expr_info* expr = (expr_info*)malloc(sizeof(expr_info));
   expr->intvalue = value;
   expr->type = 1;
   return expr;
}

expr_info* create_str_expr(char* value1, char* value2) 
{
   expr_info* expr = (expr_info*)malloc(sizeof(expr_info));
   int len2 = value2 ? strlen(value2) : 0;
   expr->strvalue = (char*) malloc(sizeof(char)*(strlen(value1) + len2 +1)); 
   strcpy(expr->strvalue, value1);
   if(value2)
   {
      strcat(expr->strvalue, value2);
   }
   expr->type = 2;
   return expr;
		
}

void free_expr(expr_info* expr)
{
  if(expr->type == 2)
  {
     free(expr->strvalue);
  }
  free(expr);
}


void print_expr(expr_info* expr)
{
   if(expr->type == 1) 
   {
	printf("Int expr with value:%d",expr->intvalue);
   }
   else
   {
	printf("Str expr with value:%s", expr->strvalue);	
   }	
}

StackMemory memory;

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
} 

