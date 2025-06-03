#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

#include "debug.h"

// External parser
extern int yyparse(void);
extern FILE *yyin;

// --- Configuration ---
#define ENABLE_EXEC_TIMER 1
#define SUPPORTED_EXTENSION ".xpriv"
#define VERSION "v1.2"

// --- ANSI Color Macros ---
#define CLR_RESET   "\033[0m"
#define CLR_CYAN    "\033[1;36m"
#define CLR_GREEN   "\033[1;32m"
#define CLR_YELLOW  "\033[1;33m"
#define CLR_BLUE    "\033[1;34m"

// --- Banner & Usage ---
void print_banner() {
    printf(CLR_CYAN "[PR Lang Interpreter]" CLR_RESET " - " CLR_GREEN "Privilege Root Language" CLR_RESET "\n");
    printf("Author: Jeck | Root-level Script Execution\n");
    printf("Version: " VERSION "\n\n");
}

void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <script%s>\n", prog_name, SUPPORTED_EXTENSION);
    fprintf(stderr, "       %s --help | --version\n", prog_name);
}

// --- Validation Utilities ---
int has_valid_extension(const char *filename) {
    const char *dot = strrchr(filename, '.');
    return (dot && strcmp(dot, SUPPORTED_EXTENSION) == 0);
}

void ensure_root(const char *prog_name) {
    if (geteuid() != 0) {
        xpriv_error(ERR_ROOT_REQUIRED, "Root access required.\nTip: Run with: sudo %s <file%s>", prog_name, SUPPORTED_EXTENSION);
    }
}

void open_script_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        xpriv_error(ERR_FILE_OPEN, "Could not open '%s': %s", filename, strerror(errno));
    }
    yyin = file;
    xpriv_debug("MAIN", "Successfully opened file '%s'", filename);
}

// --- Entry Point ---
int main(int argc, char *argv[]) {
#if ENABLE_EXEC_TIMER
    clock_t start_time = clock();
#endif

    print_banner();

    if (argc < 2) {
        print_usage(argv[0]);
        xpriv_error(ERR_SYNTAX, "Missing input file argument.");
    }

    const char *arg = argv[1];

    if (strcmp(arg, "--help") == 0) {
        print_usage(argv[0]);
        return EXIT_SUCCESS;
    }

    if (strcmp(arg, "--version") == 0) {
        printf("Xpriv Interpreter %s\n", VERSION);
        return EXIT_SUCCESS;
    }

    if (!has_valid_extension(arg)) {
        xpriv_error(ERR_SYNTAX, "Invalid file extension. Expected a '%s' script.", SUPPORTED_EXTENSION);
    }

    ensure_root(argv[0]);
    open_script_file(arg);

    printf("\n" CLR_BLUE "[Interpreter Started]" CLR_RESET " Parsing %s...\n\n", arg);

    int parse_result = yyparse();
    fclose(yyin);
    xpriv_debug("MAIN", "Script file closed.");

#if ENABLE_EXEC_TIMER
    clock_t end_time = clock();
    double exec_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\n" CLR_GREEN "Execution finished in %.3f seconds." CLR_RESET "\n", exec_time);
#endif

    return parse_result == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
