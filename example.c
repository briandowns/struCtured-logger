#include <stdio.h>

#include "src/slog.h"

int main(int argc, char **argv) {
    slog_init(stdout);
    slog(SLOG_INFO, "msg", "records added successfully", "count", "2");
    slog(SLOG_INFO, "msg", "records added successfully", "count", slog_field_int(2)); 
}
