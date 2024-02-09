#include "string21.h"

char *s21_strncat(char *dest, const char *src, size_t n) {
  s21_size_t count = 0;
  if (!dest || !src) {
    return NULL;
  }
  for (s21_size_t i = s21_strlen(dest); count < n;) {
    dest[i] = src[count];
    count++;
    i++;
  }
  return dest;
}