#include "s21_string_test.h"

START_TEST(test_s21_strrchr_normal_case) {
  const char *str = "Hello, world!";
  int c = 'o';
  char *result_s21 = s21_strrchr(str, c);
  char *result_std = strrchr(str, c);
  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strrchr_first_char) {
  const char *str = "Hello, world!";
  int c = 'H';
  char *result_s21 = s21_strrchr(str, c);
  char *result_std = strrchr(str, c);
  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strrchr_last_char) {
  const char *str = "Hello, world!";
  int c = '!';
  char *result_s21 = s21_strrchr(str, c);
  char *result_std = strrchr(str, c);
  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strrchr_null_pointer) {
  const char *str = NULL;
  int c = 'o';
  char *result_s21 = s21_strrchr(str, c);
  ck_assert_ptr_null(result_s21);
}
END_TEST

START_TEST(test_s21_strrchr_char) {
  const char *str = "Hello, world";
  int c = 'z';
  char *result_s21 = s21_strrchr(str, c);
  char *result_std = strrchr(str, c);
  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

void add_s21_strrchr_test(Suite *s) {
  TCase *tc = tcase_create("S21_strrchr");
  tcase_add_test(tc, test_s21_strrchr_normal_case);
  tcase_add_test(tc, test_s21_strrchr_first_char);
  tcase_add_test(tc, test_s21_strrchr_last_char);
  tcase_add_test(tc, test_s21_strrchr_null_pointer);
  tcase_add_test(tc, test_s21_strrchr_char);
  suite_add_tcase(s, tc);
}