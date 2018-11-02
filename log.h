#ifndef _LOG_H
#define _LOG_H

#include <stdio.h>
#include <stdarg.h>

#define LOG_TRACE "trace"
#define LOG_DEBUG "debug"
#define LOG_INFO  "info"
#define LOG_WARN  "warn"
#define LOG_ERROR "error"
#define LOG_FATAL "fatal"

int reallog(char *l, ...);

#define log(l, ...) ({ reallog(l, __VA_ARGS__, NULL); })

#endif // end _LOG_H
