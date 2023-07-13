#include "test_header.h"

Test(strpbrk, should_return_correct_pointer)
{
    char *string = "Hello, World!";
    char *accept = "World";
    char *result = strpbrk(string, accept);

    cr_assert_str_eq(result, "llo, World!", "Expected result:"
    "\"World!\", but got: %s", result);
}

Test(strpbrk, should_return_null_when_no_match)
{
    char *string = "Hello, World!";
    char *accept = "Mpbn";
    char *result = strpbrk(string, accept);

    cr_assert_null(result, "Expected result: %p, but got: %p", NULL, result);
}

Test(strpbrk, should_return_null_when_empty_string)
{
    char *string = "";
    char *accept = "Moon";
    char *result = strpbrk(string, accept);

    cr_assert_null(result, "Expected result: %p, but got: %p", NULL, result);
}

Test(strpbrk, should_return_null_when_empty_accept)
{
    char *string = "Hello, World!";
    char *accept = "";
    char *result = strpbrk(string, accept);

    cr_assert_null(result, "Expected result: %p, but got: %p", NULL, result);
}
