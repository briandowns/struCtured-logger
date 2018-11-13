#include <stdio.h>

#include "unity/unity.h"

#include "../src/slog.h"

void test_slog_init(void) {
    slog_init(stderr);
    TEST_ASSERT_NOT_NULL(slog_output);
}

void test_log_two_fields(void) {
    slog_init(stdout);
    int wc = slog(SLOG_INFO, "msg", slog_string("records added successfully"), "count", slog_int(2));
    TEST_ASSERT_EQUAL_INT(94, wc);
}

void test_log_three_fields(void) {
    slog_init(stdout);
    int wc = slog(SLOG_DEBUG, "field1", slog_string("value1"), "field2", slog_double(3.14), "field3", slog_int64(89));
    TEST_ASSERT_EQUAL_INT(110, wc);
}

void test_log_odd_count_fields(void) {
    slog_init(stdout);
    int wc = slog(SLOG_DEBUG, "field1", slog_string("value1"), slog_double(3.14), "field3", slog_int64(89));
    TEST_ASSERT_EQUAL_INT(66, wc);
}

int main(int argc, char **argv) {
    UNITY_BEGIN();

    RUN_TEST(test_slog_init);
    RUN_TEST(test_log_two_fields);
    RUN_TEST(test_log_three_fields);
    RUN_TEST(test_log_odd_count_fields);

    return UNITY_END();
}
