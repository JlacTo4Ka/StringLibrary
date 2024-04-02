#include "../s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *tmp = s21_NULL;
  if (dest != s21_NULL && src != s21_NULL) {
    tmp = dest;
    while (*dest != '\0') {
      dest++;
    }
    while (n-- > 0) {
      *dest++ = *src++;
    }
    *dest = '\0';
  }
  return tmp;
}
