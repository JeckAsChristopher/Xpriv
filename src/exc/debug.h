#ifndef DEBUG_H
#define DEBUG_H

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
    ERR_INTERNAL
} ErrorType;

// Core debug/error function
void xpriv_error(ErrorType type, const char *fmt, ...);

// Debug info (optional verbose logging)
void xpriv_debug(const char *tag, const char *fmt, ...);

#endif // DEBUG_H
