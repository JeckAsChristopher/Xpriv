#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <errno.h>
#include <string.h>

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
    ERR_UNSUPPORTED_FEATURE,
    ERR_UNKNOWN
} ErrorType;

typedef struct {
    ErrorType type;
    char message[512];
    int code;
} XPrivError;

extern XPrivError last_error;

void xpriv_error(ErrorType type, const char *fmt, ...);
void xpriv_debug(const char *tag, const char *fmt, ...);
const XPrivError* xpriv_get_last_error();

#endif
