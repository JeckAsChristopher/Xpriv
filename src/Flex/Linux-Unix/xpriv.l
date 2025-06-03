%option noyywrap

%{
#include "xpriv.tab.h"
#include <string.h>
#include <stdlib.h>

extern YYSTYPE yylval;
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
"fork"          { return FORK; }
"execve"        { return EXECVE; }
"kill"          { return KILL; }
"wait"          { return WAIT; }
"open"          { return OPEN; }
"close"         { return CLOSE; }
"read"          { return READ; }
"write"         { return WRITE; }
"pipe"          { return PIPE; }
"chmod"         { return CHMOD; }
"chown"         { return CHOWN; }
"mkdir"         { return MKDIR; }
"rmdir"         { return RMDIR; }
"stat"          { return STAT; }
"connect"       { return CONNECT; }
"bind"          { return BIND; }
"listen"        { return LISTEN; }
"accept"        { return ACCEPT; }
"socket"        { return SOCKET; }
"getenv"        { return GETENV; }

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

\"[^\"]*\"      {
                  int len = yyleng - 2; // exclude quotes
                  char *str = (char *)malloc(len + 1);
                  if (!str) {
                    fprintf(stderr, "Out of memory\n");
                    exit(1);
                  }
                  strncpy(str, yytext + 1, len);
                  str[len] = '\0';
                  yylval.str = str;
                  return STRING;
                }

[0-9]+          {
                  yylval.num = atoi(yytext);
                  return NUMBER;
                }

[a-zA-Z_][a-zA-Z0-9_]* {
                          yylval.str = strdup(yytext);
                          return IDENT;
                        }

"//".*          { /* skip comment */ }

[ \t\r\n]+      { /* skip whitespace */ }

.               { return *yytext; }

%%
