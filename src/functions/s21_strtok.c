#include "../s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *last_token = s21_NULL;

  if (str != s21_NULL) {
    last_token = str;
  }
  if (*last_token == '\0') {
    last_token = s21_NULL;
    return s21_NULL;
  }
  char *token_start = last_token;
  while (*last_token != '\0' && s21_strchr(delim, *last_token) == s21_NULL) {
    last_token++;
  }
  if (*last_token == '\0') {
    last_token = s21_NULL;
  } else {
    *last_token = '\0';
    last_token++;
  }
  return token_start;
}