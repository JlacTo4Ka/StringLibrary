#include "../s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *str_tmp = (unsigned char *)str;
  int check = 0;
  while (n-- && !check) {
    if (*str_tmp == (unsigned char)c) {
      check = 1;
    } else
      str_tmp++;
  }
  if (check != 1) {
    str_tmp = s21_NULL;
  }

  return str_tmp;
}
