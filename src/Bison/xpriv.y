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

%%

program:
    requires_block statements
    ;

requires_block:
      REQUIRES ROOT {
        root_required = 1;
        if (geteuid() != 0) {
            fprintf(stderr, "Error: Permission denied. Do Root installed on your device?\n");
            exit(1);
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
        printf("var %s = %s\n", $2, $4);
    }
    ;

expr:
      STRING { $$ = $1; }
    | IDENT  { $$ = $1; }
    ;

syscall_stmt:
    SYSCALL IDENT LPAREN syscall_args RPAREN {
        char cmd[512];
        snprintf(cmd, sizeof(cmd), "%s %s", $2, $4 ? $4 : "");
        int result = system(cmd);
        if (result != 0) {
            fprintf(stderr, "Error: syscall '%s' failed.\n", cmd);
        }
        if ($4) free($4);
    }
    ;

syscall_args:
      /* empty */ { $$ = NULL; }
    | expr        { $$ = strdup($1); }
    | expr COMMA expr {
        size_t len = strlen($1) + strlen($3) + 2;
        char *combined = (char*)malloc(len);
        if (combined) {
            snprintf(combined, len, "%s %s", $1, $3);
        }
        $$ = combined;
    }
    ;

print_stmt:
    PRINT LPAREN expr RPAREN {
        printf("%s\n", $3);
    }
    ;

loop_stmt:
    LOOP NUMBER TIMES LBRACE statements RBRACE {
        for (int i = 0; i < $2; i++) {
            printf("[loop %d]\n", i + 1);
            // You can evaluate nested statements here in future enhancements.
        }
    }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error: %s\n", s);
}
