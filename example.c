#include "src/slog.h"

int main(int argc, char **argv) {
    slog_init(SLOG_OUT_STDOUT);
    slog(SLOG_INFO, "msg", "records added successfully", "count", "2");
}
