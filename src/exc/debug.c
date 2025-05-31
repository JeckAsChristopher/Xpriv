#include "debug.h"

void xpriv_error(ErrorType type, const char *fmt, ...) {
    const char *prefix;

    switch (type) {
        case ERR_SYNTAX:         prefix = "Syntax Error"; break;
        case ERR_ROOT_REQUIRED:  prefix = "Root Privilege Error"; break;
        case ERR_SYSCALL_FAIL:   prefix = "Syscall Error"; break;
        case ERR_FILE_OPEN:      prefix = "File Error"; break;
        case ERR_VAR_DECL:       prefix = "Declaration Error"; break;
        case ERR_UNKNOWN_IDENT:  prefix = "Unknown Identifier"; break;
        case ERR_RUNTIME:        prefix = "Runtime Error"; break;
        case ERR_INTERNAL:       prefix = "Internal Error"; break;
        default:                 prefix = "Unknown Error"; break;
    }

    fprintf(stderr, "[%s] ", prefix);

    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);

    fprintf(stderr, "\n");
    exit(EXIT_FAILURE);
}

void xpriv_debug(const char *tag, const char *fmt, ...) {
#ifdef XPRIV_DEBUG
    fprintf(stderr, "[DEBUG][%s] ", tag);
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fprintf(stderr, "\n");
#endif
}
