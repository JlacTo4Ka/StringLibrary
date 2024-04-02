#include "s21_string_test.h"

START_TEST(s21_to_lower_1) {
  char str[] = "Hello, World!";
  char *result_s21 = s21_to_lower(str);
  ck_assert_str_eq("hello, world!", result_s21);
  free(result_s21);
}
END_TEST

START_TEST(s21_to_lower_2) {
  char str[] = "HELLO, WORLD!";
  char *result_s21 = s21_to_lower(str);
  ck_assert_str_eq("hello, world!", result_s21);
  free(result_s21);
}
END_TEST

START_TEST(s21_to_lower_3) {
  char *str = s21_NULL;
  char *result_s21 = s21_to_lower(str);
  ck_assert_ptr_eq(result_s21, s21_NULL);
  free(result_s21);
}
END_TEST

START_TEST(s21_to_lower_4) {
  char str[] = "hello, world!";
  char *result_s21 = s21_to_lower(str);
  ck_assert_str_eq("hello, world!", result_s21);
  free(result_s21);
}
END_TEST

void add_s21_to_lower_test(Suite *s) {
  TCase *tc = tcase_create("S21_to_lower");
  tcase_add_test(tc, s21_to_lower_1);
  tcase_add_test(tc, s21_to_lower_2);
  tcase_add_test(tc, s21_to_lower_3);
  tcase_add_test(tc, s21_to_lower_4);
  suite_add_tcase(s, tc);
}