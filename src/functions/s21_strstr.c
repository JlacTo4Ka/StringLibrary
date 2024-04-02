#include "../s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *res = s21_NULL;
  char *tmp = (char *)haystack;
  int needle_length = s21_strlen(needle);
  int flag = 0;
  while (*tmp != '\0' && flag == 0) {
    if (s21_strncmp(tmp, needle, needle_length) == 0) {
      flag = 1;
      res = tmp;
    } else {
      tmp++;
    }
  }
  return res;
}