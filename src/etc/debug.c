#include "debug.h"

void xpriv_error(ErrorType type, const char *fmt, ...) {
    const char *prefix;

    switch (type) {
        case ERR_SYNTAX:             prefix = "Syntax Error"; break;
        case ERR_ROOT_REQUIRED:      prefix = "Root Privilege Error"; break;
        case ERR_SYSCALL_FAIL:       prefix = "Syscall Error"; break;
        case ERR_FILE_OPEN:          prefix = "File Error"; break;
        case ERR_VAR_DECL:           prefix = "Declaration Error"; break;
        case ERR_UNKNOWN_IDENT:      prefix = "Unknown Identifier"; break;
        case ERR_RUNTIME:            prefix = "Runtime Error"; break;
        case ERR_INTERNAL:           prefix = "Internal Error"; break;
        case ERR_TYPE_MISMATCH:      prefix = "Type Mismatch Error"; break;
        case ERR_NULL_POINTER:       prefix = "Null Pointer Error"; break;
        case ERR_INDEX_OUT_OF_BOUNDS:prefix = "Index Out of Bounds"; break;
        case ERR_PERMISSION_DENIED:  prefix = "Permission Denied"; break;
        case ERR_DIVISION_BY_ZERO:   prefix = "Division by Zero"; break;
        case ERR_UNSUPPORTED_FEATURE:prefix = "Unsupported Feature"; break;
        default:                     prefix = "Unknown Error"; break;
    }

    fprintf(stderr, "\033[1;31m[ERROR][%s]\033[0m ", prefix);

    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);

    fprintf(stderr, "\n");
    exit(EXIT_FAILURE);
}

void xpriv_debug(const char *tag, const char *fmt, ...) {
#ifdef XPRIV_DEBUG
    fprintf(stderr, "\033[1;34m[DEBUG][%s]\033[0m ", tag);
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fprintf(stderr, "\n");
#endif
}
