#include "s21_string_test.h"

START_TEST(s21_trim_1) {
  char str[] = "Hello, world!";
  s21_size_t len = strlen(str);
  char *result_s21 = s21_trim(str, "H");
  ck_assert_str_eq("ello, world!", result_s21);
  ck_assert_int_eq(len - 1, strlen(result_s21));
  free(result_s21);
}
END_TEST

START_TEST(s21_trim_2) {
  char str[] = "Hello, world!";
  s21_size_t len = strlen(str);
  char *result_s21 = s21_trim(str, "l");
  ck_assert_str_eq("Hello, world!", result_s21);
  ck_assert_int_eq(len, strlen(result_s21));
  free(result_s21);
}
END_TEST

START_TEST(s21_trim_3) {
  char str[] = "Hello, world!";
  s21_size_t len = strlen(str);
  char *result_s21 = s21_trim(str, "!");
  ck_assert_str_eq("Hello, world", result_s21);
  ck_assert_int_eq(len - 1, strlen(result_s21));
  free(result_s21);
}
END_TEST

START_TEST(s21_trim_4) {
  char *str = s21_NULL;
  char *result_s21 = s21_trim(str, "");
  ck_assert_ptr_eq(result_s21, s21_NULL);
  free(result_s21);
}
END_TEST

START_TEST(s21_trim_5) {
  char str[] = "Hello, world!";
  s21_size_t len = strlen(str);
  char *result_s21 = s21_trim(str, "Hed!");
  ck_assert_str_eq("llo, worl", result_s21);
  ck_assert_int_eq(len - 4, strlen(result_s21));
  free(result_s21);
}
END_TEST

START_TEST(s21_trim_6) {
  char str[] = "Hello, world!";
  char *result_s21 = s21_trim(str, s21_NULL);
  ck_assert_ptr_eq(result_s21, s21_NULL);
  free(result_s21);
}
END_TEST

void add_s21_trim_test(Suite *s) {
  TCase *tc = tcase_create("S21_trim");
  tcase_add_test(tc, s21_trim_1);
  tcase_add_test(tc, s21_trim_2);
  tcase_add_test(tc, s21_trim_3);
  tcase_add_test(tc, s21_trim_4);
  tcase_add_test(tc, s21_trim_5);
  tcase_add_test(tc, s21_trim_6);
  suite_add_tcase(s, tc);
}