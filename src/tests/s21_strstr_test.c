#include "s21_string_test.h"

START_TEST(test_s21_strstr_match) {
  const char *haystack = "Hello, World!";
  const char *needle = "World";
  char *result_s21 = s21_strstr(haystack, needle);
  char *result_std = strstr(haystack, needle);
  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strstr_no_match) {
  const char *haystack = "Hello, World!";
  const char *needle = "Foo";
  char *result_s21 = s21_strstr(haystack, needle);
  char *result_std = strstr(haystack, needle);
  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strstr_empty_haystack) {
  const char *haystack = "";
  const char *needle = "Hello";
  char *result_s21 = s21_strstr(haystack, needle);
  char *result_std = strstr(haystack, needle);
  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strstr_empty_needle) {
  const char *haystack = "Hello, World!";
  const char *needle = "";
  char *result_s21 = s21_strstr(haystack, needle);
  char *result_std = strstr(haystack, needle);
  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strstr_null_haystack) {
  const char *haystack = "\0";
  const char *needle = "Hello";
  char *result_s21 = s21_strstr(haystack, needle);
  char *result_std = strstr(haystack, needle);
  ck_assert_pstr_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strstr_null_needle) {
  const char *haystack = "Hello, World!";
  const char *needle = "\0";
  char *result_s21 = s21_strstr(haystack, needle);
  char *result_std = strstr(haystack, needle);
  ck_assert_pstr_eq(result_s21, result_std);
}
END_TEST

void add_s21_strstr_test(Suite *s) {
  TCase *tc = tcase_create("S21_strstr");
  tcase_add_test(tc, test_s21_strstr_match);
  tcase_add_test(tc, test_s21_strstr_no_match);
  tcase_add_test(tc, test_s21_strstr_empty_haystack);
  tcase_add_test(tc, test_s21_strstr_empty_needle);
  tcase_add_test(tc, test_s21_strstr_null_haystack);
  tcase_add_test(tc, test_s21_strstr_null_needle);

  suite_add_tcase(s, tc);
}