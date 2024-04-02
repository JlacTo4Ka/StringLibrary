#include "../s21_string.h"

char *s21_strcat(char *str1, const char *str2) {
  int i = 0;
  int str1_length = s21_strlen(str1);

  while (str2[i] != '\0') {
    str1[str1_length + i] = str2[i];
    i++;
  }

  str1[str1_length + i] = '\0';
  return str1;
}
