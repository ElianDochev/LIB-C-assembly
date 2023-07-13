#include "test_header.h"

Test(_strstr, basic)
{
    const char message[] = "Hello, World!";
    char *result = strstr(message, "Hello, World!");

    cr_assert_eq(result, message, "Expected result: %p, but got: %p", message, result);
}

Test(_strstr, empty_string)
{
    const char message[] = "";
    char *result = strstr(message, "");

    cr_assert_eq(result, message, "Expected result: %p, but got: %p", message, result);
}

Test(_strstr, needle)
{
    const char message[] = "Hello, World!";
    char *result = strstr(message, "World!");

    cr_assert_eq(result, message + 7, "Expected result: %p, but got: %p", message + 7, result);
}

Test(_strstr, needle_not_found)
{
    const char message[] = "Hello, World!";
    char *result = strstr(message, "qwerty");

    cr_assert_eq(result, NULL, "Expected result: %p, but got: %p", NULL, result);
}
