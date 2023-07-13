#include "test_header.h"

Test(strrchr_tests, find_char_in_string)
{
    char string[] = "This is a sample string";
    char *ptr;

    ptr = strrchr(string, 's');
    cr_assert_neq(ptr, NULL, "Expected pointer to be non-NULL");
    cr_assert_str_eq(ptr, "string",
    "Expected pointer to point to \"string\" it points to \"%s\"", ptr);
}

Test(strrchr_tests, find_char_not_in_string)
{
    char string[] = "This is a sample string";
    char *ptr;

    ptr = strchr(string, 'x');
    cr_assert_eq(ptr, NULL, "Expected pointer to be NULL");
}

Test(strrchr_tests, find_null_char_in_string)
{
    char string[] = "This is a sample string";
    char *ptr;

    ptr = strchr(string, '\0');
    cr_assert_str_eq(ptr, "", "Expected pointer to point to empty string");
}
