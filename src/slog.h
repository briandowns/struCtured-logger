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
    SLOG_STRING
} slog_field_types;

/**
 * slog_field_t
 */
struct slog_field_t {
    uint8_t type;
    union {
        int int_value;
        int64_t int64_value;
        double double_value;
        char *char_value;
    };
} slog_field_t;  

/** 
 * slog_int is used to add an integer value
 * to the log entry.
 */
struct slog_field_t *slog_int(const int value);

/** 
 * slog_int64 is used to add a 64 bit integer
 * value to the log entry.
 */
struct slog_field_t *slog_int64(const int64_t value);

/** 
 * slog_double is used to add a double to the 
 * log entry.
 */
struct slog_field_t *slog_double(const double value);

/** 
 * slog_string is used to add a string to the 
 * log entry.
 */
struct slog_field_t *slog_string(const char *value);

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

#endif /* end _SLOG_H */
