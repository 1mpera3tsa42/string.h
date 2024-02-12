#include "string21.h"

char *s21_strchr(const char *str, int c) {
  char *res = S21_NULL;
  int a = s21_strlen(str) + 1;
  for (int i = 0; i < x; i++) {
    if (str[i] == c) {
      res = (str + 1);
      break;
    }
  }
  return (char *)res;
}