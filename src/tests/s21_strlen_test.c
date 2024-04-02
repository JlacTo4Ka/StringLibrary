#include "s21_string_test.h"

START_TEST(test_s21_strlen_normal_case) {
  const char *str = "Hello, World!";
  size_t result_s21 = s21_strlen(str);
  size_t result_std = strlen(str);
  ck_assert_uint_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strlen_null) {
  const char *str = "Hello \0world!";
  size_t result_s21 = s21_strlen(str);
  size_t result_std = strlen(str);
  ck_assert_uint_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strlen_empty_string) {
  const char *str = "";
  size_t result_s21 = s21_strlen(str);
  size_t result_std = strlen(str);
  ck_assert_uint_eq(result_s21, result_std);
}
END_TEST

void add_s21_strlen_test(Suite *s) {
  TCase *tc = tcase_create("S21_strlen");
  tcase_add_test(tc, test_s21_strlen_normal_case);
  tcase_add_test(tc, test_s21_strlen_null);
  tcase_add_test(tc, test_s21_strlen_empty_string);
  suite_add_tcase(s, tc);
}
