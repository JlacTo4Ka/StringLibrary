#include "s21_string_test.h"

START_TEST(test_s21_strpbrk_normal_case) {
  const char *str1 = "Hello, World!";
  const char *str2 = "abcde";
  char *result_s21 = s21_strpbrk(str1, str2);
  char *result_std = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strpbrk_first_char) {
  const char *str1 = "Hello, World!";
  const char *str2 = "H";
  char *result_s21 = s21_strpbrk(str1, str2);
  char *result_std = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strpbrk_last_char) {
  const char *str1 = "Hello, World!";
  const char *str2 = "!";
  char *result_s21 = s21_strpbrk(str1, str2);
  char *result_std = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strpbrk_no_char) {
  const char *str1 = "Hello, World!";
  const char *str2 = "xyz";
  char *result_s21 = s21_strpbrk(str1, str2);
  char *result_std = strpbrk(str1, str2);
  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strpbrk_null_pointer_str1) {
  char *str1 = NULL;
  char *str2 = "abc";
  char *result_s21 = s21_strpbrk(str1, str2);
  ck_assert_ptr_null(result_s21);
}
END_TEST

START_TEST(test_s21_strpbrk_null_pointer_str2) {
  char *str1 = "Hello, World!";
  char *str2 = NULL;
  char *result_s21 = s21_strpbrk(str1, str2);
  ck_assert_ptr_null(result_s21);
}
END_TEST

void add_s21_strpbrk_test(Suite *s) {
  TCase *tc = tcase_create("S21_strpbrk");
  tcase_add_test(tc, test_s21_strpbrk_normal_case);
  tcase_add_test(tc, test_s21_strpbrk_first_char);
  tcase_add_test(tc, test_s21_strpbrk_last_char);
  tcase_add_test(tc, test_s21_strpbrk_no_char);
  tcase_add_test(tc, test_s21_strpbrk_null_pointer_str1);
  tcase_add_test(tc, test_s21_strpbrk_null_pointer_str2);
  suite_add_tcase(s, tc);
}