#include "../s21_string.h"

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  char *str1_tmp = (char *)str1;
  char *str2_tmp = (char *)str2;
  int result = 0;
  for (s21_size_t i = 0; i < n && !result; i++) {
    int ascii_code_str1 = (int)(char)str1_tmp[i];
    int ascii_code_str2 = (int)(char)str2_tmp[i];
    if (ascii_code_str1 > ascii_code_str2) {
      result = ascii_code_str1 - ascii_code_str2;
    }
    if (ascii_code_str1 < ascii_code_str2) {
      result = ascii_code_str1 - ascii_code_str2;
    }
  }

  return result;
}