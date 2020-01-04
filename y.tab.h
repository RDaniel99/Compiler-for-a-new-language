/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    ENDDEF = 259,
    BEG = 260,
    AND = 261,
    OR = 262,
    NOT = 263,
    DEF = 264,
    LR = 265,
    GR = 266,
    LRE = 267,
    GRE = 268,
    END = 269,
    LET = 270,
    CLASS = 271,
    IF = 272,
    FOR = 273,
    WHILE = 274,
    EVAL_FUNC = 275,
    STRUCTURE = 276,
    VOID_TYPE = 277,
    INT_TYPE = 278,
    CHAR_TYPE = 279,
    STRING_TYPE = 280,
    BOOL_TYPE = 281,
    FLOAT_TYPE = 282,
    DEFINE = 283,
    ARRAY_TYPE = 284,
    STRLEN_FUNC = 285,
    BOOL_VALUE = 286,
    STRING_VALUE = 287,
    INT_VALUE = 288,
    FLOAT_VALUE = 289,
    CHAR_VALUE = 290
  };
#endif
/* Tokens.  */
#define ID 258
#define ENDDEF 259
#define BEG 260
#define AND 261
#define OR 262
#define NOT 263
#define DEF 264
#define LR 265
#define GR 266
#define LRE 267
#define GRE 268
#define END 269
#define LET 270
#define CLASS 271
#define IF 272
#define FOR 273
#define WHILE 274
#define EVAL_FUNC 275
#define STRUCTURE 276
#define VOID_TYPE 277
#define INT_TYPE 278
#define CHAR_TYPE 279
#define STRING_TYPE 280
#define BOOL_TYPE 281
#define FLOAT_TYPE 282
#define DEFINE 283
#define ARRAY_TYPE 284
#define STRLEN_FUNC 285
#define BOOL_VALUE 286
#define STRING_VALUE 287
#define INT_VALUE 288
#define FLOAT_VALUE 289
#define CHAR_VALUE 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 40 "yacc.y" /* yacc.c:1921  */

float       floatval;
int         intval;
char*       strval;

#line 134 "y.tab.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
