#include "s21_string_test.h"

START_TEST(test_s21_strcpy_normal_case) {
  char dest_s21[20];
  char dest_std[20];
  const char *src = "Hello, World!";
  char *result_s21 = s21_strcpy(dest_s21, src);
  char *result_std = strcpy(dest_std, src);
  ck_assert_str_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strcpy_empty_source) {
  char dest_s21[20] = "Previous Content";
  char dest_std[20] = "Previous Content";
  const char *src = "";
  char *result_s21 = s21_strcpy(dest_s21, src);
  char *result_std = strcpy(dest_std, src);
  ck_assert_str_eq(result_s21, result_std);
}
END_TEST

START_TEST(test_s21_strcpy_null_pointer_str1) {
  char *str1 = NULL;
  char *str2 = "abc";
  char *result_s21 = s21_strcpy(str1, str2);
  ck_assert_ptr_null(result_s21);
}
END_TEST

START_TEST(test_s21_strcpy_null_pointer_str2) {
  char *str1 = "Hello, World!";
  char *str2 = NULL;
  char *result_s21 = s21_strcpy(str1, str2);
  ck_assert_ptr_null(result_s21);
}
END_TEST

void add_s21_strcpy_test(Suite *s) {
  TCase *tc = tcase_create("S21_Strcpy");
  tcase_add_test(tc, test_s21_strcpy_normal_case);
  tcase_add_test(tc, test_s21_strcpy_empty_source);
  tcase_add_test(tc, test_s21_strcpy_null_pointer_str1);
  tcase_add_test(tc, test_s21_strcpy_null_pointer_str2);
  suite_add_tcase(s, tc);
}
