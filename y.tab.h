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
    ENDCLASS = 260,
    BEG = 261,
    AND = 262,
    OR = 263,
    NOT = 264,
    DEF = 265,
    LR = 266,
    GR = 267,
    LRE = 268,
    GRE = 269,
    END = 270,
    LET = 271,
    CLASS = 272,
    IF = 273,
    FOR = 274,
    WHILE = 275,
    EVAL_FUNC = 276,
    STRUCTURE = 277,
    VOID_TYPE = 278,
    INT_TYPE = 279,
    CHAR_TYPE = 280,
    STRING_TYPE = 281,
    BOOL_TYPE = 282,
    FLOAT_TYPE = 283,
    DEFINE = 284,
    ARRAY_TYPE = 285,
    STRLEN_FUNC = 286,
    BOOL_VALUE = 287,
    STRING_VALUE = 288,
    INT_VALUE = 289,
    FLOAT_VALUE = 290,
    CHAR_VALUE = 291
  };
#endif
/* Tokens.  */
#define ID 258
#define ENDDEF 259
#define ENDCLASS 260
#define BEG 261
#define AND 262
#define OR 263
#define NOT 264
#define DEF 265
#define LR 266
#define GR 267
#define LRE 268
#define GRE 269
#define END 270
#define LET 271
#define CLASS 272
#define IF 273
#define FOR 274
#define WHILE 275
#define EVAL_FUNC 276
#define STRUCTURE 277
#define VOID_TYPE 278
#define INT_TYPE 279
#define CHAR_TYPE 280
#define STRING_TYPE 281
#define BOOL_TYPE 282
#define FLOAT_TYPE 283
#define DEFINE 284
#define ARRAY_TYPE 285
#define STRLEN_FUNC 286
#define BOOL_VALUE 287
#define STRING_VALUE 288
#define INT_VALUE 289
#define FLOAT_VALUE 290
#define CHAR_VALUE 291

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 40 "yacc.y" /* yacc.c:1921  */

float       floatval;
int         intval;
char*       strval;

#line 136 "y.tab.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
