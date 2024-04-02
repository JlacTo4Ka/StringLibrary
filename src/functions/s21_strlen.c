#include "../s21_string.h"

s21_size_t s21_strlen(const char *string) {
  int result = 0;
  while (string[result] != '\0') {
    result++;
  }

  return result;
}
