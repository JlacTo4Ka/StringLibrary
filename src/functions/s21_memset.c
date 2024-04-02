#include "../s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  char *str_tmp = (char *)str;
  char *result = s21_NULL;
  if (n == 1) {
    *str_tmp = (char)c;
    result = (char *)str;
  } else if (n > 1) {
    for (s21_size_t i = 0; i < n; i++) {
      str_tmp[i] = (char)c;
    }
    result = (char *)str;
  }

  return (void *)result;
}
