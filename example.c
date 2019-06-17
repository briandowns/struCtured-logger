#include <stdio.h>

#include "log.h"

int main(int argc, char **argv) {
    slog_init(stdout);
    slog(LOG_INFO, "msg", log_string("records added successfully"), "count", log_int(2));
    slog(LOG_INFO, "msg", log_string("records added successfully"), "count", log_int64(9223372036854775807));
    slog(LOG_INFO, "msg", log_string("record added successfully"), "name", log_string("Brian"), "elapsed", slog_double(5.76));
}
