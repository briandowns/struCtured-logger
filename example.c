#include "src/log.h"

int main(int argc, char **argv) {
    slog_init(LOG_OUT_STDOUT);
    slog(LOG_INFO, "msg", "records added successfully", "count", "2");
}
