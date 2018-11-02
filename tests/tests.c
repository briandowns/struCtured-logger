#include "unity/unity.h"

#include "../src/slog.h"

void test_slog_init(void) {
    slog_init(SLOG_OUT_STDERR);
    TEST_ASSERT_NOT_NULL(slog_output);
}

void test_log_two_fields(void) {}
void test_log_three_fields(void) {}

int main(int argc, char **argv) {
    UNITY_BEGIN();

    RUN_TEST(test_slog_init);
    RUN_TEST(test_log_two_fields);
    RUN_TEST(test_log_three_fields);

    return UNITY_END();
}