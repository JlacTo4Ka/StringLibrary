#include "../s21_string.h"

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  char *dest_ptr = (char *)dest;
  const char *src_ptr = (const char *)src;
  if (dest != s21_NULL && src != s21_NULL) {
    for (s21_size_t i = 0; i < n; i++) {
      dest_ptr[i] = src_ptr[i];
    }
  }
  return dest;
}
