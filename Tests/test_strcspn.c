#include "test_header.h"

Test(strcspn, should_return_correct_length)
{
    char *string = "Hello, World!";
    char *reject = ",";
    size_t result = strcspn(string, reject);

    cr_assert_eq(result, 5, "Expected result: %lu, but got: %lu", 5, result);
}

Test(strcspn, should_return_full_string_length_when_no_match)
{
    char *string = "Hello, World!";
    char *reject = "Moon";
    size_t result = strcspn(string, reject);

    cr_assert_eq(result, 4,
    "Expected result: %lu, but got: %lu", 4, result);
}

Test(strcspn, should_return_0_when_first_character_matches)
{
    char *string = "Hello, World!";
    char *reject = "H";
    size_t result = strcspn(string, reject);

    cr_assert_eq(result, 0, "Expected result: %lu, but got: %lu", 0, result);
}

Test(strcspn, should_return_0_when_empty_string)
{
    char *string = "";
    char *reject = "Moon";
    size_t result = strcspn(string, reject);

    cr_assert_eq(result, 0, "Expected result: %lu, but got: %lu", 0, result);
}

Test(strcspn, should_return_full_string_length_when_empty_reject)
{
    char *string = "Hello, World!";
    char *reject = "";
    size_t result = strcspn(string, reject);

    cr_assert_eq(result, strlen(string),
    "Expected result: %lu, but got: %lu", strlen(string), result);
}
