/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
    BEG = 258,
    AND = 259,
    OR = 260,
    NOT = 261,
    DEF = 262,
    END = 263,
    LET = 264,
    CLASS = 265,
    IF = 266,
    FOR = 267,
    WHILE = 268,
    EVAL_FUNC = 269,
    STRUCTURE = 270,
    ID = 271,
    INT_TYPE = 272,
    CHAR_TYPE = 273,
    STRING_TYPE = 274,
    BOOL_TYPE = 275,
    BOOL_VALUE = 276,
    STRING_VALUE = 277,
    INT_VALUE = 278,
    CHAR_VALUE = 279,
    FLOAT_TYPE = 280,
    DEFINE = 281,
    ARRAY_TYPE = 282,
    STRLEN_FUNC = 283
  };
#endif
/* Tokens.  */
#define BEG 258
#define AND 259
#define OR 260
#define NOT 261
#define DEF 262
#define END 263
#define LET 264
#define CLASS 265
#define IF 266
#define FOR 267
#define WHILE 268
#define EVAL_FUNC 269
#define STRUCTURE 270
#define ID 271
#define INT_TYPE 272
#define CHAR_TYPE 273
#define STRING_TYPE 274
#define BOOL_TYPE 275
#define BOOL_VALUE 276
#define STRING_VALUE 277
#define INT_VALUE 278
#define CHAR_VALUE 279
#define FLOAT_TYPE 280
#define DEFINE 281
#define ARRAY_TYPE 282
#define STRLEN_FUNC 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
