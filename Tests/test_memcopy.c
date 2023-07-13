#include "test_header.h"

Test(memcpy_tests, copy_memory)
{
    char string[] = "This is a sample string";
    char *ptr;

    ptr = memcpy(string, "new", 3);
    cr_assert_neq(ptr, NULL, "Expected pointer to be non-NULL");
    cr_assert_str_eq(string, "news is a sample string",
    "Expected pointer to point to \"news is a sample string\" it points to \"%s\"", ptr);
}

//imposible to test undefined behavior
// Test(memcpy_tests, copy_memory_with_overlap)
// {
//     char string[] = "This is a sample string";
//     char *ptr;

//     ptr = _memcpy(string + 5, string, sizeof(string));
//     cr_assert_neq(string, NULL, "Expected pointer to be non-NULL");
//     cr_assert_str_eq(string, "This This is a sample string",
//     "Expected pointer to point to \"This This is a sample string\"");
// }

Test(memcpy_test, zero_length)
{
    char string[] = "This is a sample string";
    char *ptr;

    ptr = memcpy(string, "new", 0);
    cr_assert_neq(ptr, NULL, "Expected pointer to be non-NULL");
    cr_assert_str_eq(string, "This is a sample string",
    "Expected pointer to point to \"This is a sample string\" it points to \"%s\"", ptr);
}
