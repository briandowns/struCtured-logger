#include "log.h"

int main(int argc, char **argv) {
    log(LOG_INFO, "count", "2", "request", "outbound");
}