%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void yyerror(const char *s);
int yylex(void);

int root_required = 0;
%}

%union {
    char* str;
    int num;
}

%token <str> STRING IDENT
%token <num> NUMBER
%token REQUIRES ROOT LET SYSCALL PRINT LOOP TIMES FROM TO WHEN
%token EQ NEQ LT GT LEQ GEQ
%token PLUS MINUS MUL DIV
%token LBRACE RBRACE LPAREN RPAREN COMMA ASSIGN

%type <str> expr syscall_args condition

%start program

%%

program:
    requires_block statements
    ;

requires_block:
      REQUIRES ROOT {
          root_required = 1;
          if (geteuid() != 0) {
              fprintf(stderr, "Error: This program requires root privileges.\n");
              exit(EXIT_FAILURE);
          } else {
              printf("Root privilege confirmed.\n");
          }
      }
    | /* optional */
    ;

statements:
      /* empty */
    | statements statement
    ;

statement:
      var_decl
    | syscall_stmt
    | print_stmt
    | loop_stmt
    | conditional_stmt
    ;

var_decl:
    LET IDENT ASSIGN expr {
        printf("var %s = %s\n", $2, $4);
        free($2); free($4);
    }
    ;

expr:
      STRING { $$ = $1; }
    | IDENT  { $$ = strdup($1); free($1); }
    | NUMBER {
        char buf[32];
        snprintf(buf, sizeof(buf), "%d", $1);
        $$ = strdup(buf);
    }
    | expr PLUS expr {
        char *buf = malloc(strlen($1) + strlen($3) + 2);
        sprintf(buf, "%s+%s", $1, $3);
        $$ = buf;
        free($1); free($3);
    }
    | expr MINUS expr {
        char *buf = malloc(strlen($1) + strlen($3) + 2);
        sprintf(buf, "%s-%s", $1, $3);
        $$ = buf;
        free($1); free($3);
    }
    | expr MUL expr {
        char *buf = malloc(strlen($1) + strlen($3) + 2);
        sprintf(buf, "%s*%s", $1, $3);
        $$ = buf;
        free($1); free($3);
    }
    | expr DIV expr {
        char *buf = malloc(strlen($1) + strlen($3) + 2);
        sprintf(buf, "%s/%s", $1, $3);
        $$ = buf;
        free($1); free($3);
    }
    | LPAREN expr RPAREN {
        $$ = strdup($2);
        free($2);
    }
    ;

condition:
      expr EQ expr   { $$ = strdup("=="); }
    | expr NEQ expr  { $$ = strdup("!="); }
    | expr LT expr   { $$ = strdup("<"); }
    | expr GT expr   { $$ = strdup(">"); }
    | expr LEQ expr  { $$ = strdup("<="); }
    | expr GEQ expr  { $$ = strdup(">="); }
    ;

syscall_stmt:
    SYSCALL IDENT LPAREN syscall_args RPAREN {
        if (!root_required) {
            fprintf(stderr, "Error: 'syscall' requires 'requires root' declaration.\n");
            exit(EXIT_FAILURE);
        }
        char cmd[512];
        snprintf(cmd, sizeof(cmd), "%s %s", $2, $4 ? $4 : "");
        int result = system(cmd);
        printf("syscall %s result: %d\n", cmd, result);
        free($2); if ($4) free($4);
    }
    ;

syscall_args:
      /* empty */ { $$ = strdup(""); }
    | expr        { $$ = strdup($1); free($1); }
    | expr COMMA expr {
        size_t len = strlen($1) + strlen($3) + 2;
        char *combined = malloc(len);
        snprintf(combined, len, "%s %s", $1, $3);
        $$ = combined;
        free($1); free($3);
    }
    ;

print_stmt:
    PRINT LPAREN expr RPAREN {
        if ($3) {
            printf("[print]: %s\n", $3);
            free($3);
        }
    }
    ;

loop_stmt:
    LOOP IDENT FROM NUMBER TO NUMBER LBRACE statements RBRACE {
        for (int i = $4; i <= $6; i++) {
            printf("[loop %s=%d]\n", $2, i);
            // Execute inner block
        }
        free($2);
    }
    ;

conditional_stmt:
    WHEN condition LBRACE statements RBRACE {
        printf("[when condition met]\n");
        // Evaluate and run condition block
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error: %s\n", s);
}
