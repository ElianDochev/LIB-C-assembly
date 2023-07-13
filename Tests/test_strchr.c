#include "test_header.h"

Test(strchr_tests, find_char_in_string)
{
    char string[] = "This is a sample string";
    char *ptr;

    ptr = strchr(string, 'a');
    cr_assert_neq(ptr, NULL, "Expected pointer to be non-NULL %p", ptr);
    cr_assert_str_eq(ptr, "a sample string",
    "Expected pointer to point to \"sample string\" it points to \"%s\"", ptr);
}

Test(strchr_tests, find_char_not_in_string)
{
    char string[] = "This is a sample string";
    char *ptr;

    ptr = strchr(string, 'x');
    cr_assert_eq(ptr, NULL, "Expected pointer to be NULL");
}

Test(strchr_tests, find_null_char_in_string)
{
    char string[] = "This is a sample string";
    char *ptr;

    ptr = strchr(string, '\0');
    cr_assert_str_eq(ptr, "", "Expected pointer to point to empty string");
}