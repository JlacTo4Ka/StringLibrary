#include "../s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *result = s21_NULL;
  while (*str != '\0') {
    if (*str == (char)c) {
      result = (char *)str;
      break;
    }
    str++;
  }
  if (*str == '\0' && *str == c) {
    result = (char *)str;
  }
  return result;
}
