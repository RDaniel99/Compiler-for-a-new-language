/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "yacc.y" /* yacc.c:337  */

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


#line 109 "y.tab.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 40 "yacc.y" /* yacc.c:352  */

float       floatval;
int         intval;
char*       strval;

#line 230 "y.tab.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   185

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

#define YYUNDEFTOK  2
#define YYMAXUTOK   291

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      41,    42,    34,    32,    46,    33,    49,    35,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    47,    43,
       2,    48,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,    45,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    36,    37,    38,
      39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    77,    77,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    92,    93,    94,    95,    96,    97,   100,   101,
     102,   103,   104,   105,   106,   109,   112,   115,   118,   121,
     124,   134,   172,   194,   215,   238,   265,   266,   267,   268,
     272,   273,   274,   275,   276,   277,   281,   285,   286,   290,
     291,   292,   296,   297,   298,   299,   300,   301,   302,   307,
     308,   309,   310,   311,   312,   313,   314,   315,   316,   321,
     326,   333,   338,   345,   346,   347,   351,   352,   355,   356,
     357,   358,   359,   362,   363,   364,   365,   368
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "ENDDEF", "ENDCLASS", "BEG", "AND",
  "OR", "NOT", "DEF", "LR", "GR", "LRE", "GRE", "END", "LET", "CLASS",
  "IF", "FOR", "WHILE", "EVAL_FUNC", "STRUCTURE", "VOID_TYPE", "INT_TYPE",
  "CHAR_TYPE", "STRING_TYPE", "BOOL_TYPE", "FLOAT_TYPE", "DEFINE",
  "ARRAY_TYPE", "STRLEN_FUNC", "'+'", "'-'", "'*'", "'/'", "BOOL_VALUE",
  "STRING_VALUE", "INT_VALUE", "FLOAT_VALUE", "CHAR_VALUE", "'('", "')'",
  "';'", "'['", "']'", "','", "':'", "'='", "'.'", "$accept", "start",
  "expr", "declaratii", "tip", "class_type", "declaratie_clasa",
  "cod_clasa", "declaratie_variabila", "lista_variabile_declarare",
  "variabila_tip", "declaratie_functie", "cod_functie", "statement",
  "for_params", "conditions", "condition", "logical_operator", "asignare",
  "classContent", "classApelare", "apelare", "list_parametri", "parametru",
  "value", "EMPTY", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,    43,    45,    42,    47,   287,   288,   289,   290,
     291,    40,    41,    59,    91,    93,    44,    58,    61,    46
};
# endif

#define YYPACT_NINF -68

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-68)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      85,    23,    26,    28,    44,   -68,    -3,     5,    35,    45,
      34,   -68,    43,   102,   -68,    85,    85,    85,    11,    39,
      26,    85,   -68,   -68,   -68,    59,    74,   -68,   -68,   -68,
     -68,   -68,   -68,   107,   -68,   -68,   -68,   -68,   130,    39,
      79,    39,   -68,   134,    39,   131,    16,   143,   106,    76,
     110,   111,   112,   114,   115,   150,    16,   116,   108,   117,
     118,   153,    16,   124,     9,    18,    20,    40,   160,    40,
      19,    16,   -68,   -68,   -68,    47,   -68,   -68,   -68,   161,
     162,   119,   -16,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   125,   122,   -68,   -16,   -68,   -68,   -68,   -68,   -16,
     -68,   -68,   -68,   128,   -68,   129,   120,   -68,    97,   132,
     127,   133,   -68,    21,   -68,    19,    58,   -68,   -16,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,    67,   166,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,    40,   170,   171,    40,
     172,   -68,   -68,    88,    19,    19,    19,    19,   -68,   -68,
      16,   -68,   135,    16,   136,    16,   -68,   113,   113,   -68,
     -68,   165,   167,   160,   168,   -68,   -68,   -68,   -68
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     2,     0,     0,     0,     0,
       0,    28,    29,     0,     1,    12,    13,    14,     0,     0,
       0,     0,    15,    16,    17,     0,     0,    25,    22,    18,
      21,    19,    20,     0,    31,    24,    30,    27,     0,     0,
       0,     0,    26,     0,     0,     0,    87,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    37,     0,     0,     0,
       0,     0,    87,     0,     0,     0,     0,     0,     0,     0,
       0,    36,    35,    39,    43,     0,    45,    44,    33,     0,
       0,     0,    79,    86,    84,    83,    85,    73,    82,    81,
      80,     0,    76,    78,    60,    63,    62,    61,    59,    69,
      70,    71,    72,    50,    49,     0,    47,    51,     0,     0,
       0,     0,    11,     0,    10,     0,     0,    38,    65,    68,
      67,    66,    64,    32,    34,    23,    74,     0,     0,    52,
      53,    54,    57,    58,    55,    56,     0,     0,     0,     0,
       0,     8,     7,     0,     0,     0,     0,     0,    75,    77,
       0,    48,    69,     0,     0,     0,     9,     3,     4,     5,
       6,     0,     0,     0,     0,    42,    40,    46,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -68,   -68,   -35,   121,   100,   -68,   -68,   -68,    98,    53,
     -68,   -68,   -56,   -68,   -68,   -61,    37,   -68,   -67,   -55,
     -48,   -62,    54,   -68,   -37,   123
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,   116,     5,    34,    35,     6,    38,    54,    11,
      12,     8,    55,    56,   109,   105,   106,   136,    57,    58,
      59,    60,    91,    92,    93,    61
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      73,   110,    90,    97,   102,   107,    79,   107,   111,    88,
      95,   100,    82,   121,    10,   117,    89,    96,   101,    49,
     119,    94,   112,    99,   141,    64,     9,   120,    98,    10,
      53,    13,     2,    66,    50,    51,    52,    53,   122,    53,
      15,    53,    27,   103,    14,    83,    84,    85,    16,    86,
     118,    87,   113,    25,    83,    84,    85,   114,    86,   142,
     115,    53,    28,    29,    30,    90,    31,    32,    53,    33,
      82,    26,    88,    36,   107,   151,   104,   107,    17,    89,
     143,    19,   100,    83,    84,    85,    18,    86,    53,    20,
     144,   145,   146,   147,   161,     1,   167,   162,     7,   164,
     148,     2,     3,    83,    84,    85,    39,    86,    21,   157,
     158,   159,   160,     7,     7,     7,    40,    64,    41,     7,
     144,   145,   146,   147,    65,    66,    44,   129,   130,   131,
     156,   132,   133,   134,   135,    42,    22,    23,    24,    43,
      46,    45,    37,    48,    47,    65,   137,   146,   147,    62,
      63,    67,    68,    69,    72,    70,    75,    78,    71,    74,
      76,    77,    81,   108,   125,   123,   124,   126,   127,    64,
     139,   128,   150,   152,   138,   140,   154,   153,   155,   163,
     165,   149,   166,   168,   137,    80
};

static const yytype_uint8 yycheck[] =
{
      56,    68,    64,    65,    66,    67,    62,    69,    69,    64,
      65,    66,     3,    75,     3,    71,    64,    65,    66,     3,
      75,     3,     3,     3,     3,    41,     3,    75,    65,     3,
      21,     3,    16,    49,    18,    19,    20,    21,    75,    21,
      43,    21,     3,     3,     0,    36,    37,    38,    43,    40,
       3,    42,    33,    42,    36,    37,    38,    38,    40,    38,
      41,    21,    23,    24,    25,   127,    27,    28,    21,    30,
       3,    18,   127,    20,   136,   136,    36,   139,    43,   127,
     115,    47,   137,    36,    37,    38,    41,    40,    21,    46,
      32,    33,    34,    35,   150,    10,   163,   153,     0,   155,
      42,    16,    17,    36,    37,    38,    47,    40,     6,   144,
     145,   146,   147,    15,    16,    17,    42,    41,    11,    21,
      32,    33,    34,    35,    48,    49,    47,     7,     8,     9,
      42,    11,    12,    13,    14,     5,    15,    16,    17,    39,
       6,    41,    21,    12,    44,    48,    49,    34,    35,     6,
      44,    41,    41,    41,     4,    41,    48,     4,    43,    43,
      43,    43,    38,     3,    45,     4,     4,    42,    46,    41,
      43,    42,     6,     3,    42,    42,   139,     6,     6,    43,
      15,   127,    15,    15,    49,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    10,    16,    17,    51,    53,    56,    58,    61,     3,
       3,    59,    60,     3,     0,    43,    43,    43,    41,    47,
      46,     6,    53,    53,    53,    42,    59,     3,    23,    24,
      25,    27,    28,    30,    54,    55,    59,    53,    57,    47,
      42,    11,     5,    54,    47,    54,     6,    54,    12,     3,
      18,    19,    20,    21,    58,    62,    63,    68,    69,    70,
      71,    75,     6,    44,    41,    48,    49,    41,    41,    41,
      41,    43,     4,    62,    43,    48,    43,    43,     4,    62,
      75,    38,     3,    36,    37,    38,    40,    42,    69,    70,
      71,    72,    73,    74,     3,    69,    70,    71,    74,     3,
      69,    70,    71,     3,    36,    65,    66,    71,     3,    64,
      68,    65,     3,    33,    38,    41,    52,    62,     3,    69,
      70,    71,    74,     4,     4,    45,    42,    46,    42,     7,
       8,     9,    11,    12,    13,    14,    67,    49,    42,    43,
      42,     3,    38,    52,    32,    33,    34,    35,    42,    72,
       6,    65,     3,     6,    66,     6,    42,    52,    52,    52,
      52,    62,    62,    43,    62,    15,    15,    68,    15
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    53,    53,    53,    53,    53,    53,    54,    54,
      54,    54,    54,    54,    54,    55,    56,    57,    58,    59,
      59,    60,    61,    61,    61,    61,    62,    62,    62,    62,
      63,    63,    63,    63,    63,    63,    64,    65,    65,    66,
      66,    66,    67,    67,    67,    67,    67,    67,    67,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    69,
      69,    70,    70,    71,    71,    71,    72,    72,    73,    73,
      73,    73,    73,    74,    74,    74,    74,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     3,     3,     3,     3,     2,     2,     3,
       1,     1,     2,     2,     2,     3,     3,     3,     1,     1,
       1,     1,     1,     7,     1,     1,     5,     1,     2,     1,
       3,     3,    10,     9,    10,     9,     2,     1,     3,     2,
       7,     7,     7,     2,     2,     2,     5,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     4,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 80 "yacc.y" /* yacc.c:1652  */
    { (yyval.intval) = (yyvsp[-2].intval) + (yyvsp[0].intval); }
#line 1441 "y.tab.c" /* yacc.c:1652  */
    break;

  case 4:
#line 81 "yacc.y" /* yacc.c:1652  */
    { (yyval.intval) = (yyvsp[-2].intval) - (yyvsp[0].intval); }
#line 1447 "y.tab.c" /* yacc.c:1652  */
    break;

  case 5:
#line 82 "yacc.y" /* yacc.c:1652  */
    { (yyval.intval) = (yyvsp[-2].intval) * (yyvsp[0].intval); }
#line 1453 "y.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 83 "yacc.y" /* yacc.c:1652  */
    { (yyval.intval) = (yyvsp[-2].intval) / (yyvsp[0].intval); }
#line 1459 "y.tab.c" /* yacc.c:1652  */
    break;

  case 7:
#line 84 "yacc.y" /* yacc.c:1652  */
    { (yyval.intval) = -atoi((yyvsp[0].strval)); }
#line 1465 "y.tab.c" /* yacc.c:1652  */
    break;

  case 8:
#line 85 "yacc.y" /* yacc.c:1652  */
    { (yyval.intval) = 0; }
#line 1471 "y.tab.c" /* yacc.c:1652  */
    break;

  case 9:
#line 86 "yacc.y" /* yacc.c:1652  */
    { (yyval.intval) = (yyvsp[-1].intval); }
#line 1477 "y.tab.c" /* yacc.c:1652  */
    break;

  case 10:
#line 87 "yacc.y" /* yacc.c:1652  */
    { (yyval.intval) = atoi((yyvsp[0].strval)); }
#line 1483 "y.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 88 "yacc.y" /* yacc.c:1652  */
    { (yyval.intval) = 0; }
#line 1489 "y.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 100 "yacc.y" /* yacc.c:1652  */
    {(yyval.strval)="INT";}
#line 1495 "y.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 101 "yacc.y" /* yacc.c:1652  */
    {(yyval.strval)="BOOL";}
#line 1501 "y.tab.c" /* yacc.c:1652  */
    break;

  case 20:
#line 102 "yacc.y" /* yacc.c:1652  */
    {(yyval.strval)="FLOAT";}
#line 1507 "y.tab.c" /* yacc.c:1652  */
    break;

  case 21:
#line 103 "yacc.y" /* yacc.c:1652  */
    {(yyval.strval)="CHAR";}
#line 1513 "y.tab.c" /* yacc.c:1652  */
    break;

  case 22:
#line 104 "yacc.y" /* yacc.c:1652  */
    {(yyval.strval)="VOID";}
#line 1519 "y.tab.c" /* yacc.c:1652  */
    break;

  case 23:
#line 105 "yacc.y" /* yacc.c:1652  */
    {(yyval.strval)="ARRAY";}
#line 1525 "y.tab.c" /* yacc.c:1652  */
    break;

  case 24:
#line 106 "yacc.y" /* yacc.c:1652  */
    {(yyval.strval)=(yyvsp[0].strval);}
#line 1531 "y.tab.c" /* yacc.c:1652  */
    break;

  case 25:
#line 109 "yacc.y" /* yacc.c:1652  */
    {(yyval.strval)=(yyvsp[0].strval); printf("de verificat daca exista clasa \n");}
#line 1537 "y.tab.c" /* yacc.c:1652  */
    break;

  case 26:
#line 112 "yacc.y" /* yacc.c:1652  */
    { }
#line 1543 "y.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 122 "yacc.y" /* yacc.c:1652  */
    {
                         }
#line 1550 "y.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 125 "yacc.y" /* yacc.c:1652  */
    {
                    char aux[]=",";
                    char aux2[]=":";
                    strcat((yyval.strval),aux);
                    strcat((yyval.strval),(yyvsp[0].strval));                  
               }
#line 1561 "y.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 135 "yacc.y" /* yacc.c:1652  */
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
                    sprintf(aux,"%s:%s",(yyval.strval),(yyvsp[0].strval));
                    (yyval.strval)=aux;
                    
                    variabila v;
                    v.nume    = pre+std::string((yyvsp[-2].strval));
                    v.tip     = std::string((yyvsp[0].strval));
                    v.valoare = "";
                    if(adaugaVar(v))
                    {
                         printf("variabila %s de tipul %s declarata\n",v.nume.c_str(),(yyvsp[0].strval));
                    }
                    else
                    {
                         printf("variabila %s de tipul %s a fost declarata anterior\n", (yyvsp[-2].strval), (yyvsp[0].strval));
                         M_ERROR_EXISTS_VAR
                         exit(0);
                         
                    }
               }
#line 1601 "y.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 173 "yacc.y" /* yacc.c:1652  */
    { 
                       std::string pre;
                       if(GetIsInClass())
                       {
                            pre=std::string( GetCurrentClassName());
                            pre=pre+std::string(".");
                       }

                       functie f;
                       f.nume = pre+std::string((yyvsp[-8].strval));
                       f.returnType = std::string((yyvsp[-3].strval));
                       adaugaParams(f, std::string((yyvsp[-6].strval)));
                       if(adaugaFunc(f))
                         printf("functia %s declarata cu tipul %s si parametrii %s\n",(yyvsp[-8].strval),(yyvsp[-3].strval),(yyvsp[-6].strval));
                       else
                       {
                         printf("functia %s nu a fost declarata cu tipul %s si parametrii %s", (yyvsp[-8].strval), (yyvsp[-3].strval), (yyvsp[-6].strval));
                         M_ERROR_EXISTS_FUNC
                         exit(0);
                       }
                  }
#line 1627 "y.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 195 "yacc.y" /* yacc.c:1652  */
    {
                       std::string pre;
                       if(GetIsInClass())
                       {
                            pre=std::string( GetCurrentClassName() );
                            pre=pre+std::string(".");                       }

                       functie f;
                       f.nume = pre+std::string((yyvsp[-7].strval));
                       f.returnType = std::string((yyvsp[-3].strval));
                       f.parametrii.clear();
                       if(adaugaFunc(f))
                         printf("functia %s declarata cu tipul %s fara parametri\n",(yyvsp[-7].strval), (yyvsp[-3].strval));
                       else
                       {
                         printf("functia %s nu a fost declarata cu tipul %s fara parametri\n", (yyvsp[-7].strval), (yyvsp[-3].strval));
                         M_ERROR_EXISTS_FUNC
                         exit(0);
                       }
                  }
#line 1652 "y.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 216 "yacc.y" /* yacc.c:1652  */
    { 
                       std::string pre;
                       if(GetIsInClass())
                       {
                            pre=std::string( GetCurrentClassName() );
                            pre=pre+std::string(".");                     
                       }

                       functie f;
                       f.nume = pre+std::string((yyvsp[-8].strval));

                       f.returnType = std::string((yyvsp[-3].strval));
                       adaugaParams(f, std::string((yyvsp[-6].strval)));
                       if(adaugaFunc(f))
                         printf("functia %s declarata cu tipul %s si parametrii %s\n",(yyvsp[-8].strval),(yyvsp[-3].strval),(yyvsp[-6].strval));
                       else
                       {
                         printf("functia %s nu a fost declarata cu tipul %s si parametrii %s\n", (yyvsp[-8].strval), (yyvsp[-3].strval), (yyvsp[-6].strval));
                         M_ERROR_EXISTS_FUNC
                         exit(0);
                       }
                  }
#line 1679 "y.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 239 "yacc.y" /* yacc.c:1652  */
    { 
                       std::string pre;
                       if(GetIsInClass())
                       {
                            pre=std::string( GetCurrentClassName() );
                            pre=pre+std::string(".");
                       }

                       functie f;
                       f.nume = pre+std::string((yyvsp[-7].strval));

                       f.returnType = std::string((yyvsp[-3].strval));
                       f.parametrii.clear();
                       if(adaugaFunc(f))
                         printf("functia %s declarata cu tipul %s fara parametri\n",(yyvsp[-7].strval),(yyvsp[-3].strval));
                       else
                       {
                         printf("functia %s nu a fost declarata cu tipul %s fara parametri\n", (yyvsp[-7].strval), (yyvsp[-3].strval));
                         M_ERROR_EXISTS_FUNC
                         exit(0);
                       }
                       
                  }
#line 1707 "y.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 281 "yacc.y" /* yacc.c:1652  */
    {}
#line 1713 "y.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 307 "yacc.y" /* yacc.c:1652  */
    {printf(" 1 | %s<-%s\n",(yyvsp[-2].strval),(yyvsp[0].strval));}
#line 1719 "y.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 308 "yacc.y" /* yacc.c:1652  */
    {printf(" 2 | %s<-%s\n",(yyvsp[-2].strval),(yyvsp[0].strval));}
#line 1725 "y.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 309 "yacc.y" /* yacc.c:1652  */
    {printf(" 3 | %s<-%s\n",(yyvsp[-2].strval),(yyvsp[0].strval));}
#line 1731 "y.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 310 "yacc.y" /* yacc.c:1652  */
    {printf(" 4 | %s<-%s\n",(yyvsp[-2].strval),(yyvsp[0].strval));}
#line 1737 "y.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 311 "yacc.y" /* yacc.c:1652  */
    {printf(" 5 | %s<-%s\n",(yyvsp[-2].strval),(yyvsp[0].strval));}
#line 1743 "y.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 312 "yacc.y" /* yacc.c:1652  */
    {printf(" 6 | %s<-%s\n",(yyvsp[-2].strval),(yyvsp[0].strval));}
#line 1749 "y.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 313 "yacc.y" /* yacc.c:1652  */
    {printf(" 7 | %s<-%s\n",(yyvsp[-2].strval),(yyvsp[0].strval));}
#line 1755 "y.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 314 "yacc.y" /* yacc.c:1652  */
    {printf(" 8 | %s<-%s\n",(yyvsp[-2].strval),(yyvsp[0].strval));}
#line 1761 "y.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 315 "yacc.y" /* yacc.c:1652  */
    {printf(" 9 | %s<-%s\n",(yyvsp[-2].strval),(yyvsp[0].strval));}
#line 1767 "y.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 316 "yacc.y" /* yacc.c:1652  */
    {printf("10 | %s<-%s\n",(yyvsp[-2].strval),(yyvsp[0].strval));}
#line 1773 "y.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 322 "yacc.y" /* yacc.c:1652  */
    {
                    strcat((yyval.strval),".");
                    strcat((yyval.strval),(yyvsp[0].strval));
               }
#line 1782 "y.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 327 "yacc.y" /* yacc.c:1652  */
    {
                    strcat((yyval.strval),".");
                    strcat((yyval.strval),(yyvsp[0].strval));
               }
#line 1791 "y.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 334 "yacc.y" /* yacc.c:1652  */
    {
                    strcat((yyval.strval),".");
                    strcat((yyval.strval),(yyvsp[0].strval));
               }
#line 1800 "y.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 339 "yacc.y" /* yacc.c:1652  */
    {
                    strcat((yyval.strval),".");
                    strcat((yyval.strval),(yyvsp[0].strval));
               }
#line 1809 "y.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 345 "yacc.y" /* yacc.c:1652  */
    {strcat((yyval.strval),"()");}
#line 1815 "y.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 346 "yacc.y" /* yacc.c:1652  */
    {strcat((yyval.strval),"(");strcat((yyval.strval),(yyvsp[-1].strval));strcat((yyval.strval),")");}
#line 1821 "y.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 347 "yacc.y" /* yacc.c:1652  */
    {if(strcmp("main",GetCurrentFunctionName())==0) printf("valoarea este: %d\n",(yyvsp[-1].intval));}
#line 1827 "y.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 351 "yacc.y" /* yacc.c:1652  */
    {}
#line 1833 "y.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 352 "yacc.y" /* yacc.c:1652  */
    {strcat((yyval.strval),",");strcat((yyval.strval),(yyvsp[0].strval));}
#line 1839 "y.tab.c" /* yacc.c:1652  */
    break;

  case 78:
#line 355 "yacc.y" /* yacc.c:1652  */
    {(yyval.strval)=strdup((yyvsp[0].strval));}
#line 1845 "y.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 356 "yacc.y" /* yacc.c:1652  */
    {(yyval.strval)=strdup((yyvsp[0].strval));}
#line 1851 "y.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 357 "yacc.y" /* yacc.c:1652  */
    {(yyval.strval)=strdup((yyvsp[0].strval));}
#line 1857 "y.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 358 "yacc.y" /* yacc.c:1652  */
    {(yyval.strval)=strdup((yyvsp[0].strval));}
#line 1863 "y.tab.c" /* yacc.c:1652  */
    break;

  case 82:
#line 359 "yacc.y" /* yacc.c:1652  */
    {(yyval.strval)=strdup((yyvsp[0].strval));}
#line 1869 "y.tab.c" /* yacc.c:1652  */
    break;


#line 1873 "y.tab.c" /* yacc.c:1652  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 371 "yacc.y" /* yacc.c:1918  */


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

