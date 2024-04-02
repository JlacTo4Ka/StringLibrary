#include "../s21_string.h"

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  char *flag = s21_NULL;
  if (dest != s21_NULL && src != s21_NULL) {
    flag = dest;
    size_t number = 0;
    while (number < n) {
      if (*src != '\0')
        *dest++ = *src++;
      else
        *dest++ = '\0';
      number++;
    }
  }

  return flag;
}
