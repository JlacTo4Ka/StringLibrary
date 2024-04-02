#include "s21_string_test.h"

START_TEST(s21_insert_1) {
  char str[] = "Hello, world!";
  s21_size_t len = strlen(str);
  char *result_s21 = s21_insert(str, "!!", 0);
  ck_assert_str_eq("!!Hello, world!", result_s21);
  ck_assert_int_eq(len + 2, strlen(result_s21));
  free(result_s21);
}
END_TEST

START_TEST(s21_insert_2) {
  char str[] = "Hello, world!";
  s21_size_t len = strlen(str);
  char *result_s21 = s21_insert(str, "!!", 1);
  ck_assert_str_eq("H!!ello, world!", result_s21);
  ck_assert_int_eq(len + 2, strlen(result_s21));
  free(result_s21);
}
END_TEST

START_TEST(s21_insert_3) {
  char str[] = "Hello, world!";
  s21_size_t len = strlen(str);
  char *result_s21 = s21_insert(str, "!!", 13);
  ck_assert_str_eq("Hello, world!!!", result_s21);
  ck_assert_int_eq(len + 2, strlen(result_s21));
  free(result_s21);
}
END_TEST

START_TEST(s21_insert_4) {
  char *str = s21_NULL;
  char *result_s21 = s21_insert(str, "!", 0);
  ck_assert_ptr_eq(result_s21, s21_NULL);
  free(result_s21);
}
END_TEST

START_TEST(s21_insert_5) {
  char str[] = "Hello, world!";
  char *result_s21 = s21_insert(str, s21_NULL, 1);
  ck_assert_ptr_eq(result_s21, s21_NULL);
  free(result_s21);
}
END_TEST

START_TEST(s21_insert_6) {
  char str[] = "Hello, world!";
  char *result_s21 = s21_insert(str, "!", 100);
  ck_assert_ptr_eq(result_s21, s21_NULL);
  free(result_s21);
}
END_TEST

START_TEST(s21_insert_7) {
  char str[] = "Hello, world!";
  char *result_s21 = s21_insert(str, "!", -1);
  ck_assert_ptr_eq(result_s21, s21_NULL);
  free(result_s21);
}
END_TEST

void add_s21_insert_test(Suite *s) {
  TCase *tc = tcase_create("S21_insert");
  tcase_add_test(tc, s21_insert_1);
  tcase_add_test(tc, s21_insert_2);
  tcase_add_test(tc, s21_insert_3);
  tcase_add_test(tc, s21_insert_4);
  tcase_add_test(tc, s21_insert_5);
  tcase_add_test(tc, s21_insert_6);
  tcase_add_test(tc, s21_insert_7);
  suite_add_tcase(s, tc);
}