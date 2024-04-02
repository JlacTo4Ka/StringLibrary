#include "s21_string_test.h"

START_TEST(test_strncat_common_1) {
  char dest[100] = "Hello ";
  char dest1[100] = "Hello ";
  char str[100] = "world!";
  s21_size_t n = 2;
  ck_assert_pstr_eq(strncat(dest, str, n), s21_strncat(dest1, str, n));
}
END_TEST

START_TEST(test_strncat_common_2) {
  char dest[100] = "Hello ";
  char dest1[100] = "Hello ";
  char str[100] = "world!";
  s21_size_t n = 3;
  ck_assert_pstr_eq(strncat(dest, str, n), s21_strncat(dest1, str, n));
}
END_TEST

START_TEST(test_strncat_common_3) {
  char dest[30] = "Hello, world!";
  char dest1[30] = "Hello, world!";
  char str[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(dest, str, n), s21_strncat(dest1, str, n));
}
END_TEST

START_TEST(test_strncat_common_4) {
  char dest[30] = "Hello, world!";
  char dest1[30] = "Hello, world!";
  char str[] = "\n\0\\d\f\\g\7";
  s21_size_t n = 3;
  ck_assert_pstr_eq(strncat(dest, str, n), s21_strncat(dest1, str, n));
}
END_TEST

START_TEST(test_strncat_common_5) {
  char dest[100] = "Hello, world!";
  char dest1[100] = "Hello, world!";
  char str[] =
      "Sims may be just pixel men, but they also have their own needs, "
      "including food.";
  s21_size_t n = 6;
  ck_assert_pstr_eq(strncat(dest, str, n), s21_strncat(dest1, str, n));
}
END_TEST

START_TEST(test_strncat_common_6) {
  char dest[30] = "";
  char dest1[30] = "";
  char str[] = "Hello, world!";
  s21_size_t n = 3;
  ck_assert_pstr_eq(strncat(dest, str, n), s21_strncat(dest1, str, n));
}
END_TEST

START_TEST(test_strncat_common_7) {
  char dest[100] = "Hello, world!";
  char dest1[100] = "Hello, world!";
  char str[] = "Sims may be just pixel men.";
  s21_size_t n = 2;
  ck_assert_pstr_eq(strncat(dest, str, n), s21_strncat(dest1, str, n));
}
END_TEST

START_TEST(test_strncat_common_8) {
  char dest[100] = "";
  char dest1[100] = "";
  char str[] = "";
  s21_size_t n = 10;
  ck_assert_pstr_eq(strncat(dest, str, n), s21_strncat(dest1, str, n));
}
END_TEST

START_TEST(test_strncat_common_9) {
  char dest[100] = "Hello\0, world!";
  char dest1[100] = "Hello\0, world!";
  char str[] = "Sims may\0 be just pixel men.";
  s21_size_t n = 15;
  ck_assert_pstr_eq(strncat(dest, str, n), s21_strncat(dest1, str, n));
}
END_TEST

START_TEST(test_strncat_common_10) {
  char dest[100] = "Hello, world!";
  char dest1[100] = "Hello, world!";
  char str[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncat(dest, str, n), s21_strncat(dest1, str, n));
}
END_TEST

START_TEST(test_strncat_common_11) {
  char dest[100] = "Hello, world!";
  char dest1[100] = "Hello, world!";
  char str[] = "\0";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncat(dest, str, n), s21_strncat(dest1, str, n));
}
END_TEST

START_TEST(test_strncat_common_12) {
  char dest[100] = "Hello, world!";
  char dest1[100] = "Hello, world!";
  char str[] = "\0\0\0";
  s21_size_t n = 4;
  ck_assert_pstr_eq(strncat(dest, str, n), s21_strncat(dest1, str, n));
}
END_TEST

START_TEST(test_strncat_empty_dest) {
  char dest[100] = "";
  char dest1[100] = "";
  char str[100] = "world!";
  s21_size_t n = 3;
  ck_assert_pstr_eq(strncat(dest, str, n), s21_strncat(dest1, str, n));
}
END_TEST

START_TEST(test_strncat_empty_str) {
  char dest[100] = "Hello ";
  char dest1[100] = "Hello ";
  char str[100] = "";
  s21_size_t n = 4;
  ck_assert_pstr_eq(strncat(dest, str, n), s21_strncat(dest1, str, n));
}
END_TEST

void add_s21_strncat_test(Suite *s) {
  TCase *t_case = tcase_create("S21_strncat");

  tcase_add_test(t_case, test_strncat_common_1);
  tcase_add_test(t_case, test_strncat_common_2);
  tcase_add_test(t_case, test_strncat_common_3);
  tcase_add_test(t_case, test_strncat_common_4);
  tcase_add_test(t_case, test_strncat_common_5);
  tcase_add_test(t_case, test_strncat_common_6);
  tcase_add_test(t_case, test_strncat_common_7);
  tcase_add_test(t_case, test_strncat_common_8);
  tcase_add_test(t_case, test_strncat_common_9);
  tcase_add_test(t_case, test_strncat_common_10);
  tcase_add_test(t_case, test_strncat_common_11);
  tcase_add_test(t_case, test_strncat_common_12);
  tcase_add_test(t_case, test_strncat_empty_dest);
  tcase_add_test(t_case, test_strncat_empty_str);

  suite_add_tcase(s, t_case);
}