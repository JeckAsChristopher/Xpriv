%option noyywrap
%{
#include "xpriv.tab.h"
#include <string.h>
%}

%%

"requires"          { return REQUIRES; }
"root"              { return ROOT; }
"let"               { return LET; }
"syscall"           { return SYSCALL; }
"print"             { return PRINT; }
"loop"              { return LOOP; }
"times"             { return TIMES; }
"{"                 { return LBRACE; }
"}"                 { return RBRACE; }
"("                 { return LPAREN; }
")"                 { return RPAREN; }
","                 { return COMMA; }
"="                 { return ASSIGN; }

[0-9]+              { yylval.num = atoi(yytext); return NUMBER; }
\"[^\"]*\"          { yylval.str = strdup(yytext); return STRING; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return IDENT; }

[ \t\r\n]+          { }
.                   { return *yytext; }

%%
