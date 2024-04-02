#include "s21_string_test.h"

START_TEST(test_s21_strtok_single_token) {
  char str[] = "Hello,World!";
  const char *delim = ",";
  char *result_s21 = s21_strtok(str, delim);
  char *result_std = strtok(str, delim);
  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strtok_no_match) {
  char str[] = "Hello,World!";
  const char *delim = "?";
  char *result_s21 = s21_strtok(str, delim);
  char *result_std = strtok(str, delim);
  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strtok_no_match_1) {
  char str[] = "\0";
  const char *delim = "";
  char *result_s21 = s21_strtok(str, delim);
  char *result_std = strtok(str, delim);
  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strtok_empty_string) {
  char str[] = "";
  const char *delim = ",";
  char *result_s21 = s21_strtok(str, delim);
  char *result_std = strtok(str, delim);
  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strtok_null_string) {
  char str[] = "";
  const char *delim = "\0";
  char *result_s21 = s21_strtok(str, delim);
  char *result_std = strtok(str, delim);
  ck_assert_ptr_eq(result_s21, result_std);
}
END_TEST

void add_s21_strtok_test(Suite *s) {
  TCase *tc = tcase_create("S21_strtok");
  tcase_add_test(tc, test_s21_strtok_single_token);
  tcase_add_test(tc, test_s21_strtok_no_match);
  tcase_add_test(tc, test_s21_strtok_no_match_1);
  tcase_add_test(tc, test_s21_strtok_empty_string);
  tcase_add_test(tc, test_s21_strtok_null_string);

  suite_add_tcase(s, tc);
}
