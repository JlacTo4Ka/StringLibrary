#include "../s21_string.h"

size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t count = 0;
  if (str1 != s21_NULL && str2 != s21_NULL) {
    const char *string;
    int flag = 0;
    for (string = str1; *string != '\0' && !flag; ++string) {
      const char *pattern;
      for (pattern = str2; *pattern != '\0' && !flag; ++pattern) {
        if (*string == *pattern) {
          flag = 1;
        }
      }
      if (!flag) ++count;
    }
  }
  return count;
}