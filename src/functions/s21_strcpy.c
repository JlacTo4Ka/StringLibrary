#include "../s21_string.h"

char *s21_strcpy(char *dest, const char *src) {
  char *tmp = s21_NULL;
  if (dest != s21_NULL && src != s21_NULL) {
    tmp = dest;
    while (*src != '\0') {
      *dest++ = *src++;
    }
    *dest = '\0';
  }

  return tmp;
}