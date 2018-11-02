#ifndef _SLOG_H
#define _SLOG_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SLOG_TRACE "trace"
#define SLOG_DEBUG "debug"
#define SLOG_INFO  "info"
#define SLOG_WARN  "warn"
#define SLOG_ERROR "error"
#define SLOG_FATAL "fatal"

/**
 * slog field types
 */
static enum {
    SLOG_INT,
    SLOG_INT64,
    SLOG_DOUBLE,
    SLOG_STRING,
};

/**
 * slog_field_t
 */
typedef struct {
    uint8_t type;
    union {
        int int_value;
        int64_t int64_value;
        double double_value;
        char *char_value;
    };
} slog_field_t;  

slog_field_t *slog_field_int(void *value);

/**
 * slog_output contains the location we're
 * going to write our log entries to
 */
FILE *slog_output;

enum {
    SLOG_OUT_STDERR,
    SLOG_OUT_STDOUT,
};

/**
 * slog_init initializes the logger and sets up
 * where the logger writes to.
 */
void slog_init(FILE *out);

/**
 * reallog provides the functionality of the logger. Returns
 * the number os bytes written.
 */
int reallog(char *l, ...);

/**
 * slog is the main entry point for adding data
 * to the logger to create log entries
 */
#define slog(l, ...) ({ reallog(l, __VA_ARGS__, NULL); })

#endif // end _SLOG_H 
