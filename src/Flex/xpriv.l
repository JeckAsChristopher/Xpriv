%option noyywrap
%{
#include "xpriv.tab.h"
#include <string.h>
%}

%%

"requires"      { return REQUIRES; }
"root"          { return ROOT; }
"let"           { return LET; }
"syscall"       { return SYSCALL; }
"print"         { return PRINT; }
"loop"          { return LOOP; }
"from"          { return FROM; }
"to"            { return TO; }
"when"          { return WHEN; }
"exec"          { return EXEC; }
"require_bin"   { return REQUIRE_BIN; }
"env"           { return ENV; }
"sleep"         { return SLEEP; }
"exit"          { return EXIT; }
"as_root"       { return ASROOT; }
"=="            { return EQ; }
"!="            { return NEQ; }
"<="            { return LEQ; }
">="            { return GEQ; }
"<"             { return LT; }
">"             { return GT; }

"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MUL; }
"/"             { return DIV; }

"{"             { return LBRACE; }
"}"             { return RBRACE; }
"("             { return LPAREN; }
")"             { return RPAREN; }
","             { return COMMA; }
"="             { return ASSIGN; }

\"[^\"]*\"      { yylval.str = strdup(yytext); return STRING; }
[0-9]+          { yylval.num = atoi(yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return IDENT; }

"//".*          { /* ignore single-line comments */ }

[ \t\r\n]+      { /* skip whitespace */ }
.               { return *yytext; }

%%
