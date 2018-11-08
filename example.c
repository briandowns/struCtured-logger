#include <stdio.h>

#include "src/slog.h"

int main(int argc, char **argv) {
    slog_init(stdout);
    slog(SLOG_INFO, "msg", slog_string("records added successfully"), "count", slog_int(2));
    slog(SLOG_INFO, "msg", slog_string("records added successfully"), "count", slog_int64(9223372036854775807));
    slog(SLOG_INFO, "msg", slog_string("records added partially"), "count", slog_int64(3.14));
    slog(SLOG_INFO, "msg", slog_string("record added successfully"), "name", slog_string("Brian"), "elapsed", slog_double(5.76)); 
}
