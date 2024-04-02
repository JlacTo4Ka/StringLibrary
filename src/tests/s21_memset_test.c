#include "s21_string_test.h"

START_TEST(test_s21_memset_common) {
  char dest[20];
  char expected[20] = "Hello, World!\0";
  s21_memset(dest, 'H', 13);
  memset(expected, 'H', 13);
  ck_assert_mem_eq(dest, expected, 13);
}
END_TEST

START_TEST(memset_1) {
  char str1[] = "abcdefghij";
  char str2[] = "abcdefghij";
  int c = '2';
  int n = 10;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_2) {
  char str1[] = "abcdefghij";
  char str2[] = "abcdefghij";
  int c = 'a';
  int n = 10;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_3) {
  char str1[] = "abcdefghij";
  char str2[] = "abcdefghij";
  int c = '2';
  int n = 1;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(memset_4) {
  char str1[] = "abcdefghij";
  char str2[] = "abcdefghij";
  int c = '2';
  int n = 5;
  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(test_s21_memset_zero_character) {
  char dest[20] = "Hello, World!\0";
  char expected[20] = "Hello, World!\0";
  s21_memset(dest, '\0', 13);
  memset(expected, '\0', 13);
  ck_assert_mem_eq(dest, expected, 13);
}
END_TEST

void add_s21_memset_test(Suite *s) {
  TCase *t_case = tcase_create("S21_memset");
  tcase_add_test(t_case, test_s21_memset_common);
  tcase_add_test(t_case, test_s21_memset_zero_character);
  tcase_add_test(t_case, memset_1);
  tcase_add_test(t_case, memset_2);
  tcase_add_test(t_case, memset_3);
  tcase_add_test(t_case, memset_4);
  suite_add_tcase(s, t_case);
}