#include "../s21_string.h"

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int result = -1;
  if (str1 != s21_NULL && str2 != s21_NULL) {
    result = 0;
    while (n > 0 && !result) {
      if (*str1 != *str2 && *str1 > *str2) {
        result = *str1 - *str2;
      }
      if (*str1 != *str2 && *str1 < *str2) {
        result = *str1 - *str2;
      }
      str1++;
      str2++;
      n--;
    }
  }

  return result;
}