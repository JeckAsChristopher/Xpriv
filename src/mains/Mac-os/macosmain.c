#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include "debug.h"

extern int yyparse(void);
extern FILE *yyin;

#define ENABLE_EXEC_TIMER 1
#define VERSION "v1.0"

#define CLR_RESET   "\033[0m"
#define CLR_CYAN    "\033[1;36m"
#define CLR_GREEN   "\033[1;32m"
#define CLR_YELLOW  "\033[1;33m"
#define CLR_BLUE    "\033[1;34m"

void print_banner() {
    printf(CLR_CYAN "[PR Lang Interpreter]" CLR_RESET " - " CLR_GREEN "Privilege Root Language" CLR_RESET "\n");
    printf("Author: Jeck | Root-level Script Execution\n");
    printf("Version: " VERSION "\n\n");
}

void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <script.xpriv>\n", prog_name);
    fprintf(stderr, "       %s --help | --version\n", prog_name);
}

int has_valid_extension(const char *filename, const char *ext) {
    const char *dot = strrchr(filename, '.');
    return (dot && strcmp(dot, ext) == 0);
}

int main(int argc, char *argv[]) {
#if ENABLE_EXEC_TIMER
    clock_t start_time = clock();
#endif

    print_banner();

    if (argc < 2) {
        print_usage(argv[0]);
        xpriv_error(ERR_SYNTAX, "Missing input file argument.");
    }

    if (strcmp(argv[1], "--help") == 0) {
        print_usage(argv[0]);
        return EXIT_SUCCESS;
    }

    if (strcmp(argv[1], "--version") == 0) {
        printf("Xpriv Interpreter %s\n", VERSION);
        return EXIT_SUCCESS;
    }

    if (!has_valid_extension(argv[1], ".xpriv")) {
        xpriv_error(ERR_SYNTAX, "Invalid file type. Expected a '.xpriv' script.");
    }

    if (geteuid() != 0) {
        xpriv_error(ERR_ROOT_REQUIRED, "This program requires root access.\nTip: Run with: sudo %s <script.xpriv>", argv[0]);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        xpriv_error(ERR_FILE_OPEN, "Could not open '%s': %s", argv[1], strerror(errno));
    }

    xpriv_debug("MAIN", "Successfully opened file '%s'", argv[1]);

    yyin = file;

    printf("\n" CLR_BLUE "[Interpreter Started]" CLR_RESET " Parsing %s...\n\n", argv[1]);
    int result = yyparse();

    fclose(file);
    xpriv_debug("MAIN", "File closed.");

#if ENABLE_EXEC_TIMER
    clock_t end_time = clock();
    double exec_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\n" CLR_GREEN "Execution finished in %.3f seconds." CLR_RESET "\n", exec_time);
#endif

    return result == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
