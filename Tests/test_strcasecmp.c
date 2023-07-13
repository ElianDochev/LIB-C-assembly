#include "test_header.h"

Test(_strcasecmp, basic)
{
    const char message[] = "Hello, World!";
    int result = strcasecmp(message, "Hello, World!");

    cr_assert_eq(result, 0, "Expected result: %d, but got: %d", 0, result);
}

Test(_strcasecmp, empty_string)
{
    const char message[] = "";
    int result = strcasecmp(message, "");

    cr_assert_eq(result, 0, "Expected result: %d, but got: %d", 0, result);
}

Test(_strcasecmp, different_string)
{
    const char message[] = "qwerty watertf";
    int result = strcasecmp(message, "Hello , World!");

    cr_assert_eq(result, 9, "Expected result: %d, but got: %d", 0, result);
}

Test(_strcasecmp, case_insensitive)
{
    const char message[] = "Hello, World!";
    int result = strcasecmp(message, "hello, world!");

    cr_assert_eq(result, 0, "Expected result: %d, but got: %d", 0, result);
}