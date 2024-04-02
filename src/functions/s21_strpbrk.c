#include "../s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;
  if (str1 != s21_NULL && str2 != s21_NULL) {
    while (*str1 != '\0') {
      const char *current = str2;
      while (*current != '\0' && !result) {
        if (*str1 == *current) {
          result = (char *)str1;
        } else
          current++;
      }
      str1++;
    }
  }

  return result;
}
