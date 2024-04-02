#include "s21_string_test.h"

START_TEST(s21_to_upper_1) {
  char str[] = "Hello, World!";
  char *result_s21 = s21_to_upper(str);
  ck_assert_str_eq("HELLO, WORLD!", result_s21);
  free(result_s21);
}
END_TEST

START_TEST(s21_to_upper_2) {
  char str[] = "HELLO, WORLD!";
  char *result_s21 = s21_to_upper(str);
  ck_assert_str_eq("HELLO, WORLD!", result_s21);
  free(result_s21);
}
END_TEST

START_TEST(s21_to_upper_3) {
  char *str = s21_NULL;
  char *result_s21 = s21_to_upper(str);
  ck_assert_ptr_eq(result_s21, s21_NULL);
  free(result_s21);
}
END_TEST

void add_s21_to_upper_test(Suite *s) {
  TCase *tc = tcase_create("S21_to_upper");
  tcase_add_test(tc, s21_to_upper_1);
  tcase_add_test(tc, s21_to_upper_2);
  tcase_add_test(tc, s21_to_upper_3);
  suite_add_tcase(s, tc);
}