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

struct _IO_FILE *slog_output;

enum {
    SLOG_OUT_STDERR,
    SLOG_OUT_STDOUT,
};

void slog_init(uint8_t out);
int reallog(char *l, ...);

#define slog(l, ...) ({ reallog(l, __VA_ARGS__, NULL); })

#endif // end _STRUCTURED_LOG_H 
