#include "debug.h"

XPrivError last_error;

static const char* error_type_to_string(ErrorType type) {
    switch (type) {
        case ERR_SYNTAX:              return "Syntax Error";
        case ERR_ROOT_REQUIRED:       return "Root Privilege Error";
        case ERR_SYSCALL_FAIL:        return "Syscall Error";
        case ERR_FILE_OPEN:           return "File Error";
        case ERR_VAR_DECL:            return "Declaration Error";
        case ERR_UNKNOWN_IDENT:       return "Unknown Identifier";
        case ERR_RUNTIME:             return "Runtime Error";
        case ERR_INTERNAL:            return "Internal Error";
        case ERR_TYPE_MISMATCH:       return "Type Mismatch Error";
        case ERR_NULL_POINTER:        return "Null Pointer Error";
        case ERR_INDEX_OUT_OF_BOUNDS: return "Index Out of Bounds";
        case ERR_PERMISSION_DENIED:   return "Permission Denied";
        case ERR_DIVISION_BY_ZERO:    return "Division by Zero";
        case ERR_UNSUPPORTED_FEATURE: return "Unsupported Feature";
        default:                      return "Unknown Error";
    }
}

static void log_to_file(const char *msg) {
    FILE *log = fopen("/var/log/xpriv.log", "a");
    if (log) {
        fprintf(log, "%s\n", msg);
        fclose(log);
    }
}

void xpriv_error(ErrorType type, const char *fmt, ...) {
    char timestamp[64];
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(timestamp, sizeof(timestamp), "[%Y-%m-%d %H:%M:%S]", tm_info);

    const char *prefix = error_type_to_string(type);

    va_list args;
    va_start(args, fmt);
    vsnprintf(last_error.message, sizeof(last_error.message), fmt, args);
    va_end(args);

    last_error.type = type;
    last_error.code = type;  // You can map this to custom values if needed.

    fprintf(stderr, "\033[1;31m%s [ERROR][%s]\033[0m %s", timestamp, prefix, last_error.message);

    // Include errno if applicable
    if (errno != 0) {
        fprintf(stderr, " (errno: %d - %s)", errno, strerror(errno));
    }

    fprintf(stderr, "\n");

    // Log to file
    char full_log[1024];
    snprintf(full_log, sizeof(full_log), "%s [ERROR][%s] %s", timestamp, prefix, last_error.message);
    log_to_file(full_log);

    exit(type); // Or use a custom exit code per type
}

void xpriv_debug(const char *tag, const char *fmt, ...) {
#ifdef XPRIV_DEBUG
    char timestamp[64];
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    strftime(timestamp, sizeof(timestamp), "[%Y-%m-%d %H:%M:%S]", tm_info);

    fprintf(stderr, "\033[1;34m%s [DEBUG][%s]\033[0m ", timestamp, tag);
    va_list args;
    va_start(args, fmt);
    vfprintf(stderr, fmt, args);
    va_end(args);
    fprintf(stderr, "\n");
#endif
}

const XPrivError* xpriv_get_last_error() {
    return &last_error;
}
