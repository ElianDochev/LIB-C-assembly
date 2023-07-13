#include "test_header.h"

Test(_strlen, basic)
{
  const char message[] = "Hello, World!";
  int length = strlen(message);

  cr_assert_eq(length, 13, "Expected length: %d, but got: %d",
  13, length);
}

Test(_strlen, empty_string)
{
  const char message[] = "";
  int length = strlen(message);

  cr_assert_eq(length, 0, "Expected length: %d, but got: %d",
  0, length);
}
