#include "s21_string_test.h"

START_TEST(test_s21_strcspn_normal_case) {
  const char *str1 = "Hello, World!";
  const char *str2 = "aeou";
  size_t result_s21 = s21_strcspn(str1, str2);
  size_t result_std = strcspn(str1, str2);
  ck_assert_int_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strcspn_empty_string) {
  const char *str1 = "";
  const char *str2 = "aeou";
  size_t result_s21 = s21_strcspn(str1, str2);
  size_t result_std = strcspn(str1, str2);
  ck_assert_int_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strcspn_no_match) {
  const char *str1 = "Hello, World!";
  const char *str2 = "xyz";
  size_t result_s21 = s21_strcspn(str1, str2);
  size_t result_std = strcspn(str1, str2);
  ck_assert_int_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strcspn_match_at_beginning) {
  const char *str1 = "Hello, World!";
  const char *str2 = "H";
  size_t result_s21 = s21_strcspn(str1, str2);
  size_t result_std = strcspn(str1, str2);
  ck_assert_int_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strcspn_match_at_end) {
  const char *str1 = "Hello, World!";
  const char *str2 = "!";
  size_t result_s21 = s21_strcspn(str1, str2);
  size_t result_std = strcspn(str1, str2);
  ck_assert_int_eq(result_s21, result_std);
}
END_TEST

void add_s21_strcspn_test(Suite *s) {
  TCase *tc = tcase_create("S21_Strcspn");
  tcase_add_test(tc, test_s21_strcspn_normal_case);
  tcase_add_test(tc, test_s21_strcspn_empty_string);
  tcase_add_test(tc, test_s21_strcspn_no_match);
  tcase_add_test(tc, test_s21_strcspn_match_at_beginning);
  tcase_add_test(tc, test_s21_strcspn_match_at_end);
  suite_add_tcase(s, tc);
}
