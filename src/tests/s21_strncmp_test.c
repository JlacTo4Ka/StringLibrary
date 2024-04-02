#include "s21_string_test.h"

START_TEST(test_strncmp_common) {
  const char str1[] = "Normal";
  const char str2[] = "Normal";
  s21_size_t n = 5;
  int result = s21_strncmp(str1, str2, n);
  int expected_result = strncmp(str1, str2, n);
  result = result > 0 ? 1 : result == 0 ? 0 : -1;
  expected_result = expected_result > 0 ? 1 : expected_result == 0 ? 0 : -1;
  ck_assert_int_eq(result, expected_result);
}
END_TEST

START_TEST(test_strncmp_empty_src) {
  const char str1[] = "";
  const char str2[] = "Hello";
  s21_size_t n = 1;
  int result = s21_strncmp(str1, str2, n);
  int expected_result = strncmp(str1, str2, n);
  result = result > 0 ? 1 : result == 0 ? 0 : -1;
  expected_result = expected_result > 0 ? 1 : expected_result == 0 ? 0 : -1;
  ck_assert_int_eq(result, expected_result);
}
END_TEST

START_TEST(test_strncmp_empty_dest) {
  const char str1[] = "Hello";
  const char str2[] = "";
  s21_size_t n = 1;
  int result = s21_strncmp(str1, str2, n);
  int expected_result = strncmp(str1, str2, n);
  result = result > 0 ? 1 : result == 0 ? 0 : -1;
  expected_result = expected_result > 0 ? 1 : expected_result == 0 ? 0 : -1;
  ck_assert_int_eq(result, expected_result);
}
END_TEST

START_TEST(test_strncmp_nocommon) {
  const char str1[] = "Hello";
  const char str2[] = "Hellp";
  s21_size_t n = 4;
  int result = s21_strncmp(str1, str2, n);
  int expected_result = strncmp(str1, str2, n);
  result = result > 0 ? 1 : result == 0 ? 0 : -1;
  expected_result = expected_result > 0 ? 1 : expected_result == 0 ? 0 : -1;
  ck_assert_int_eq(result, expected_result);
}
END_TEST

START_TEST(test_strncmp_zero_n) {
  const char str1[] = "Hello";
  const char str2[] = "Hellp";
  s21_size_t n = 0;
  int result = s21_strncmp(str1, str2, n);
  int expected_result = strncmp(str1, str2, n);
  result = result > 0 ? 1 : result == 0 ? 0 : -1;
  expected_result = expected_result > 0 ? 1 : expected_result == 0 ? 0 : -1;
  ck_assert_int_eq(result, expected_result);
}
END_TEST

void add_s21_strncmp_test(Suite *s) {
  TCase *t_case = tcase_create("S21_strncmp");
  tcase_add_test(t_case, test_strncmp_common);
  tcase_add_test(t_case, test_strncmp_empty_src);
  tcase_add_test(t_case, test_strncmp_empty_dest);
  tcase_add_test(t_case, test_strncmp_nocommon);
  tcase_add_test(t_case, test_strncmp_zero_n);

  suite_add_tcase(s, t_case);
}