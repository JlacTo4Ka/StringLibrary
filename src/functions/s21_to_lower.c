#include "../s21_string.h"

void *s21_to_lower(const char *str) {
  char *new_str = s21_NULL;
  if (str) {
    new_str = (char *)malloc((s21_strlen(str) + 1) * sizeof(char));
    if (new_str) {
      int i = 0;
      while (str[i] != '\0') {
        new_str[i] = tolower(str[i]);
        i++;
      }
      new_str[i] = '\0';
    }
  }
  return new_str;
}