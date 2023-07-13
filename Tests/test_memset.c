#include "test_header.h"

Test(memset_tests, fill_memory_with_zeroes)
{
    char string[] = "This is a sample string";
    char *ptr;

    ptr = memset(string, 0, sizeof(string));
    cr_assert_neq(ptr, NULL, "Expected pointer to be non-NULL");
    cr_assert_str_eq(ptr, "", "Expected pointer to point to empty string");
}

Test(memset_tests, fill_memory_with_non_zeroes)
{
    char string[] = "This is a sample string";
    char *ptr;

    ptr = memset(string, 'x', 23);
    cr_assert_neq(string, NULL, "Expected pointer to be non-NULL");
    cr_assert_str_eq(string, "xxxxxxxxxxxxxxxxxxxxxxx",
    "Expected pointer to point to empty string");
}
