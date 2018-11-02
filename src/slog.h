#ifndef _STRUCTURED_LOG_H
#define _STRUCTURED_LOG_H

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
 * slog_output contains the location we're
 * going to write our log entries to
 */
struct _IO_FILE *slog_output;

enum {
    SLOG_OUT_STDERR,
    SLOG_OUT_STDOUT,
};

/**
 * slog_init initializes the logger and sets up
 * where the logger writes to.
 */
void slog_init(uint8_t out);

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

#endif // end _STRUCTURED_LOG_H 
