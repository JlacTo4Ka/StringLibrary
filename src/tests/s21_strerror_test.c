#include "s21_string_test.h"

START_TEST(strerror_all) {
  for (int i = 0; i < 150; i++) {
    ck_assert_str_eq(strerror(i), s21_strerror(i));
  }
}
END_TEST

START_TEST(test_s21_strerror_negative_error) {
  int errnum = -1;
  char *result_s21 = s21_strerror(errnum);
  char *result_std = strerror(errnum);
  ck_assert_str_eq(result_s21, result_std);
}
END_TEST

void add_s21_strerror_test(Suite *s) {
  TCase *tc = tcase_create("S21_strerror");
  tcase_add_test(tc, strerror_all);
  tcase_add_test(tc, test_s21_strerror_negative_error);

  suite_add_tcase(s, tc);
}