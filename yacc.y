%{
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "shared.h"

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

%token ENDDEF ENDCLASS BEG AND OR NOT DEF LR GR LRE GRE END LET CLASS IF FOR WHILE EVAL_FUNC STRUCTURE VOID_TYPE INT_TYPE CHAR_TYPE STRING_TYPE BOOL_TYPE FLOAT_TYPE DEFINE ARRAY_TYPE STRLEN_FUNC

%type<strval> variabila_tip
%type<strval> lista_variabile_declarare
%type<strval> list_parametri
%type<strval> tip
%type<strval> class_type
%type<strval> value
%type<strval> asignare
%type<strval> apelare
%type<strval> parametru
%type<intval> expr
%type<intval> expr2

%type<strval> non_int_value

%left '+' '-'
%left '*' '/'

%token<strval> BOOL_VALUE
%token<strval> STRING_VALUE
%token<strval> INT_VALUE
%token<strval> FLOAT_VALUE
%token<strval> CHAR_VALUE

%start start
%%



start: declaratii
     ;

expr : expr2 '+' expr2 { $$ = $1 + $3; } 
| expr2 '-' expr2 { $$ = $1 - $3; } 
| expr2 '*' expr2 { $$ = $1 * $3; } 
| expr2 '/' expr2 { $$ = $1 / $3; } 
| '(' expr ')' { $$ = $2; } 
;

expr2: expr2 '+' expr2 { $$ = $1 + $3; } 
     | expr2 '-' expr2 { $$ = $1 - $3; } 
     | expr2 '*' expr2 { $$ = $1 * $3; } 
     | expr2 '/' expr2 { $$ = $1 / $3; } 
     | '(' expr ')' { $$ = $2; } 
     |'-'INT_VALUE { $$ = -1*atoi($2); } 
     | '-'ID 
          { 
               $$ = 0; 
               variabila v; 
               v.nume=std::string($2); 
               if(existaVar(v))
               { 
                    if(v.tip==std::string("Int")) 
                    {
                         $$=-1*atoi(v.valoare.c_str());
                    }
               }
               else
               {
                    std::cout<<"variabila "<<v.nume<<" nedeclarata\n";
                    exit(1);
               }
          } 
     | INT_VALUE { $$ = atoi($1);}
     | ID 
          { 
               $$ = 0; 
               variabila v;    
               v.nume=std::string($1);  
               if(existaVar(v))
               {
                    if(v.tip==std::string("Int"))
                    {
                         $$=atoi(v.valoare.c_str());
                    }
               }
               else
               {
                    std::cout<<"variabila "<<v.nume<<" nedeclarata\n";
                    exit(1);
               }
          }
     ;


declaratii: declaratie_clasa';'                    {printTable();std::cout<<"linia "<<yylineno<<"\npress enter to continue"; std::getchar();}
          | declaratie_variabila';'                {printTable();std::cout<<"linia "<<yylineno<<"\npress enter to continue"; std::getchar();}
          | declaratie_functie';'                  {printTable();std::cout<<"linia "<<yylineno<<"\npress enter to continue"; std::getchar();}
          | declaratie_clasa';' declaratii         {printTable();std::cout<<"linia "<<yylineno<<"\npress enter to continue"; std::getchar();}
          | declaratie_variabila';' declaratii     {printTable();std::cout<<"linia "<<yylineno<<"\npress enter to continue"; std::getchar();}
          | declaratie_functie';' declaratii       {printTable();std::cout<<"linia "<<yylineno<<"\npress enter to continue"; std::getchar();}
          ;

tip: INT_TYPE                                     {$$="Int";}
   | BOOL_TYPE                                    {$$="Bool";}
   | FLOAT_TYPE                                   {$$="Float";}
   | CHAR_TYPE                                    {$$="Char";}
   | VOID_TYPE                                    {$$="Void";}
   | STRING_TYPE                                  {$$="String";}
   | ARRAY_TYPE LR tip GR '[' INT_VALUE ']'       {$$="Aarray";}
   | class_type                                   {$$=$1;}
   ;


class_type: ID 
               {
                    $$=$1; 
                    clasa c;
                    c.nume = std::string($1);
                    if(!existaClasa(c))
                    {
                         M_ERROR_NOT_EXISTS_CLASS
                         exit(0);
                    }
               }
          ;

declaratie_clasa: CLASS ID BEG cod_clasa ENDCLASS  
               { 
                   
               }
                ;

cod_clasa:declaratii 
         ;

declaratie_variabila: LET lista_variabile_declarare {printTable();std::cout<<"linia "<<yylineno<<"\npress enter to continue"; std::getchar();}
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
                           
                    clasa c;
                    c.nume=std::string($3);

                    std::string pre="";

                    if(GetIsInClass())
                    {
                         if(GetIsInFunction()==0)
                         {
                              clasa c2;
                              c2.nume=std::string(GetCurrentClassName());

                              variabila v;
                              v.nume    = std::string($1);
                              v.tip     = std::string($3);
                              v.valoare = "";
                              appendToClass(c2,v);

                              pre=std::string(GetCurrentClassName())+std::string("::");
                         }
                    }

                    if(existaClasa(c))
                    {     
                         for (variabila var:c.membrii)
                         {
                              var.nume=std::string($1)+std::string(".")+var.nume;
                              adaugaVar(var);
                         }
                         for (functie fun:c.functii)
                         {
                              fun.nume=std::string($1)+std::string(".")+fun.nume;
                              adaugaFunc(fun);
                         }
                         
                    }
                    else if(c.nume==std::string("String")||c.nume==std::string("Int")||c.nume==std::string("Float")||c.nume==std::string("Char")||c.nume==std::string("Bool")||c.nume==std::string("Void"))
                    {

                    }
                    else
                    {
                         std::cout<<"TIP INEXISTENT\n";
                         exit(0);
                    }
               
                    char aux[1024];
                    sprintf(aux,"%s:%s",$$,$3);
                    $$=strdup(aux);
                    
                    variabila v;
                    v.nume    = pre+std::string($1);
                    v.tip     = std::string($3);
                    v.valoare = "";
                    if(adaugaVar(v))
                    {

                    }
                    else
                    {
                         printf("variabila %s de tipul %s a fost declarata anterior\n", $1, $3);
                         M_ERROR_EXISTS_VAR
                         exit(0);
                    }
               }
         ;

declaratie_functie: DEF ID '('lista_variabile_declarare')' ':' tip BEG cod_functie ENDDEF 
                  { 
                       functie f;
                       f.nume = std::string($2);
                       f.returnType = std::string($7);
                       adaugaParams(f, std::string($4));
                       if(GetIsInClass())
                       {
                            clasa c;
                            c.nume=std::string(GetCurrentClassName());
                            appendToClass(c,f);
                       }
                       else if(adaugaFunc(f))
                       {
                            
                       }    
                       else
                       {
                         printf("functia %s nu a fost declarata cu tipul %s si parametrii %s", $2, $7, $4);
                         M_ERROR_EXISTS_FUNC
                        {printTable();std::cout<<"linia "<<yylineno<<"\npress enter to continue";   std::getchar();} exit(0);
                       }
                  }
                  | DEF ID '('')' ':' tip BEG EMPTY ENDDEF                                
                  {
                       std::string pre;
                       if(GetIsInClass())
                       {
                            pre=std::string( GetCurrentClassName() );
                            pre=pre+std::string(".");                       }

                       functie f;
                       f.nume = pre+std::string($2);
                       f.returnType = std::string($6);
                       f.parametrii.clear();
                       if(adaugaFunc(f))
                       {
                            
                       }
                       else
                       {
                         printf("functia %s nu a fost declarata cu tipul %s fara parametri\n", $2, $6);
                         M_ERROR_EXISTS_FUNC
                         exit(0);
                       }
                  }
                  | DEF ID '('lista_variabile_declarare')' ':' tip BEG EMPTY ENDDEF       
                  { 
                       std::string pre;
                       if(GetIsInClass())
                       {
                            pre=std::string( GetCurrentClassName() );
                            pre=pre+std::string(".");                     
                       }

                       functie f;
                       f.nume = pre+std::string($2);

                       f.returnType = std::string($7);
                       adaugaParams(f, std::string($4));
                       if(adaugaFunc(f))
                       {

                       }  
                       else
                       {
                         printf("functia %s nu a fost declarata cu tipul %s si parametrii %s\n", $2, $7, $4);
                         M_ERROR_EXISTS_FUNC
                         exit(0);
                       }
                  }
                  | DEF ID '('')' ':' tip BEG cod_functie ENDDEF                          
                  { 
                       std::string pre;
                       if(GetIsInClass())
                       {
                            pre=std::string( GetCurrentClassName() );
                            pre=pre+std::string(".");
                       }

                       functie f;
                       f.nume = pre+std::string($2);

                       f.returnType = std::string($6);
                       f.parametrii.clear();
                       if(adaugaFunc(f))
                       {

                       }
                       else
                       {
                         printf("functia %s nu a fost declarata cu tipul %s fara parametri\n", $2, $6);
                         M_ERROR_EXISTS_FUNC
                         exit(0);
                       }
                       
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
         | asignare';' {printTable();std::cout<<"linia "<<yylineno<<"\npress enter to continue";   std::getchar();}
         | apelare';'  {printTable();std::cout<<"linia "<<yylineno<<"\npress enter to continue";   std::getchar();}
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
asignare: ID '=' value                       
          {
               
               variabila v;
               v.nume = std::string($1);
               if(existaVar(v))
               {
                    v.valoare = std::string($3);
                    modifica(v);
               }
               else
               {
                    M_ERROR_NOT_EXISTS_VAR
                    exit(0);
               }
          }
        | ID '=' ID                          
          {
             variabila v1;
             variabila v2;
             v1.nume = std::string($1);
             v2.nume = std::string($3);
             if(existaVar(v1) && existaVar(v2))
             {
                  if(v1.tip == v2.tip && v2.valoare != "")
                  {
                       v1.valoare = v2.valoare;
                       modifica(v1);
                  }
                  else
                  {
                       printf("Asignare gresita!!!\n");
                       exit(0);
                  }
             }
          }
        | ID '=' apelare                     
          {
               /// To-Do: pt eval()
             variabila v;
             std::string str = "";
             str += std::string($3);
             v.nume = std::string($1);
             functie f;
             f.nume = "";
             int b = 0;
             for(int i = 0; i < str.size(); i++)
             {
                  if(str[i] == '(') {
                       b = 1;
                       break;
                  }
                  f.nume += str[i];
             }
             std::string params = "";
             int ord = 0;
             for(int i = 0;i<str.size(); i++)
             {
                    if(str[i] == ')') ord = 0;
                    if(ord) params+=str[i];
                    if(str[i] == '(') ord = 1;
             }

             checkParams(f, params);

             if(b == 1 && existaVar(v))
             {
                  f.returnType = v.tip;

                  if(existaFunc(f))
                  {
                  }
                  else
                  {
                       printf("Asignare gresita\n");
                       exit(0);
                  }
             }
          }
        ;


apelare: ID '(' ')'         
          {

               strcat($$,"()");
               functie f;
               f.nume = std::string($1);
               f.returnType = "";
               f.parametrii.clear();

               if(existaFunc(f))
               {
                    if(f.parametrii.size() == 0)
                    {
                    }
                    else
                    {
                         printf("Error: Numar incorect de parametrii\n");
                         exit(0);
                    }
               }
               else
               {
                    M_ERROR_NOT_EXISTS_FUNC
                    exit(0);
               }
          }
       | ID '('list_parametri')'   
          {
            char* aux=strdup($1);
            $1=aux;
            strcat($$,"(");strcat($$,$3);strcat($$,")");
            functie f;
            f.nume = std::string($1);
            f.returnType = "";
            f.parametrii.clear();
            checkParams(f, std::string($3));
            if(existaFunc(f))
            {
            }
            else
            {
                 printf("Error: Numar incorect de parametrii\n");
                 exit(0);
            }
          }
       | EVAL_FUNC '('expr')'      {if(strcmp("main",GetCurrentFunctionName())==0) printf("Rezultatul evaluarii este: %d\n",$3);}
       ;


list_parametri: parametru          {}
              | parametru',' list_parametri {char aux[1024]; sprintf(aux,"%s,%s",$$,$3);$$=strdup(aux);}
              ;

parametru: non_int_value            {$$=strdup($1);}
         | apelare                  {$$=strdup($1);}
         | ID                       {$$=strdup($1);}
         | expr                     {char aux[30];sprintf(aux,"%d",$1);$$=strdup(aux);}
         ;

value: INT_VALUE    
     | STRING_VALUE 
     | CHAR_VALUE   
     | BOOL_VALUE   
     ;

non_int_value: STRING_VALUE
             | CHAR_VALUE
             | BOOL_VALUE
             ;

EMPTY:
     ; 

%%

#include <iostream>  
#include "shared.h"

int main(int argc, char** argv){

StackMemory memory;
SetMemory(memory);
adaugaMem();
SetIsInFunction(false);
SetCurrentFunctionName(nullptr);
SetIsInClass(false);
SetCurrentClassName(nullptr);

yyin=fopen(argv[1],"r");
yyparse();
} 

