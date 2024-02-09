#include "string21.h"

size_t s21_strspn(const char *str1, const char *str2) {
  size_t count = 0;

  for (str1; *str1 != '\0'; str1++) {
    for (str2; *str2 != '\0'; str2++)
      if (*str1 == *str2) break;
    if (*str2 == '\0')
      return count;
    else
      count++;
  }
  return count;
}