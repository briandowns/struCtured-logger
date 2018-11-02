#include "unity/unity.h"

#include "../src/slog.h"

void test_slog_init(void) {
    slog_init(SLOG_OUT_STDERR);
    TEST_ASSERT_NOT_NULL(slog_output);
}

void test_log_two_fields(void) {
    slog_init(SLOG_OUT_STDERR);
    int wc = slog(SLOG_INFO, "msg", "records added successfully", "count", "2");
    TEST_ASSERT_EQUAL_INT(79, wc);
}

void test_log_three_fields(void) {
    slog_init(SLOG_OUT_STDOUT);
    int wc = slog(SLOG_INFO, "field1", "value1", "field2", "value2", "field3", "value3");
    TEST_ASSERT_EQUAL_INT(88, wc);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();

    RUN_TEST(test_slog_init);
    RUN_TEST(test_log_two_fields);
    RUN_TEST(test_log_three_fields);

    return UNITY_END();
}