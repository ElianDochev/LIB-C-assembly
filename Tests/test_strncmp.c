#include "test_header.h"

Test(_strncmp, basic)
{
    const char message[] = "Hello, World!";
    int result = strncmp(message, "Hello, World!", 13);

    cr_assert_eq(result, 0, "Expected result: %d, but got: %d", 0, result);
}

Test(_strncmp, empty_string)
{
    const char message[] = "";
    int result = strncmp(message, "", 1);

    cr_assert_eq(result, 0, "Expected result: %d, but got: %d", 0, result);
}

Test(_strncmp, different_string)
{
    const char message[] = "qwerty watertf";
    int result = strncmp(message, "Hello , World!", 14);

    cr_assert_eq(result, 41, "Expected result: %d, but got: %d", 0, result);
}

Test(_strncmp, substring)
{
    const char message[] = "Hello, World!";
    int result = strncmp(message, "Hello", 5);

    cr_assert_eq(result, 0, "Expected result: %d, but got: %d", 0, result);
}

Test(_strncmp, overflowing_len)
{
    const char message[] = "Hello, World!";
    int result = strncmp(message, "Hello, World!", 20);

    cr_assert_eq(result, 0, "Expected result: %d, but got: %d", 0, result);
}
