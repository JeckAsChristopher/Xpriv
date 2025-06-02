/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void yyerror(const char *s);
int yylex(void);

int root_required = 0;

#line 83 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
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

#include "xpriv.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_STRING = 3,                     /* STRING  */
  YYSYMBOL_IDENT = 4,                      /* IDENT  */
  YYSYMBOL_NUMBER = 5,                     /* NUMBER  */
  YYSYMBOL_REQUIRES = 6,                   /* REQUIRES  */
  YYSYMBOL_ROOT = 7,                       /* ROOT  */
  YYSYMBOL_LET = 8,                        /* LET  */
  YYSYMBOL_SYSCALL = 9,                    /* SYSCALL  */
  YYSYMBOL_PRINT = 10,                     /* PRINT  */
  YYSYMBOL_LOOP = 11,                      /* LOOP  */
  YYSYMBOL_TIMES = 12,                     /* TIMES  */
  YYSYMBOL_FROM = 13,                      /* FROM  */
  YYSYMBOL_TO = 14,                        /* TO  */
  YYSYMBOL_WHEN = 15,                      /* WHEN  */
  YYSYMBOL_EXEC = 16,                      /* EXEC  */
  YYSYMBOL_REQUIRE_BIN = 17,               /* REQUIRE_BIN  */
  YYSYMBOL_ENV = 18,                       /* ENV  */
  YYSYMBOL_SLEEP = 19,                     /* SLEEP  */
  YYSYMBOL_EXIT = 20,                      /* EXIT  */
  YYSYMBOL_ASROOT = 21,                    /* ASROOT  */
  YYSYMBOL_EQ = 22,                        /* EQ  */
  YYSYMBOL_NEQ = 23,                       /* NEQ  */
  YYSYMBOL_LT = 24,                        /* LT  */
  YYSYMBOL_GT = 25,                        /* GT  */
  YYSYMBOL_LEQ = 26,                       /* LEQ  */
  YYSYMBOL_GEQ = 27,                       /* GEQ  */
  YYSYMBOL_PLUS = 28,                      /* PLUS  */
  YYSYMBOL_MINUS = 29,                     /* MINUS  */
  YYSYMBOL_MUL = 30,                       /* MUL  */
  YYSYMBOL_DIV = 31,                       /* DIV  */
  YYSYMBOL_LBRACE = 32,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 33,                    /* RBRACE  */
  YYSYMBOL_LPAREN = 34,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 35,                    /* RPAREN  */
  YYSYMBOL_COMMA = 36,                     /* COMMA  */
  YYSYMBOL_ASSIGN = 37,                    /* ASSIGN  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_program = 39,                   /* program  */
  YYSYMBOL_requires_block = 40,            /* requires_block  */
  YYSYMBOL_statements = 41,                /* statements  */
  YYSYMBOL_statement = 42,                 /* statement  */
  YYSYMBOL_var_decl = 43,                  /* var_decl  */
  YYSYMBOL_expr = 44,                      /* expr  */
  YYSYMBOL_condition = 45,                 /* condition  */
  YYSYMBOL_syscall_stmt = 46,              /* syscall_stmt  */
  YYSYMBOL_exec_stmt = 47,                 /* exec_stmt  */
  YYSYMBOL_require_bin_stmt = 48,          /* require_bin_stmt  */
  YYSYMBOL_env_stmt = 49,                  /* env_stmt  */
  YYSYMBOL_sleep_stmt = 50,                /* sleep_stmt  */
  YYSYMBOL_exit_stmt = 51,                 /* exit_stmt  */
  YYSYMBOL_as_root_block = 52,             /* as_root_block  */
  YYSYMBOL_print_stmt = 53,                /* print_stmt  */
  YYSYMBOL_expr_list = 54,                 /* expr_list  */
  YYSYMBOL_loop_stmt = 55,                 /* loop_stmt  */
  YYSYMBOL_conditional_stmt = 56,          /* conditional_stmt  */
  YYSYMBOL_syscall_args = 57               /* syscall_args  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   156

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  103

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    33,    33,    37,    46,    49,    51,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    69,    76,
      77,    78,    83,    88,    93,    98,   103,   109,   110,   111,
     112,   113,   114,   118,   132,   141,   156,   168,   175,   182,
     192,   196,   197,   201,   210,   216,   217,   218
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "STRING", "IDENT",
  "NUMBER", "REQUIRES", "ROOT", "LET", "SYSCALL", "PRINT", "LOOP", "TIMES",
  "FROM", "TO", "WHEN", "EXEC", "REQUIRE_BIN", "ENV", "SLEEP", "EXIT",
  "ASROOT", "EQ", "NEQ", "LT", "GT", "LEQ", "GEQ", "PLUS", "MINUS", "MUL",
  "DIV", "LBRACE", "RBRACE", "LPAREN", "RPAREN", "COMMA", "ASSIGN",
  "$accept", "program", "requires_block", "statements", "statement",
  "var_decl", "expr", "condition", "syscall_stmt", "exec_stmt",
  "require_bin_stmt", "env_stmt", "sleep_stmt", "exit_stmt",
  "as_root_block", "print_stmt", "expr_list", "loop_stmt",
  "conditional_stmt", "syscall_args", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-45)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       5,     6,    12,   -45,   -45,   -45,    92,    13,    15,   -18,
      26,    -1,    -3,    -2,     0,    19,    20,     7,   -45,   -45,
     -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,
       3,    24,    -1,    42,   -45,   -45,   -45,    -1,    93,    34,
      -1,    -1,    -1,    62,    63,   -45,    -1,    -1,    48,   -29,
      75,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   -45,   105,   113,   121,    50,    51,    27,    48,
      21,    60,   -45,    -1,    45,   -45,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    54,   -45,   -45,   -45,
     -45,   -45,   -45,    -1,   -45,    48,    91,   -45,    48,    65,
     -45,    73,   -45
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     5,     3,     1,     2,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     7,
       8,    12,    13,    15,    14,    16,    17,     9,    10,    11,
       0,     0,     0,     0,    19,    20,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     0,    45,    41,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     5,     0,     0,     0,     0,     0,     0,    18,
      46,     0,    40,     0,     0,    26,    27,    28,    29,    30,
      31,    32,    22,    23,    24,    25,     0,    34,    35,    36,
      37,    38,    39,     0,    33,    42,     0,    44,    47,     0,
       5,     0,    43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -45,   -45,   -45,   -44,   -45,   -45,   -32,   -45,   -45,   -45,
     -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45,   -45
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     6,    18,    19,    38,    39,    20,    21,
      22,    23,    24,    25,    26,    27,    49,    28,    29,    71
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      48,    68,    34,    35,    36,    51,    72,    73,    63,    64,
      65,     1,     5,     4,    69,    70,    32,    30,    86,    31,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      33,    40,    41,    37,    42,     7,     8,     9,    10,    45,
      46,    95,    11,    12,    13,    14,    15,    16,    17,    58,
      59,    60,    61,    43,    44,    50,   101,    93,    47,    96,
      92,    98,     7,     8,     9,    10,    62,    66,    67,    11,
      12,    13,    14,    15,    16,    17,    58,    59,    60,    61,
      74,     7,     8,     9,    10,    90,    91,    97,    11,    12,
      13,    14,    15,    16,    17,    94,    99,   100,     0,     0,
       7,     8,     9,    10,     0,     0,   102,    11,    12,    13,
      14,    15,    16,    17,     0,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    58,    59,    60,    61,     0,
       0,     0,    75,    58,    59,    60,    61,     0,     0,     0,
      87,    58,    59,    60,    61,     0,     0,     0,    88,    58,
      59,    60,    61,     0,     0,     0,    89
};

static const yytype_int8 yycheck[] =
{
      32,    45,     3,     4,     5,    37,    35,    36,    40,    41,
      42,     6,     0,     7,    46,    47,    34,     4,    62,     4,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
       4,    34,    34,    34,    34,     8,     9,    10,    11,    32,
      37,    73,    15,    16,    17,    18,    19,    20,    21,    28,
      29,    30,    31,    34,    34,    13,   100,    36,    34,    14,
      33,    93,     8,     9,    10,    11,    32,     5,     5,    15,
      16,    17,    18,    19,    20,    21,    28,    29,    30,    31,
       5,     8,     9,    10,    11,    35,    35,    33,    15,    16,
      17,    18,    19,    20,    21,    35,     5,    32,    -1,    -1,
       8,     9,    10,    11,    -1,    -1,    33,    15,    16,    17,
      18,    19,    20,    21,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    28,    29,    30,    31,    -1,
      -1,    -1,    35,    28,    29,    30,    31,    -1,    -1,    -1,
      35,    28,    29,    30,    31,    -1,    -1,    -1,    35,    28,
      29,    30,    31,    -1,    -1,    -1,    35
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     6,    39,    40,     7,     0,    41,     8,     9,    10,
      11,    15,    16,    17,    18,    19,    20,    21,    42,    43,
      46,    47,    48,    49,    50,    51,    52,    53,    55,    56,
       4,     4,    34,     4,     3,     4,     5,    34,    44,    45,
      34,    34,    34,    34,    34,    32,    37,    34,    44,    54,
      13,    44,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    44,    44,    44,     5,     5,    41,    44,
      44,    57,    35,    36,     5,    35,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    41,    35,    35,    35,
      35,    35,    33,    36,    35,    44,    14,    33,    44,     5,
      32,    41,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    43,    44,
      44,    44,    44,    44,    44,    44,    44,    45,    45,    45,
      45,    45,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    54,    55,    56,    57,    57,    57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     0,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       1,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     5,     4,     4,     4,     4,     4,     4,
       4,     1,     3,     9,     5,     0,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
  case 3: /* requires_block: REQUIRES ROOT  */
#line 37 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                    {
          root_required = 1;
          if (geteuid() != 0) {
              fprintf(stderr, "[error] root privileges required.\n");
              exit(EXIT_FAILURE);
          } else {
              printf("[root granted]\n");
          }
      }
#line 1207 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 18: /* var_decl: LET IDENT ASSIGN expr  */
#line 69 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                          {
        printf("[var] %s = %s\n", (yyvsp[-2].str), (yyvsp[0].str));
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1216 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 19: /* expr: STRING  */
#line 76 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
             { (yyval.str) = (yyvsp[0].str); }
#line 1222 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 20: /* expr: IDENT  */
#line 77 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
             { (yyval.str) = strdup((yyvsp[0].str)); free((yyvsp[0].str)); }
#line 1228 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 21: /* expr: NUMBER  */
#line 78 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
             {
        char buf[32];
        snprintf(buf, sizeof(buf), "%d", (yyvsp[0].num));
        (yyval.str) = strdup(buf);
    }
#line 1238 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 22: /* expr: expr PLUS expr  */
#line 83 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                     {
        char *buf = malloc(strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 2);
        sprintf(buf, "%s+%s", (yyvsp[-2].str), (yyvsp[0].str));
        (yyval.str) = buf; free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1248 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 23: /* expr: expr MINUS expr  */
#line 88 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                      {
        char *buf = malloc(strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 2);
        sprintf(buf, "%s-%s", (yyvsp[-2].str), (yyvsp[0].str));
        (yyval.str) = buf; free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1258 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 24: /* expr: expr MUL expr  */
#line 93 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                    {
        char *buf = malloc(strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 2);
        sprintf(buf, "%s*%s", (yyvsp[-2].str), (yyvsp[0].str));
        (yyval.str) = buf; free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1268 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 25: /* expr: expr DIV expr  */
#line 98 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                    {
        char *buf = malloc(strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 2);
        sprintf(buf, "%s/%s", (yyvsp[-2].str), (yyvsp[0].str));
        (yyval.str) = buf; free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1278 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 26: /* expr: LPAREN expr RPAREN  */
#line 103 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                         {
        (yyval.str) = strdup((yyvsp[-1].str)); free((yyvsp[-1].str));
    }
#line 1286 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 27: /* condition: expr EQ expr  */
#line 109 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                     { (yyval.str) = strdup("=="); }
#line 1292 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 28: /* condition: expr NEQ expr  */
#line 110 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                     { (yyval.str) = strdup("!="); }
#line 1298 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 29: /* condition: expr LT expr  */
#line 111 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                     { (yyval.str) = strdup("<"); }
#line 1304 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 30: /* condition: expr GT expr  */
#line 112 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                     { (yyval.str) = strdup(">"); }
#line 1310 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 31: /* condition: expr LEQ expr  */
#line 113 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                     { (yyval.str) = strdup("<="); }
#line 1316 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 32: /* condition: expr GEQ expr  */
#line 114 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                     { (yyval.str) = strdup(">="); }
#line 1322 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 33: /* syscall_stmt: SYSCALL IDENT LPAREN syscall_args RPAREN  */
#line 118 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                                             {
        if (!root_required) {
            fprintf(stderr, "[error] syscall requires 'requires root'.\n");
            exit(EXIT_FAILURE);
        }
        char cmd[512];
        snprintf(cmd, sizeof(cmd), "%s %s", (yyvsp[-3].str), (yyvsp[-1].str) ? (yyvsp[-1].str) : "");
        int result = system(cmd);
        printf("[syscall] %s => %d\n", cmd, result);
        free((yyvsp[-3].str)); if ((yyvsp[-1].str)) free((yyvsp[-1].str));
    }
#line 1338 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 34: /* exec_stmt: EXEC LPAREN expr RPAREN  */
#line 132 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                            {
        printf("[exec] running: %s\n", (yyvsp[-1].str));
        int ret = system((yyvsp[-1].str));
        printf("[exec return] %d\n", ret);
        free((yyvsp[-1].str));
    }
#line 1349 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 35: /* require_bin_stmt: REQUIRE_BIN LPAREN expr RPAREN  */
#line 141 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                                   {
        char check[256];
        snprintf(check, sizeof(check), "command -v %s >/dev/null 2>&1", (yyvsp[-1].str));
        int exists = system(check);
        if (exists != 0) {
            fprintf(stderr, "[missing binary] %s\n", (yyvsp[-1].str));
            exit(127);
        } else {
            printf("[bin found] %s\n", (yyvsp[-1].str));
        }
        free((yyvsp[-1].str));
    }
#line 1366 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 36: /* env_stmt: ENV LPAREN expr RPAREN  */
#line 156 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                           {
        char *val = getenv((yyvsp[-1].str));
        if (val) {
            printf("[env] %s=%s\n", (yyvsp[-1].str), val);
        } else {
            printf("[env] %s is undefined\n", (yyvsp[-1].str));
        }
        free((yyvsp[-1].str));
    }
#line 1380 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 37: /* sleep_stmt: SLEEP LPAREN NUMBER RPAREN  */
#line 168 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                               {
        printf("[sleep] %d seconds\n", (yyvsp[-1].num));
        sleep((yyvsp[-1].num));
    }
#line 1389 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 38: /* exit_stmt: EXIT LPAREN NUMBER RPAREN  */
#line 175 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                              {
        printf("[exit] code %d\n", (yyvsp[-1].num));
        exit((yyvsp[-1].num));
    }
#line 1398 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 39: /* as_root_block: ASROOT LBRACE statements RBRACE  */
#line 182 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                                    {
        if (geteuid() != 0) {
            fprintf(stderr, "[as_root error] not running as root.\n");
            exit(EXIT_FAILURE);
        }
        printf("[as_root block]\n");
    }
#line 1410 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 40: /* print_stmt: PRINT LPAREN expr_list RPAREN  */
#line 192 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                                  { }
#line 1416 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 41: /* expr_list: expr  */
#line 196 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                                  { printf("[print] %s\n", (yyvsp[0].str)); free((yyvsp[0].str)); }
#line 1422 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 42: /* expr_list: expr_list COMMA expr  */
#line 197 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                                  { printf("[print] %s\n", (yyvsp[0].str)); free((yyvsp[0].str)); }
#line 1428 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 43: /* loop_stmt: LOOP IDENT FROM NUMBER TO NUMBER LBRACE statements RBRACE  */
#line 201 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                                                              {
        for (int i = (yyvsp[-5].num); i <= (yyvsp[-3].num); i++) {
            printf("[loop %s=%d]\n", (yyvsp[-7].str), i);
        }
        free((yyvsp[-7].str));
    }
#line 1439 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 44: /* conditional_stmt: WHEN condition LBRACE statements RBRACE  */
#line 210 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                                            {
        printf("[when] condition stub eval true\n");
    }
#line 1447 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 45: /* syscall_args: %empty  */
#line 216 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                  { (yyval.str) = strdup(""); }
#line 1453 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 46: /* syscall_args: expr  */
#line 217 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                  { (yyval.str) = strdup((yyvsp[0].str)); free((yyvsp[0].str)); }
#line 1459 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;

  case 47: /* syscall_args: expr COMMA expr  */
#line 218 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"
                      {
        size_t len = strlen((yyvsp[-2].str)) + strlen((yyvsp[0].str)) + 2;
        char *combined = malloc(len);
        snprintf(combined, len, "%s %s", (yyvsp[-2].str), (yyvsp[0].str));
        (yyval.str) = combined;
        free((yyvsp[-2].str)); free((yyvsp[0].str));
    }
#line 1471 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"
    break;


#line 1475 "/data/data/com.termux/files/home/Xpriv/build/xpriv.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 227 "/data/data/com.termux/files/home/Xpriv/src/Bison/Linux-Mac-Os/xpriv.y"


void yyerror(const char *s) {
    fprintf(stderr, "[syntax error] %s\n", s);
}
