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

#include "y.tab.h"

#include "Messages.h"
#include "StackMemory.h"
#include "Converter.h"
#include "shared.h"

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
#line 40 "yacc.y" /* yacc.c:352  */

float       floatval;
int         intval;
char*       strval;

#line 228 "y.tab.c" /* yacc.c:352  */
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
#define YYLAST   190

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

#define YYUNDEFTOK  2
#define YYMAXUTOK   290

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
      40,    41,    33,    31,    45,    32,    48,    34,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    46,    42,
       2,    47,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    35,    36,    37,    38,
      39
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    77,    77,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    92,    93,    94,    95,    96,    97,   100,   101,
     102,   103,   104,   105,   106,   109,   112,   115,   118,   121,
     124,   134,   149,   154,   159,   164,   172,   173,   174,   175,
     179,   180,   181,   182,   183,   184,   188,   192,   193,   197,
     198,   199,   203,   204,   205,   206,   207,   208,   209,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   228,
     233,   240,   245,   252,   253,   254,   258,   259,   262,   263,
     264,   265,   266,   269,   270,   271,   272,   275
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "ENDDEF", "BEG", "AND", "OR",
  "NOT", "DEF", "LR", "GR", "LRE", "GRE", "END", "LET", "CLASS", "IF",
  "FOR", "WHILE", "EVAL_FUNC", "STRUCTURE", "VOID_TYPE", "INT_TYPE",
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
     285,    43,    45,    42,    47,   286,   287,   288,   289,   290,
      40,    41,    59,    91,    93,    44,    58,    61,    46
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
     102,    34,    36,    40,    25,   -68,    45,    47,    53,    38,
      14,   -68,    31,    62,   -68,   102,   102,   102,    11,    83,
      36,   102,   -68,   -68,   -68,    70,    67,   -68,   -68,   -68,
     -68,   -68,   -68,   118,   -68,   -68,   -68,   -68,   115,    83,
      97,    83,   -68,   141,    83,   137,    16,   144,   107,    33,
     111,   112,   113,   114,   116,   151,    16,   117,   109,   119,
     120,   153,    16,   123,     9,    18,    20,    68,   160,    68,
      19,    16,   -68,   -68,   -68,    27,   -68,   -68,   -68,   161,
     162,   126,     1,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   127,   122,   -68,     1,   -68,   -68,   -68,   -68,     1,
     -68,   -68,   -68,   129,   -68,   130,   125,   -68,    22,   131,
     132,   134,   -68,    21,   -68,    19,    89,   -68,     1,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,    65,   159,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,    68,   170,   171,    68,
     172,   -68,   -68,    93,    19,    19,    19,    19,   -68,   -68,
      16,   -68,   133,    16,   136,    16,   -68,    50,    50,   -68,
     -68,   165,   166,   160,   168,   -68,   -68,   -68,   -68
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
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   -54,   124,   103,   -68,   -68,   -68,    98,     8,
     -68,   -68,   -56,   -68,   -68,   -61,    44,   -68,   -67,   -55,
     -48,   -62,    57,   -68,   -33,   128
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
     119,    94,   112,    99,   141,    14,    26,   120,    36,    53,
     118,     2,    98,    50,    51,    52,    53,     9,    53,    10,
      53,    64,   122,    13,    83,    84,    85,    53,    86,    66,
      87,   113,    25,    83,    84,    85,   114,    86,   142,   115,
      19,   143,    83,    84,    85,    90,    86,    21,    82,    65,
     137,   103,    88,    64,   107,   151,    20,   107,    18,    89,
      65,    66,   100,   146,   147,    53,    27,    15,    53,    16,
     157,   158,   159,   160,   161,    17,   167,   162,     7,   164,
      83,    84,    85,   104,    86,    28,    29,    30,    40,    31,
      32,     1,    33,     7,     7,     7,    39,     2,     3,     7,
     144,   145,   146,   147,   144,   145,   146,   147,    41,    42,
     148,   129,   130,   131,   156,   132,   133,   134,   135,    22,
      23,    24,    43,    44,    45,    37,    46,    47,    48,    62,
      63,    67,    68,    69,    70,    72,    75,    78,    71,    74,
      81,    76,    77,   108,   150,   123,   124,   127,   126,    64,
     125,   128,   138,   152,   139,   140,   153,   155,   163,   165,
     166,   137,   168,   154,   149,     0,     0,     0,     0,     0,
      80
};

static const yytype_int16 yycheck[] =
{
      56,    68,    64,    65,    66,    67,    62,    69,    69,    64,
      65,    66,     3,    75,     3,    71,    64,    65,    66,     3,
      75,     3,     3,     3,     3,     0,    18,    75,    20,    20,
       3,    15,    65,    17,    18,    19,    20,     3,    20,     3,
      20,    40,    75,     3,    35,    36,    37,    20,    39,    48,
      41,    32,    41,    35,    36,    37,    37,    39,    37,    40,
      46,   115,    35,    36,    37,   127,    39,     5,     3,    47,
      48,     3,   127,    40,   136,   136,    45,   139,    40,   127,
      47,    48,   137,    33,    34,    20,     3,    42,    20,    42,
     144,   145,   146,   147,   150,    42,   163,   153,     0,   155,
      35,    36,    37,    35,    39,    22,    23,    24,    41,    26,
      27,     9,    29,    15,    16,    17,    46,    15,    16,    21,
      31,    32,    33,    34,    31,    32,    33,    34,    10,    14,
      41,     6,     7,     8,    41,    10,    11,    12,    13,    15,
      16,    17,    39,    46,    41,    21,     5,    44,    11,     5,
      43,    40,    40,    40,    40,     4,    47,     4,    42,    42,
      37,    42,    42,     3,     5,     4,     4,    45,    41,    40,
      44,    41,    41,     3,    42,    41,     5,     5,    42,    14,
      14,    48,    14,   139,   127,    -1,    -1,    -1,    -1,    -1,
      62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     9,    15,    16,    50,    52,    55,    57,    60,     3,
       3,    58,    59,     3,     0,    42,    42,    42,    40,    46,
      45,     5,    52,    52,    52,    41,    58,     3,    22,    23,
      24,    26,    27,    29,    53,    54,    58,    52,    56,    46,
      41,    10,    14,    53,    46,    53,     5,    53,    11,     3,
      17,    18,    19,    20,    57,    61,    62,    67,    68,    69,
      70,    74,     5,    43,    40,    47,    48,    40,    40,    40,
      40,    42,     4,    61,    42,    47,    42,    42,     4,    61,
      74,    37,     3,    35,    36,    37,    39,    41,    68,    69,
      70,    71,    72,    73,     3,    68,    69,    70,    73,     3,
      68,    69,    70,     3,    35,    64,    65,    70,     3,    63,
      67,    64,     3,    32,    37,    40,    51,    61,     3,    68,
      69,    70,    73,     4,     4,    44,    41,    45,    41,     6,
       7,     8,    10,    11,    12,    13,    66,    48,    41,    42,
      41,     3,    37,    51,    31,    32,    33,    34,    41,    71,
       5,    64,     3,     5,    65,     5,    41,    51,    51,    51,
      51,    61,    61,    42,    61,    14,    14,    67,    14
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    52,    52,    52,    52,    52,    52,    53,    53,
      53,    53,    53,    53,    53,    54,    55,    56,    57,    58,
      58,    59,    60,    60,    60,    60,    61,    61,    61,    61,
      62,    62,    62,    62,    62,    62,    63,    64,    64,    65,
      65,    65,    66,    66,    66,    66,    66,    66,    66,    67,
      67,    67,    67,    67,    67,    67,    67,    67,    67,    68,
      68,    69,    69,    70,    70,    70,    71,    71,    72,    72,
      72,    72,    72,    73,    73,    73,    73,    74
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

  case 28:
#line 118 "yacc.y" /* yacc.c:1652  */
    {printf("au fost declarate variabilele: %s\n",(yyvsp[0].strval));}
#line 1549 "y.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 122 "yacc.y" /* yacc.c:1652  */
    {
                         }
#line 1556 "y.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 125 "yacc.y" /* yacc.c:1652  */
    {
                    char aux[]=",";
                    char aux2[]=":";
                    strcat((yyval.strval),aux);
                    strcat((yyval.strval),(yyvsp[0].strval));                  
               }
#line 1567 "y.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 135 "yacc.y" /* yacc.c:1652  */
    {
                    char* aux =(char*) malloc(1024);
                    sprintf(aux,"%s:%s",(yyval.strval),(yyvsp[0].strval));
                    (yyval.strval)=aux;
                    
                    variabila v;
                    v.nume    = std::string((yyvsp[-2].strval));
                    v.tip     = std::string((yyvsp[0].strval));
                    v.valoare = "";
                    ///DECLARARE TODO
                    printf("variabila %s de tipul %s declarata\n",(yyvsp[-2].strval),(yyvsp[0].strval));
               }
#line 1584 "y.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 150 "yacc.y" /* yacc.c:1652  */
    { 
                       ///DECLARARE TODO
                       printf("functia %s declarata cu tipul %s si parametrii %s\n",(yyvsp[-8].strval),(yyvsp[-3].strval),(yyvsp[-6].strval));
                  }
#line 1593 "y.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 155 "yacc.y" /* yacc.c:1652  */
    {
                         ///DECLARARE TODO
                       printf("functia %s declarata cu tipul %s fara parametri\n",(yyvsp[-7].strval),(yyvsp[-3].strval));
                  }
#line 1602 "y.tab.c" /* yacc.c:1652  */
    break;

  case 34:
#line 160 "yacc.y" /* yacc.c:1652  */
    { 
                          ///DECLARARE TODO
                       printf("functia %s declarata cu tipul %s si parametrii %s\n",(yyvsp[-8].strval),(yyvsp[-3].strval),(yyvsp[-6].strval));
                  }
#line 1611 "y.tab.c" /* yacc.c:1652  */
    break;

  case 35:
#line 165 "yacc.y" /* yacc.c:1652  */
    { 
                     ///DECLARARE TODO
                       printf("functia %s declarata cu tipul %s fara parametri\n",(yyvsp[-7].strval),(yyvsp[-3].strval));
                  }
#line 1620 "y.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 188 "yacc.y" /* yacc.c:1652  */
    {}
#line 1626 "y.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 214 "yacc.y" /* yacc.c:1652  */
    {printf(" 1 | %s<-%s\n",(yyvsp[-2].strval),(yyvsp[0].strval));}
#line 1632 "y.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 215 "yacc.y" /* yacc.c:1652  */
    {printf(" 2 | %s<-%s\n",(yyvsp[-2].strval),(yyvsp[0].strval));}
#line 1638 "y.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 216 "yacc.y" /* yacc.c:1652  */
    {printf(" 3 | %s<-%s\n",(yyvsp[-2].strval),(yyvsp[0].strval));}
#line 1644 "y.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 217 "yacc.y" /* yacc.c:1652  */
    {printf(" 4 | %s<-%s\n",(yyvsp[-2].strval),(yyvsp[0].strval));}
#line 1650 "y.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 218 "yacc.y" /* yacc.c:1652  */
    {printf(" 5 | %s<-%s\n",(yyvsp[-2].strval),(yyvsp[0].strval));}
#line 1656 "y.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 219 "yacc.y" /* yacc.c:1652  */
    {printf(" 6 | %s<-%s\n",(yyvsp[-2].strval),(yyvsp[0].strval));}
#line 1662 "y.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 220 "yacc.y" /* yacc.c:1652  */
    {printf(" 7 | %s<-%s\n",(yyvsp[-2].strval),(yyvsp[0].strval));}
#line 1668 "y.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 221 "yacc.y" /* yacc.c:1652  */
    {printf(" 8 | %s<-%s\n",(yyvsp[-2].strval),(yyvsp[0].strval));}
#line 1674 "y.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 222 "yacc.y" /* yacc.c:1652  */
    {printf(" 9 | %s<-%s\n",(yyvsp[-2].strval),(yyvsp[0].strval));}
#line 1680 "y.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 223 "yacc.y" /* yacc.c:1652  */
    {printf("10 | %s<-%s\n",(yyvsp[-2].strval),(yyvsp[0].strval));}
#line 1686 "y.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 229 "yacc.y" /* yacc.c:1652  */
    {
                    strcat((yyval.strval),".");
                    strcat((yyval.strval),(yyvsp[0].strval));
               }
#line 1695 "y.tab.c" /* yacc.c:1652  */
    break;

  case 70:
#line 234 "yacc.y" /* yacc.c:1652  */
    {
                    strcat((yyval.strval),".");
                    strcat((yyval.strval),(yyvsp[0].strval));
               }
#line 1704 "y.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 241 "yacc.y" /* yacc.c:1652  */
    {
                    strcat((yyval.strval),".");
                    strcat((yyval.strval),(yyvsp[0].strval));
               }
#line 1713 "y.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 246 "yacc.y" /* yacc.c:1652  */
    {
                    strcat((yyval.strval),".");
                    strcat((yyval.strval),(yyvsp[0].strval));
               }
#line 1722 "y.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 252 "yacc.y" /* yacc.c:1652  */
    {strcat((yyval.strval),"()");}
#line 1728 "y.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 253 "yacc.y" /* yacc.c:1652  */
    {strcat((yyval.strval),"(");strcat((yyval.strval),(yyvsp[-1].strval));strcat((yyval.strval),")");}
#line 1734 "y.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 254 "yacc.y" /* yacc.c:1652  */
    {printf("valoarea este: %d\n",(yyvsp[-1].intval));}
#line 1740 "y.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 258 "yacc.y" /* yacc.c:1652  */
    {}
#line 1746 "y.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 259 "yacc.y" /* yacc.c:1652  */
    {strcat((yyval.strval),",");strcat((yyval.strval),(yyvsp[0].strval));}
#line 1752 "y.tab.c" /* yacc.c:1652  */
    break;

  case 78:
#line 262 "yacc.y" /* yacc.c:1652  */
    {(yyval.strval)=strdup((yyvsp[0].strval));}
#line 1758 "y.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 263 "yacc.y" /* yacc.c:1652  */
    {(yyval.strval)=strdup((yyvsp[0].strval));}
#line 1764 "y.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 264 "yacc.y" /* yacc.c:1652  */
    {(yyval.strval)=strdup((yyvsp[0].strval));}
#line 1770 "y.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 265 "yacc.y" /* yacc.c:1652  */
    {(yyval.strval)=strdup((yyvsp[0].strval));}
#line 1776 "y.tab.c" /* yacc.c:1652  */
    break;

  case 82:
#line 266 "yacc.y" /* yacc.c:1652  */
    {(yyval.strval)=strdup((yyvsp[0].strval));}
#line 1782 "y.tab.c" /* yacc.c:1652  */
    break;


#line 1786 "y.tab.c" /* yacc.c:1652  */
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
#line 285 "yacc.y" /* yacc.c:1918  */


#include <iostream>  

int main(int argc, char** argv){
isInFunction=false;
currentFunctionName=0;

yyin=fopen(argv[1],"r");
yyparse();
} 

