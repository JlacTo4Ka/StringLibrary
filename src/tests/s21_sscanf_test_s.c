#include "s21_string_test.h"

START_TEST(test_s21_sscanf_normal_case) {
  int i_std, j_std;
  float x_std, y_std;
  char str1_std[10], str2_std[4];
  wchar_t warr_std[2];

  int i_s21, j_s21;
  float x_s21, y_s21;
  char str1_s21[10], str2_s21[4];
  wchar_t warr_s21[2];
  setlocale(LC_ALL, "en_US.utf8");

  char input[] = "25 54.32E-1 Thompson 56789 0123 56ß水";
  /* parse as follows:
  %d: an integer
  %f: a floating-point value
  %9s: a string of at most 9 non-whitespace characters
  %2d: two-digit integer (digits 5 and 6)
  %f:  a floating-point value (digits 7, 8, 9)
  %*d: an integer which isn't stored anywhere
  ' ': all consecutive whitespace
  %3[0-9]: a string of at most 3 decimal digits (digits 5 and 6)
  %2lc: two wide characters, using multibyte to wide conversion  */
  int ret_std = sscanf(input, "%d%f%9s%2d%f%*d %2s %2lc", &i_std, &x_std,
                       str1_std, &j_std, &y_std, str2_std, warr_std);

  int ret_s21 = sscanf(input, "%d%f%9s%2d%f%*d %2s %2lc", &i_s21, &x_s21,
                       str1_s21, &j_s21, &y_s21, str2_s21, warr_s21);

  ck_assert_int_eq(i_std, i_s21);
  ck_assert_int_eq(j_std, j_s21);
  ck_assert_float_eq(x_std, x_s21);
  ck_assert_float_eq(y_std, y_s21);
  ck_assert_str_eq(str1_std, str1_s21);
  ck_assert_str_eq(str2_std, str2_s21);
  ck_assert_int_eq(ret_std, ret_s21);
  ck_assert_int_eq(warr_std[0], warr_s21[0]);
  ck_assert_int_eq(warr_std[1], warr_s21[1]);
}
END_TEST

START_TEST(sscanf_case_hello) {
  char format[] = "Hello%3ld";
  char str[] = "Hello+123";
  long int d1, d2;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(sscanf_empty_1) {
  char format[] = "%d";
  char str[] = "";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_2) {
  char format[] = "%d";
  char str[] = "     ";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_3) {
  char format[] = "%d";
  char str[] = "\n";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_6) {
  char format[] = "";
  char str[] = "\t\n\n   \n  \t";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_empty_7) {
  char format[] = "\t";
  char str[] = "\t\n\n   \n  \t";
  int p1, p2;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_case_0) {
  char format[] = "%d %d %d";
  char str[] = "0 0 0";
  int d1, d2;
  int q1, q2;
  int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(q1, q2);
  ck_assert_int_eq(z1, z2);
}
END_TEST

START_TEST(sscanf_case_s0) {
  char format[] = "%ls %ls";
  char str[] = "Ni Hao";
  wchar_t s1[20], s2[20], s3[20], s4[20];

  int16_t res1 = s21_sscanf(str, format, s1, s2);
  int16_t res2 = sscanf(str, format, s3, s4);
  ck_assert_ldouble_eq(res1, res2);
  ck_assert_int_eq(s1[0], s3[0]);
  ck_assert_int_eq(s2[1], s4[1]);
}
END_TEST

START_TEST(sscanf_case_s1) {
  char format[] = "%ls %ls";
  char str[] = "Ni Hao";
  char s1[20], s2[20], s3[20], s4[20];

  int16_t res1 = s21_sscanf(str, format, s1, s2);
  int16_t res2 = sscanf(str, format, s3, s4);
  ck_assert_ldouble_eq(res1, res2);
  ck_assert_pstr_eq(s1, s3);
  ck_assert_pstr_eq(s2, s4);
}
END_TEST

START_TEST(sscanf_case_s2) {
  char format[] = "%2s %4s %s %s %s";
  char str[] = "Hello, my name is Jinny";
  char s1[30], s2[30], s3[30], s4[30], s5[30], s6[30], s7[30], s8[30], s9[30],
      s10[30];

  int16_t res1 = s21_sscanf(str, format, &s1, &s3, &s5, &s7, &s9);
  int16_t res2 = sscanf(str, format, &s2, &s4, &s6, &s8, &s10);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(s1, s2);
  ck_assert_pstr_eq(s3, s4);
  ck_assert_pstr_eq(s5, s6);
  ck_assert_pstr_eq(s7, s8);
  ck_assert_pstr_eq(s9, s10);
}
END_TEST

START_TEST(sscanf_case_s3) {
  char format[] = "%2ls %2ls";
  char str[] = "Ni Hao Wo Jao";
  wchar_t s1[20], s2[20], s3[20], s4[20];

  int16_t res1 = s21_sscanf(str, format, s1, s2);
  int16_t res2 = sscanf(str, format, s3, s4);
  ck_assert_ldouble_eq(res1, res2);
  ck_assert_int_eq(s1[0], s3[0]);
  ck_assert_int_eq(s2[1], s4[1]);
}
END_TEST

void add_s21_sscanf_test_s(Suite *s) {
  TCase *tc = tcase_create("S21_sscanf");

  tcase_add_test(tc, test_s21_sscanf_normal_case);

  tcase_add_test(tc, sscanf_case_hello);

  tcase_add_test(tc, sscanf_empty_1);
  tcase_add_test(tc, sscanf_empty_2);
  tcase_add_test(tc, sscanf_empty_3);
  tcase_add_test(tc, sscanf_empty_6);
  tcase_add_test(tc, sscanf_empty_7);

  tcase_add_test(tc, sscanf_case_s0);
  tcase_add_test(tc, sscanf_case_s1);
  tcase_add_test(tc, sscanf_case_s2);
  tcase_add_test(tc, sscanf_case_s3);

  tcase_add_test(tc, sscanf_case_0);

  suite_add_tcase(s, tc);
}
