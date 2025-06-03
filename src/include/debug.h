#ifndef XPRIV_DEBUG_H
#define XPRIV_DEBUG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <time.h>

typedef enum {
    ERR_NONE = 0,
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
    // Add new error types here
} ErrorType;

typedef struct {
    ErrorType type;
    int code;
    char message[512];
} XPrivError;

void xpriv_error(ErrorType type, const char *fmt, ...);
void xpriv_warn(const char *fmt, ...);
void xpriv_debug(const char *tag, const char *fmt, ...);
const XPrivError* xpriv_get_last_error(void);
void xpriv_set_log_file(const char *path);
void xpriv_set_exit_on_error(int value); // 1 = exit, 0 = don't exit

#endif // XPRIV_DEBUG_H
