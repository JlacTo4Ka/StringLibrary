#include "s21_string_test.h"

START_TEST(sscanf_case_u1) {
  char format[] = "%1u %3u %6u";
  char str[] = "76 +643 -20";
  unsigned int d1, d2;
  unsigned int q1, q2;
  unsigned int z1, z2;

  int16_t res1 = s21_sscanf(str, format, &d1, &q1, &z1);
  int16_t res2 = sscanf(str, format, &d2, &q2, &z2);
  ck_assert_int_eq(res1, res2);
  ck_assert_uint_eq(d1, d2);
  ck_assert_uint_eq(q1, q2);
  ck_assert_uint_eq(z1, z2);
}
END_TEST

void add_s21_sscanf_test_uoZo(Suite *s) {
  TCase *tc = tcase_create("S21_sscanf");

  tcase_add_test(tc, sscanf_case_u1);

  suite_add_tcase(s, tc);
}
