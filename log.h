#ifndef _LOG_H
#define _LOG_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define LOG_TRACE "trace"
#define LOG_DEBUG "debug"
#define LOG_INFO  "info"
#define LOG_WARN  "warn"
#define LOG_ERROR "error"
#define LOG_FATAL "fatal"

/**
 * log field types
 */
static enum {
    LOG_INT,
    LOG_INT64,
    LOG_DOUBLE,
    LOG_STRING
} log_field_types;

/**
 * log_field_t
 */
struct log_field_t {
    uint8_t type;
    union {
        int int_value;
        int64_t int64_value;
        double double_value;
        char *char_value;
    };
} log_field_t;  

/** 
 * log_int is used to add an integer value
 * to the log entry.
 */
struct log_field_t *log_int(const int value);

/** 
 * log_int64 is used to add a 64 bit integer
 * value to the log entry.
 */
struct log_field_t *log_int64(const int64_t value);

/** 
 * log_double is used to add a double to the 
 * log entry.
 */
struct log_field_t *log_double(const double value);

/** 
 * log_string is used to add a string to the 
 * log entry.
 */
struct log_field_t *log_string(const char *value);

/**
 * log_output contains the location we're
 * going to write our log entries to
 */
FILE *log_output;

enum {
    LOG_OUT_STDERR,
    LOG_OUT_STDOUT,
};

/**
 * log_init initializes the logger and sets up
 * where the logger writes to.
 */
void log_init(FILE *out);

/**
 * reallog provides the functionality of the logger. Returns
 * the number os bytes written.
 */
int reallog(char *l, ...);

/**
 * log is the main entry point for adding data
 * to the logger to create log entries
 */
#define log(l, ...) ({ reallog(l, __VA_ARGS__, NULL); })

#endif /* end _LOG_H */
