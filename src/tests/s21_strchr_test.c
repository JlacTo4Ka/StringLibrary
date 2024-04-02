#include "s21_string_test.h"

START_TEST(test_s21_strchr_normal_case) {
  const char *str = "Hello, World!";
  int c = 'o';
  char *result_s21 = s21_strchr(str, c);
  char *result_std = strchr(str, c);
  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strchr_not_found) {
  const char *str = "Hello, World!";
  int c = 'z';
  char *result_s21 = s21_strchr(str, c);
  char *result_std = strchr(str, c);
  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strchr_empty_string) {
  const char *str = "";
  int c = 'o';
  char *result_s21 = s21_strchr(str, c);
  char *result_std = strchr(str, c);
  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST
START_TEST(test_s21_strchr_null_character) {
  const char *str = "Hello, World!";
  int c = '\0';
  char *result_s21 = s21_strchr(str, c);
  char *result_std = strchr(str, c);
  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

void add_s21_strchr_test(Suite *s) {
  TCase *tc = tcase_create("S21_Strchr");
  tcase_add_test(tc, test_s21_strchr_normal_case);
  tcase_add_test(tc, test_s21_strchr_not_found);
  tcase_add_test(tc, test_s21_strchr_empty_string);
  tcase_add_test(tc, test_s21_strchr_null_character);

  suite_add_tcase(s, tc);
}
