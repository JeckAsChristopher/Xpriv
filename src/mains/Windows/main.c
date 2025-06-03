#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include <windows.h>
#include <shellapi.h>
#include "debug.h"

// --- External Parser ---
extern int yyparse(void);
extern FILE *yyin;

// --- Config ---
#define ENABLE_EXEC_TIMER 1
#define VERSION "v1.2"

// --- ANSI Color Codes ---
#define CLR_RESET   "\033[0m"
#define CLR_CYAN    "\033[1;36m"
#define CLR_GREEN   "\033[1;32m"
#define CLR_YELLOW  "\033[1;33m"
#define CLR_BLUE    "\033[1;34m"

// --- Enable ANSI Colors in Windows Console ---
void enable_virtual_terminal_processing() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return;

    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode)) return;

    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

// --- Display Banner ---
void print_banner() {
    printf(CLR_CYAN "[PR Lang Interpreter]" CLR_RESET " - " CLR_GREEN "Privilege Root Language" CLR_RESET "\n");
    printf("Author: Jeck | Root-level Script Execution\n");
    printf("Version: " VERSION "\n\n");
}

// --- Display Usage Instructions ---
void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <script.xpriv>\n", prog_name);
    fprintf(stderr, "       %s --help | --version\n", prog_name);
}

// --- File Extension Validator ---
int has_valid_extension(const char *filename, const char *ext) {
    const char *dot = strrchr(filename, '.');
    return (dot && strcmp(dot, ext) == 0);
}

// --- Admin Privilege Checker (more robust) ---
int is_user_admin() {
    BOOL isAdmin = FALSE;
    PSID adminGroup = NULL;
    SID_IDENTIFIER_AUTHORITY ntAuthority = SECURITY_NT_AUTHORITY;

    if (AllocateAndInitializeSid(&ntAuthority, 2,
                                 SECURITY_BUILTIN_DOMAIN_RID,
                                 DOMAIN_ALIAS_RID_ADMINS,
                                 0, 0, 0, 0, 0, 0,
                                 &adminGroup)) {
        CheckTokenMembership(NULL, adminGroup, &isAdmin);
        FreeSid(adminGroup);
    }

    return isAdmin;
}

int main(int argc, char *argv[]) {
#if ENABLE_EXEC_TIMER
    clock_t start_time = clock();
#endif

    enable_virtual_terminal_processing();
    print_banner();

    // --- Argument Handling ---
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

    if (!has_valid_extension(arg, ".xpriv")) {
        xpriv_error(ERR_SYNTAX, "Invalid file type. Expected a '.xpriv' script.");
    }

    if (!is_user_admin()) {
        xpriv_error(ERR_ROOT_REQUIRED,
            "Administrator privileges are required.\nTip: Right-click the terminal and select 'Run as administrator'.");
    }

    // --- File Reading ---
    FILE *file = fopen(arg, "r");
    if (!file) {
        xpriv_error(ERR_FILE_OPEN, "Could not open '%s': %s", arg, strerror(errno));
    }

    xpriv_debug("MAIN", "Successfully opened file '%s'", arg);
    yyin = file;

    printf("\n" CLR_BLUE "[Interpreter Started]" CLR_RESET " Parsing %s...\n\n", arg);
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

// Link against shell32.lib and advapi32.lib for IsUserAnAdmin / CheckTokenMembership
#pragma comment(lib, "shell32.lib")
#pragma comment(lib, "advapi32.lib")
