%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>  // For geteuid() and sleep()

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
%token EXEC REQUIRE_BIN ENV SLEEP EXIT ASROOT
%token EQ NEQ LT GT LEQ GEQ
%token PLUS MINUS MUL DIV
%token LBRACE RBRACE LPAREN RPAREN COMMA ASSIGN
%token FORK EXECVE KILL WAIT OPEN CLOSE READ WRITE PIPE CHMOD CHOWN MKDIR RMDIR STAT CONNECT BIND LISTEN ACCEPT SOCKET GETENV

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
            fprintf(stderr, "[error] root privileges required.\n");
            exit(EXIT_FAILURE);
        } else {
            printf("[root granted]\n");
        }
    }
    | /* empty */
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
    | exec_stmt
    | require_bin_stmt
    | sleep_stmt
    | env_stmt
    | exit_stmt
    | as_root_block
;

var_decl:
    LET IDENT ASSIGN expr {
        printf("[var] %s = %s\n", $2, $4);
        free($2);
        free($4);
    }
;

expr:
    STRING {
        $$ = $1;  // STRING already dynamically allocated by lexer
    }
    | IDENT {
        $$ = strdup($1);
        free($1);
    }
    | NUMBER {
        char buf[32];
        snprintf(buf, sizeof(buf), "%d", $1);
        $$ = strdup(buf);
    }
    | expr PLUS expr {
        size_t len = strlen($1) + strlen($3) + 2;
        char *buf = malloc(len + 1);
        snprintf(buf, len + 1, "%s+%s", $1, $3);
        $$ = buf;
        free($1);
        free($3);
    }
    | expr MINUS expr {
        size_t len = strlen($1) + strlen($3) + 2;
        char *buf = malloc(len + 1);
        snprintf(buf, len + 1, "%s-%s", $1, $3);
        $$ = buf;
        free($1);
        free($3);
    }
    | expr MUL expr {
        size_t len = strlen($1) + strlen($3) + 2;
        char *buf = malloc(len + 1);
        snprintf(buf, len + 1, "%s*%s", $1, $3);
        $$ = buf;
        free($1);
        free($3);
    }
    | expr DIV expr {
        size_t len = strlen($1) + strlen($3) + 2;
        char *buf = malloc(len + 1);
        snprintf(buf, len + 1, "%s/%s", $1, $3);
        $$ = buf;
        free($1);
        free($3);
    }
    | LPAREN expr RPAREN {
        $$ = strdup($2);
        free($2);
    }
;

condition:
    expr EQ expr   { free($1); free($3); $$ = strdup("=="); }
    | expr NEQ expr { free($1); free($3); $$ = strdup("!="); }
    | expr LT expr  { free($1); free($3); $$ = strdup("<"); }
    | expr GT expr  { free($1); free($3); $$ = strdup(">"); }
    | expr LEQ expr { free($1); free($3); $$ = strdup("<="); }
    | expr GEQ expr { free($1); free($3); $$ = strdup(">="); }
;

syscall_stmt:
    SYSCALL IDENT LPAREN syscall_args RPAREN {
        if (!root_required) {
            fprintf(stderr, "[error] syscall requires 'requires root'.\n");
            exit(EXIT_FAILURE);
        }
        char cmd[512];
        snprintf(cmd, sizeof(cmd), "%s %s", $2, $4 ? $4 : "");
        int result = system(cmd);
        printf("[syscall] %s => %d\n", cmd, result);
        free($2);
        if ($4) free($4);
    }
;

exec_stmt:
    EXEC LPAREN expr RPAREN {
        printf("[exec] running: %s\n", $3);
        int ret = system($3);
        printf("[exec return] %d\n", ret);
        free($3);
    }
;

require_bin_stmt:
    REQUIRE_BIN LPAREN expr RPAREN {
        char check[256];
        snprintf(check, sizeof(check), "command -v %s >/dev/null 2>&1", $3);
        int exists = system(check);
        if (exists != 0) {
            fprintf(stderr, "[missing binary] %s\n", $3);
            exit(127);
        } else {
            printf("[bin found] %s\n", $3);
        }
        free($3);
    }
;

env_stmt:
    ENV LPAREN expr RPAREN {
        char *val = getenv($3);
        if (val) {
            printf("[env] %s=%s\n", $3, val);
        } else {
            printf("[env] %s is undefined\n", $3);
        }
        free($3);
    }
;

sleep_stmt:
    SLEEP LPAREN NUMBER RPAREN {
        printf("[sleep] %d seconds\n", $3);
        sleep($3);
    }
;

exit_stmt:
    EXIT LPAREN NUMBER RPAREN {
        printf("[exit] code %d\n", $3);
        exit($3);
    }
;

as_root_block:
    ASROOT LBRACE statements RBRACE {
        if (geteuid() != 0) {
            fprintf(stderr, "[as_root error] not running as root.\n");
            exit(EXIT_FAILURE);
        }
        printf("[as_root block executed]\n");
        // TODO: Implement executing nested statements here.
    }
;

print_stmt:
    PRINT LPAREN expr_list RPAREN { /* printing handled in expr_list */ }
;

expr_list:
    expr {
        printf("[print] %s\n", $1);
        free($1);
    }
    | expr_list COMMA expr {
        printf("[print] %s\n", $3);
        free($3);
    }
;

loop_stmt:
    LOOP IDENT FROM NUMBER TO NUMBER LBRACE statements RBRACE {
        for (int i = $4; i <= $6; ++i) {
            printf("[loop %s=%d]\n", $2, i);
            // TODO: Execute statements inside loop per iteration.
        }
        free($2);
    }
;

conditional_stmt:
    WHEN condition LBRACE statements RBRACE {
        printf("[when] condition evaluated (stubbed as true)\n");
        // TODO: Evaluate condition properly and execute statements if true.
    }
;

syscall_args:
    /* empty */ {
        $$ = strdup("");
    }
    | expr {
        $$ = $1; // pass the string directly
    }
    | syscall_args COMMA expr {
        size_t len = strlen($1) + strlen($3) + 2;
        char *combined = malloc(len + 1);
        snprintf(combined, len + 1, "%s %s", $1, $3);
        free($1);
        free($3);
        $$ = combined;
    }
;

%%

void yyerror(const char *s) {
    fprintf(stderr, "[syntax error] %s\n", s);
}
