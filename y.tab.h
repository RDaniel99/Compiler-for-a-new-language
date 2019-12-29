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
    BEG = 258,
    IF = 259,
    FOR = 260,
    WHILE = 261,
    EVAL_FUNC = 262,
    STRUCTURE = 263,
    ID = 264,
    INT_TYPE = 265,
    FLOAT_TYPE = 266,
    CHAR_TYPE = 267,
    STRING_TYPE = 268,
    BOOL_TYPE = 269,
    BOOL_VALUE = 270,
    STRING_VALUE = 271,
    INT_VALUE = 272,
    CHAR_VALUE = 273,
    DEFINE = 274,
    ARRAY_TYPE = 275,
    STRLEN_FUNC = 276
  };
#endif
/* Tokens.  */
#define BEG 258
#define IF 259
#define FOR 260
#define WHILE 261
#define EVAL_FUNC 262
#define STRUCTURE 263
#define ID 264
#define INT_TYPE 265
#define FLOAT_TYPE 266
#define CHAR_TYPE 267
#define STRING_TYPE 268
#define BOOL_TYPE 269
#define BOOL_VALUE 270
#define STRING_VALUE 271
#define INT_VALUE 272
#define CHAR_VALUE 273
#define DEFINE 274
#define ARRAY_TYPE 275
#define STRLEN_FUNC 276

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
