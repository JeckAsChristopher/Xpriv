#ifndef XPRIV_DEBUG_H
#define XPRIV_DEBUG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

// Error types
typedef enum {
    ERR_SYNTAX,
    ERR_ROOT_REQUIRED,
    ERR_SYSCALL_FAIL,
    ERR_FILE_OPEN,
    ERR_VAR_DECL,
    ERR_UNKNOWN_IDENT,
    ERR_RUNTIME,
    ERR_INTERNAL,
    ERR_TYPE_MISMATCH,
    ERR_NULL_POINTER,
    ERR_INDEX_OUT_OF_BOUNDS,
    ERR_PERMISSION_DENIED,
    ERR_DIVISION_BY_ZERO,
    ERR_UNSUPPORTED_FEATURE
} ErrorType;

// Error and debug functions
void xpriv_error(ErrorType type, const char *fmt, ...);
void xpriv_debug(const char *tag, const char *fmt, ...);

#endif // XPRIV_DEBUG_H
