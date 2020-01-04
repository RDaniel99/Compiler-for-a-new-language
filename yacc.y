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



start: declaratii
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

class_type: ID 
               {
                    $$=$1; 
                    clasa c;
                    c.nume = std::string($1);
                    if(existaClasa(c))
                         printf("Clasa %s a fost gasita.\n");
                    else
                    {
                         M_ERROR_NOT_EXISTS_CLASS
                         exit(0);
                    }
               }
          ;

declaratie_clasa: CLASS ID BEG cod_clasa ENDCLASS   
               { 
                    clasa c;
                    c.nume = std::string($2);
                    c.membrii.clear();
                    c.functii.clear();

                    // To do: de adaugat membrii si functii
                    if(adaugaClasa(c))
                         printf("Clasa %s a fost adaugata.\n", $2);
                    else
                    {
                         printf("Clasa %s n-a fost adaugata.\n", $2);
                         M_ERROR_EXISTS_CLASS
                         exit(0);
                    }
               }
                ;

cod_clasa:declaratii 
         ;

declaratie_variabila: LET lista_variabile_declarare 
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
                    if(GetCurrentClassName())
                         std::cout<<"clasa: "<<GetCurrentClassName()<<"\n";
                    if(GetCurrentFunctionName())
                         std::cout<<"\n functia: "<<GetCurrentFunctionName()<<"\n";

                    std::string pre="";
                    if(GetIsInClass())
                    {
                         if(GetIsInFunction()==0)
                         {
                              pre=std::string(GetCurrentClassName())+std::string("::");
                         }
                    }
               
                    char* aux =(char*) malloc(1024);
                    sprintf(aux,"%s:%s",$$,$3);
                    $$=aux;
                    
                    variabila v;
                    v.nume    = pre+std::string($1);
                    v.tip     = std::string($3);
                    v.valoare = "";
                    if(adaugaVar(v))
                    {
                         printf("variabila %s de tipul %s declarata\n",v.nume.c_str(),$3);
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
                       std::string pre;
                       if(GetIsInClass())
                       {
                            pre=std::string( GetCurrentClassName());
                            pre=pre+std::string(".");
                       }

                       functie f;
                       f.nume = pre+std::string($2);
                       f.returnType = std::string($7);
                       adaugaParams(f, std::string($4));
                       if(adaugaFunc(f))
                         printf("functia %s declarata cu tipul %s si parametrii %s\n",$2,$7,$4);
                       else
                       {
                         printf("functia %s nu a fost declarata cu tipul %s si parametrii %s", $2, $7, $4);
                         M_ERROR_EXISTS_FUNC
                         exit(0);
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
                         printf("functia %s declarata cu tipul %s fara parametri\n",$2, $6);
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
                         printf("functia %s declarata cu tipul %s si parametrii %s\n",$2,$7,$4);
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
                         printf("functia %s declarata cu tipul %s fara parametri\n",$2,$6);
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
asignare: ID '=' value                       
          {
               printf(" 1 | %s<-%s\n",$1,$3);
               variabila v;
               v.nume = std::string($1);
               if(existaVar(v))
               {
                    v.valoare = std::string($3);
                    modifica(v);
                    printf("Noua valoare pt %s este: %s\n", v.nume.c_str(), v.valoare.c_str());
               }
               else
               {
                    M_ERROR_NOT_EXISTS_VAR
                    exit(0);
               }
          }
        | ID '=' ID                          
          {
             printf(" 2 | %s<-%s\n",$1,$3);
             variabila v1;
             variabila v2;
             v1.nume = std::string($1);
             v2.nume = std::string($3);
             if(existaVar(v1) && existaVar(v2))
             {
                  printf("Variabilele exista:\n");
                  printf("Var1Name: %s, Var1Tip: %s, Var1Valoare: %s\n", v1.nume.c_str(), v1.tip.c_str(), v1.valoare.c_str());
                  printf("Var2Name: %s, Var2Tip: %s, Var2Valoare: %s\n", v2.nume.c_str(), v2.tip.c_str(), v2.valoare.c_str());
                  if(v1.tip == v2.tip && v2.valoare != "")
                  {
                       printf("Asignare corecta\n");
                       modifica(v2);
                       printf("Noua valoare pt %s este: %s\n", v1.nume.c_str(), v1.valoare.c_str());
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
             printf(" 3 | %s<-%s\n",$1,$3);
             variabila v;
             std::string str = std::string($3);
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

             if(b == 1 && existaVar(v) && existaFunc(f))
             {
                  if(v.tip == f.returnType)
                  {
                       printf("Asignare corecta\n");
                  }
                  else
                  {
                       printf("Asignare gresita\n");
                       exit(0);
                  }
             }
          }
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
                         printf("Apel corect functie fara params\n");
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
            strcat($$,"(");strcat($$,$3);strcat($$,")");
            functie f;
            f.nume = std::string($1);
            f.returnType = "";
            f.parametrii.clear();
            adaugaParams(f, std::string($3));
            if(existaFunc(f))
            {
                 printf("Apel corect al functiei cu params\n");
            }
            else
            {
                 printf("Error: Numar incorect de parametrii\n");
                 exit(0);
            }
          }
       | EVAL_FUNC '('expr')'      {if(strcmp("main",GetCurrentFunctionName())==0) printf("valoarea este: %d\n",$3);}
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

%%

#include <iostream>  
#include "shared.h"

int main(int argc, char** argv){

StackMemory memory;
SetMemory(memory);
adaugaMem();
std::cout<<"1\n";
SetIsInFunction(false);
SetCurrentFunctionName(nullptr);
std::cout<<"123\n";
SetIsInClass(false);
SetCurrentClassName(nullptr);
std::cout<<"123\n";

yyin=fopen(argv[1],"r");
yyparse();
} 

