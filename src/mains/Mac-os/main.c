#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "debug.h"

// External parser
extern int yyparse(void);
extern FILE *yyin;

// --- Config ---
#define ENABLE_EXEC_TIMER 1
#define VERSION "v1.2"

// ANSI escape color codes
#define CLR_RESET   "\033[0m"
#define CLR_CYAN    "\033[1;36m"
#define CLR_GREEN   "\033[1;32m"
#define CLR_YELLOW  "\033[1;33m"
#define CLR_BLUE    "\033[1;34m"
#define CLR_RED     "\033[1;31m"

// Function to print the banner
void print_banner() {
    printf(CLR_CYAN "[PR Lang Interpreter]" CLR_RESET " - " CLR_GREEN "Privilege Root Language" CLR_RESET "\n");
    printf("Author: Jeck | Root-Level Script Execution\n");
    printf("Version: " VERSION "\n\n");
}

// Function to print usage instructions
void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage:\n  %s <script.xpriv>\n  %s --help | --version\n", prog_name, prog_name);
}

// Check if the filename has the valid ".xpriv" extension
int has_valid_extension(const char *filename) {
    const char *dot = strrchr(filename, '.');
    return (dot && strcmp(dot, ".xpriv") == 0);
}

// Check if file exists and is a regular file
int file_exists(const char *path) {
    struct stat s;
    return (stat(path, &s) == 0 && S_ISREG(s.st_mode));
}

// Main entry point
int main(int argc, char *argv[]) {
#if ENABLE_EXEC_TIMER
    clock_t start_time = clock();
#endif

    print_banner();

    // Argument checks
    if (argc < 2) {
        print_usage(argv[0]);
        xpriv_error(ERR_SYNTAX, "Missing input file argument.");
    }

    const char *input_path = argv[1];

    // Help and version flags
    if (strcmp(input_path, "--help") == 0) {
        print_usage(argv[0]);
        return EXIT_SUCCESS;
    }

    if (strcmp(input_path, "--version") == 0) {
        printf("Xpriv Interpreter %s\n", VERSION);
        return EXIT_SUCCESS;
    }

    // Extension check
    if (!has_valid_extension(input_path)) {
        xpriv_error(ERR_SYNTAX, "Invalid file type. Expected a '.xpriv' script.");
    }

    // File existence check
    if (!file_exists(input_path)) {
        xpriv_error(ERR_FILE_OPEN, "File not found or not a regular file: '%s'", input_path);
    }

    // Check root privilege
    if (geteuid() != 0) {
        xpriv_error(ERR_ROOT_REQUIRED, "Root access is required.\nTip: Run with: sudo %s <script.xpriv>", argv[0]);
    }

    // File opening
    FILE *file = fopen(input_path, "r");
    if (!file) {
        xpriv_error(ERR_FILE_OPEN, "Could not open '%s': %s", input_path, strerror(errno));
    }

    xpriv_debug("MAIN", "Successfully opened file '%s'", input_path);
    yyin = file;

    // Start parsing
    printf("\n" CLR_BLUE "[Interpreter Started]" CLR_RESET " Parsing %s...\n\n", input_path);
    int parse_result = yyparse();

    fclose(file);
    xpriv_debug("MAIN", "File closed.");

#if ENABLE_EXEC_TIMER
    clock_t end_time = clock();
    double exec_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("\n" CLR_GREEN "Execution finished in %.3f seconds." CLR_RESET "\n", exec_time);
#endif

    if (parse_result == 0) {
        printf(CLR_GREEN "\n[SUCCESS]" CLR_RESET " Script executed without errors.\n");
        return EXIT_SUCCESS;
    } else {
        printf(CLR_RED "\n[FAILURE]" CLR_RESET " Script parsing failed with errors.\n");
        return EXIT_FAILURE;
    }
}
