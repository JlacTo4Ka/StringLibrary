#include "s21_string_test.h"

START_TEST(sscanf_spec_p_1) {
  char format[] = "%p";
  char str[] = "0xAAAA";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_2) {
  char format[] = "%5p";
  char str[] = "0xAAA";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_3) {
  char format[] = "%p";
  char str[] = "0xFFFFFF";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_4) {
  char format[] = "%p";
  char str[] = "0x0000";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_5) {
  char format[] = "%p";
  char str[] = "0xA2361598";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_6) {
  char format[] = "%p";
  char str[] = "0x34567hjk";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_7) {
  char format[] = "%p";
  char str[] = "0x34567hjk678";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_8) {
  char format[] = "%p";
  char str[] = "0x34ABcd68";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_9) {
  char format[] = "%p";
  char str[] = "1234567890ABCDEF";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_10) {
  char format[] = "%5p";
  char str[] = "0x237";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_11) {
  char format[] = "%6p";
  char str[] = "0xdksajh";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_12) {
  char format[] = "%6p";
  char str[] = "0xAGAGUIY";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_13) {
  char format[] = "%p";
  char str[] = "0xAGAGUIYUYGFSV";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_14) {
  char format[] = "%p";
  char str[] = "0xAA64BB";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_p_15) {
  char format[] = "%p";
  char str[] = "0xGGH7TY";
  int *p1 = 0, *p2 = 0;

  int16_t res1 = s21_sscanf(str, format, &p1);
  int16_t res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(sscanf_spec_n_1) {
  char format[] = "%n";
  char str[] = "danila";
  int n1 = 0, n2 = 0;

  int16_t res1 = s21_sscanf(str, format, &n1);
  int16_t res2 = sscanf(str, format, &n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_spec_n_2) {
  char format[] = "%d %n";
  char str[] = "80";
  int d1 = 0, d2 = 0;
  int n1 = 0, n2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &n1);
  int16_t res2 = sscanf(str, format, &d2, &n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_spec_n_3) {
  char format[] = "%d %d %n %d %d %d";
  char str[] = "80 50 70 371 327";
  int d1 = 0, d2 = 0;
  int dd1 = 0, dd2 = 0;
  int f1 = 0, f2 = 0;
  int ff1 = 0, ff2 = 0;
  int k1 = 0, k2 = 0;
  int n1 = 0, n2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &dd1, &n1, &f1, &ff1, &k1);
  int16_t res2 = sscanf(str, format, &d2, &dd2, &n2, &f2, &ff2, &k2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(dd1, dd2);
  ck_assert_int_eq(f1, f2);
  ck_assert_int_eq(ff1, ff2);
  ck_assert_int_eq(k1, k2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_spec_n_4) {
  char format[] = "%n";
  char str[] = " ";
  int n1 = 0, n2 = 0;

  int16_t res1 = s21_sscanf(str, format, &n1);
  int16_t res2 = sscanf(str, format, &n2);
  ck_assert_int_eq(res1, res2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(sscanf_spec_n_7) {
  char format[] = "%c";
  char str[] = "%";
  char d1 = 0, d2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1);
  int16_t res2 = sscanf(str, format, &d2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(sscanf_spec_n_8) {
  char format[] = "%s %n %s %n %s %s %s";
  char str[] = "Hello, my name is Jinny";
  char s1[30], s2[30], s3[30], s4[30], s5[30], s6[30], s7[30], s8[30], s9[30],
      s10[30];
  int hn1 = 0, hn2 = 0;
  int hhn1 = 0, hhn2 = 0;

  int16_t res1 = s21_sscanf(str, format, &s1, &hn1, &s3, &hhn1, &s5, &s7, &s9);
  int16_t res2 = sscanf(str, format, &s2, &hn2, &s4, &hhn2, &s6, &s8, &s10);
  ck_assert_int_eq(res1, res2);
  ck_assert_pstr_eq(s1, s2);
  ck_assert_pstr_eq(s3, s4);
  ck_assert_pstr_eq(s5, s6);
  ck_assert_pstr_eq(s7, s8);
  ck_assert_pstr_eq(s9, s10);
  ck_assert_int_eq(hn1, hn2);
  ck_assert_int_eq(hhn1, hhn2);
}
END_TEST

START_TEST(sscanf_spec_n_9) {
  char format[] = "%lf %lf %lf %lf %n %lf";
  char str[] = ".0 66.34 9877.66 1.99 0.999";
  double d1 = 0, d2 = 0;
  double dd1 = 0, dd2 = 0;
  double f1 = 0, f2 = 0;
  double ff1 = 0, ff2 = 0;
  double k1 = 0, k2 = 0;
  int n1 = 0, n2 = 0;

  int16_t res1 = s21_sscanf(str, format, &d1, &dd1, &f1, &ff1, &n1, &k1);
  int16_t res2 = sscanf(str, format, &d2, &dd2, &f2, &ff2, &n2, &k2);
  ck_assert_double_eq(res1, res2);
  ck_assert_double_eq(d1, d2);
  ck_assert_double_eq(dd1, dd2);
  ck_assert_double_eq(f1, f2);
  ck_assert_double_eq(ff1, ff2);
  ck_assert_double_eq(k1, k2);
  ck_assert_int_eq(n1, n2);
}
END_TEST

void add_s21_sscanf_test_np(Suite *s) {
  TCase *tc = tcase_create("S21_sscanf");

  tcase_add_test(tc, sscanf_spec_p_1);
  tcase_add_test(tc, sscanf_spec_p_2);
  tcase_add_test(tc, sscanf_spec_p_3);
  tcase_add_test(tc, sscanf_spec_p_4);
  tcase_add_test(tc, sscanf_spec_p_5);
  tcase_add_test(tc, sscanf_spec_p_6);
  tcase_add_test(tc, sscanf_spec_p_7);
  tcase_add_test(tc, sscanf_spec_p_8);
  tcase_add_test(tc, sscanf_spec_p_9);
  tcase_add_test(tc, sscanf_spec_p_10);
  tcase_add_test(tc, sscanf_spec_p_11);
  tcase_add_test(tc, sscanf_spec_p_12);
  tcase_add_test(tc, sscanf_spec_p_13);
  tcase_add_test(tc, sscanf_spec_p_14);
  tcase_add_test(tc, sscanf_spec_p_15);

  tcase_add_test(tc, sscanf_spec_n_1);
  tcase_add_test(tc, sscanf_spec_n_2);
  tcase_add_test(tc, sscanf_spec_n_3);
  tcase_add_test(tc, sscanf_spec_n_4);

  tcase_add_test(tc, sscanf_spec_n_7);
  tcase_add_test(tc, sscanf_spec_n_8);
  tcase_add_test(tc, sscanf_spec_n_9);

  suite_add_tcase(s, tc);
}
