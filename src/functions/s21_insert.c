#include "../s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *new_str = s21_NULL;
  if (src && str && start_index <= s21_strlen(src)) {
    int src_len = s21_strlen(src);
    int str_len = s21_strlen(str);
    new_str = (char *)malloc((src_len + str_len + 1) * sizeof(char));
    if (new_str) {
      s21_strncpy(new_str, src, start_index);
      *(new_str + start_index) = '\0';
      s21_strncat(new_str, str, str_len);
      s21_strncat(new_str, src + start_index, src_len - start_index);
    }
  }
  return new_str;
}