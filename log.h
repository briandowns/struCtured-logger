#ifndef _LOG_H
#define _LOG_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#define LOG_TRACE "trace"
#define LOG_DEBUG "debug"
#define LOG_INFO  "info"
#define LOG_WARN  "warn"
#define LOG_ERROR "error"
#define LOG_FATAL "fatal"

enum {
    LOG_OUT_STDERR,
    LOG_OUT_STDOUT,
} log_out_t;

void log_init(int out);
int reallog(char *l, ...);

#define log(l, ...) ({ reallog(l, __VA_ARGS__, NULL); })

#endif // end _LOG_H
