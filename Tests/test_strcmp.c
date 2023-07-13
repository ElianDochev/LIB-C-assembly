#include "test_header.h"

Test(_strcmp, basic)
{
  const char message[] = "Hello, World!";
  int length = strcmp(message, "Hello, World!");

  cr_assert_eq(length, 0, "Expected length: 0, but got: %d", length);
}

Test(_strcmp, empty_string)
{
  const char message[] = "";
  int length = strcmp(message, "");

  cr_assert_eq(length, 0, "Expected length: 0, but got: %d", length);
}

Test(_strcmp, different_string)
{
  const char message[] = "Hello, World!";
  int length = strcmp(message, "Hello , World!");

  cr_assert(length > 0, "Expected length: positive, but got: %d", length);
}

Test(_strcmp, different_string2)
{
  const char message[] = "Hello, World";
  int length = strcmp(message, "Hello, World!");

  cr_assert(length < 0, "Expected length: negative, but got: %d", length);
}
