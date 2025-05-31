#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

extern int yyparse(void);
extern FILE *yyin;

void print_banner() {
    printf("\033[1;36m[PR Lang Interpreter]\033[0m - \033[1;32mPrivilege Root Language\033[0m\n");
    printf("Author: Jeck | Root-level Script Execution\n\n");
}

void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <script.xpriv>\n", prog_name);
}

int has_valid_extension(const char *filename, const char *ext) {
    const char *dot = strrchr(filename, '.');
    return dot && strcmp(dot, ext) == 0;
}

int main(int argc, char *argv[]) {
    clock_t start_time = clock();

    print_banner();

    if (argc < 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    if (!has_valid_extension(argv[1], ".xpriv")) {
        fprintf(stderr, "\033[1;31mError:\033[0m Invalid file type. Expected a `.xpriv` script.\n");
        return EXIT_FAILURE;
    }

    if (geteuid() != 0) {
        fprintf(stderr, "\033[1;31mPermission Denied:\033[0m This program requires \033[1;33mroot access\033[0m.\n");
        fprintf(stderr, "Tip: Try running with \033[1;34msudo %s <script.xpriv>\033[0m\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    yyin = file;

    printf("\n\033[1;34m[Interpreter Started]\033[0m Parsing %s...\n\n", argv[1]);
    int result = yyparse();
    fclose(file);

    clock_t end_time = clock();
    double exec_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("\n\033[1;32mExecution finished in %.3f seconds.\033[0m\n", exec_time);
    return result == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
