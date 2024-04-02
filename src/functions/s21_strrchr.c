#include "../s21_string.h"

char *s21_strrchr(const char *str, int c) {
  const char *last_ccurrence = s21_NULL;
  if (str != s21_NULL) {
    while (*str != '\0') {
      if (*str == (char)c) {
        last_ccurrence = str;
      }
      str++;
    }
  }
  return (char *)last_ccurrence;
}