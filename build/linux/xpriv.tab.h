/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_DATA_DATA_COM_TERMUX_FILES_HOME_XPRIV_BUILD_LINUX_XPRIV_TAB_H_INCLUDED
# define YY_YY_DATA_DATA_COM_TERMUX_FILES_HOME_XPRIV_BUILD_LINUX_XPRIV_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    STRING = 258,                  /* STRING  */
    IDENT = 259,                   /* IDENT  */
    NUMBER = 260,                  /* NUMBER  */
    REQUIRES = 261,                /* REQUIRES  */
    ROOT = 262,                    /* ROOT  */
    LET = 263,                     /* LET  */
    SYSCALL = 264,                 /* SYSCALL  */
    PRINT = 265,                   /* PRINT  */
    LOOP = 266,                    /* LOOP  */
    TIMES = 267,                   /* TIMES  */
    FROM = 268,                    /* FROM  */
    TO = 269,                      /* TO  */
    WHEN = 270,                    /* WHEN  */
    EQ = 271,                      /* EQ  */
    NEQ = 272,                     /* NEQ  */
    LT = 273,                      /* LT  */
    GT = 274,                      /* GT  */
    LEQ = 275,                     /* LEQ  */
    GEQ = 276,                     /* GEQ  */
    PLUS = 277,                    /* PLUS  */
    MINUS = 278,                   /* MINUS  */
    MUL = 279,                     /* MUL  */
    DIV = 280,                     /* DIV  */
    LBRACE = 281,                  /* LBRACE  */
    RBRACE = 282,                  /* RBRACE  */
    LPAREN = 283,                  /* LPAREN  */
    RPAREN = 284,                  /* RPAREN  */
    COMMA = 285,                   /* COMMA  */
    ASSIGN = 286                   /* ASSIGN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 13 "/data/data/com.termux/files/home/Xpriv/src/Bison/xpriv.y"

    char* str;
    int num;

#line 100 "/data/data/com.termux/files/home/Xpriv/build/linux/xpriv.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_DATA_DATA_COM_TERMUX_FILES_HOME_XPRIV_BUILD_LINUX_XPRIV_TAB_H_INCLUDED  */
