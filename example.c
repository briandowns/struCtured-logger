#include "log.h"

int main(int argc, char **argv) {
    log_init(LOG_OUT_STDOUT);
    log(LOG_INFO, "msg", "records added successfully", "count", "2");
}
