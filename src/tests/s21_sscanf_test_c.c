#include "s21_string_test.h"

START_TEST(sscanf_case_c1) {
  char format[] = "%c";
  char str[] = "   Hello";
  char c1, c2;

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_case_c2) {
  char format[] = "%c";
  char str[] = "\t\n\n  1 \n  \t";
  char c1, c2;

  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_case_c3) {
  char format[] = "%c";
  char str[] = "\t\n\n   \n  \ta";
  char c1, c2;
  int16_t res1 = s21_sscanf(str, format, &c1);
  int16_t res2 = sscanf(str, format, &c2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(sscanf_case_c4) {
  char format[] = "%c%c%c";
  char str[] = "\t\n\n  123 \n  \t";
  char c11, c12, c13, c21, c22, c23;

  int16_t res1 = s21_sscanf(str, format, &c11, &c12, &c13);
  int16_t res2 = sscanf(str, format, &c21, &c22, &c23);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11, c21);
  ck_assert_int_eq(c12, c22);
  ck_assert_int_eq(c13, c23);
}
END_TEST

START_TEST(sscanf_case_c5) {
  char format[] = "%lc";
  char str[] = "Sie Sie";
  wchar_t c11[2], c12[2];

  int16_t res1 = s21_sscanf(str, format, &c11);
  int16_t res2 = sscanf(str, format, &c12);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(c11[0], c12[0]);
}
END_TEST

void add_s21_sscanf_test_c(Suite *s) {
  TCase *tc = tcase_create("S21_sscanf");

  tcase_add_test(tc, sscanf_case_c1);
  tcase_add_test(tc, sscanf_case_c2);
  tcase_add_test(tc, sscanf_case_c3);
  tcase_add_test(tc, sscanf_case_c4);
  tcase_add_test(tc, sscanf_case_c5);

  suite_add_tcase(s, tc);
}
