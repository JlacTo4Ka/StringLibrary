#include "s21_string_test.h"

START_TEST(test_memcmp_common) {
  char str1_common[] = "Hello, World!\0";
  char str2_common[] = "aeiou\0";
  int result = s21_memcmp(str1_common, str2_common, s21_strlen(str1_common));
  int expected = memcmp(str1_common, str2_common, strlen(str1_common));
  result = result > 0 ? 1 : result < 0 ? -1 : result;
  expected = expected > 0 ? 1 : expected < 0 ? -1 : expected;
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_memcmp_no_common) {
  char str1_no_common[] = "1234567890\0";
  char str2_no_common[] = "abcdefghijklmnopqrstuvwxyz\0";
  int result =
      s21_memcmp(str1_no_common, str2_no_common, strlen(str1_no_common));
  int expected = memcmp(str1_no_common, str2_no_common, strlen(str1_no_common));
  result = result > 0 ? 1 : result < 0 ? -1 : result;
  expected = expected > 0 ? 1 : expected < 0 ? -1 : expected;
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_memcmp_empty) {
  char str1_empty[] = "\0";
  char str2_empty[] = "\0";
  int result = s21_memcmp(str1_empty, str2_empty, s21_strlen(str1_empty));
  int expected = memcmp(str1_empty, str2_empty, s21_strlen(str1_empty));
  result = result > 0 ? 1 : result < 0 ? -1 : result;
  expected = expected > 0 ? 1 : expected < 0 ? -1 : expected;
  ck_assert_int_eq(result, expected);
}
END_TEST

START_TEST(test_memcmp_first_condition) {
  char str1_first_condition[] = "def\0";
  char str2_first_condition[] = "abc\0";
  int result = s21_memcmp(str1_first_condition, str2_first_condition,
                          strlen(str1_first_condition));
  int expected = memcmp(str1_first_condition, str2_first_condition,
                        strlen(str1_first_condition));
  result = result > 0 ? 1 : result < 0 ? -1 : result;
  expected = expected > 0 ? 1 : expected < 0 ? -1 : expected;
  ck_assert_int_eq(result, expected);
}
END_TEST

void add_s21_memcmp_test(Suite *s) {
  TCase *t_case = tcase_create("S21_memcmp");

  tcase_add_test(t_case, test_memcmp_common);
  tcase_add_test(t_case, test_memcmp_no_common);
  tcase_add_test(t_case, test_memcmp_empty);
  tcase_add_test(t_case, test_memcmp_first_condition);

  suite_add_tcase(s, t_case);
}
