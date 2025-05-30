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
%token REQUIRES ROOT LET SYSCALL PRINT LOOP TIMES
%token LBRACE RBRACE LPAREN RPAREN COMMA ASSIGN

%type <str> expr syscall_args

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
    ;

var_decl:
    LET IDENT ASSIGN expr {
        if ($2 && $4) {
            printf("var %s = %s\n", $2, $4);
        } else {
            fprintf(stderr, "Error: Invalid variable declaration.\n");
        }
        free($2);
        free($4);
    }
    ;

expr:
      STRING { $$ = $1; }
    | IDENT  { $$ = strdup($1); free($1); }
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
        if (result != 0) {
            fprintf(stderr, "syscall failed: %s\n", cmd);
        } else {
            printf("syscall executed: %s\n", cmd);
        }
        free($2);
        if ($4) free($4);
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
            printf("%s\n", $3);
            free($3);
        }
    }
    ;

loop_stmt:
    LOOP NUMBER TIMES LBRACE statements RBRACE {
        for (int i = 0; i < $2; i++) {
            printf("[loop %d]\n", i + 1);
            // Future: Evaluate nested statements here.
        }
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error: %s\n", s);
}
