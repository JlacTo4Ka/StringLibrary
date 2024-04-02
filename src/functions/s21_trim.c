#include "../s21_string.h"

void *s21_trim(const char *str, const char *trim_chars) {
  char *new_str = s21_NULL;
  if (str && trim_chars) {
    char *start = (char *)str;
    char *end = (char *)str + s21_strlen(str);
    while (*start && s21_strchr(trim_chars, *start)) {
      start++;
    }
    while (end != start && s21_strchr(trim_chars, *(end - 1))) {
      end--;
    }
    new_str = (char *)malloc((end - start + 1) * sizeof(char));
    if (new_str) {
      s21_strncpy(new_str, start, end - start);
      new_str[end - start] = '\0';
    }
  }
  return new_str;
}