#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern int yyparse(void);
extern FILE *yyin;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file.xpriv>\n", argv[0]);
        return 1;
    }

    // Check for root access
    if (geteuid() != 0) {
        fprintf(stderr, "Error: Permission denied. Do Root installed on your device?\n");
        return 1;
    }

    // Open the .xpriv file
    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    // Set input for the parser
    yyin = file;

    // Parse and execute
    int result = yyparse();

    fclose(file);
    return result;
}
