#include "s21_string_test.h"

START_TEST(s21_memchr_1) {
  char str[] = "Hello, world!";
  int ch = ' ';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_2) {
  char str[] = "Hello, world!";
  int ch = 'H';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_3) {
  char str[] = "Hello, world!";
  int ch = 101;
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_4) {
  char str[] = "Hello, world!";
  int ch = 65;
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_5) {
  char str[] = "Hello, world!";
  int ch = 'l';
  s21_size_t len = 10;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_6) {
  char str[] = "Hello, world!";
  int ch = 'w';
  s21_size_t len = 5;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_7) {
  char str[] = "12345";
  int ch = '8';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_8) {
  char str[] = "12345678";
  int ch = '2';
  s21_size_t len = 0;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_9) {
  char str[] = "123456";
  int ch = 'g';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(s21_memchr_10) {
  char str[] = "123456";
  int ch = '\0';
  s21_size_t len = 9;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

void add_s21_memchr_test(Suite *s) {
  TCase *t_case = tcase_create("S21_memchr");
  tcase_add_test(t_case, s21_memchr_1);
  tcase_add_test(t_case, s21_memchr_2);
  tcase_add_test(t_case, s21_memchr_3);
  tcase_add_test(t_case, s21_memchr_4);
  tcase_add_test(t_case, s21_memchr_5);
  tcase_add_test(t_case, s21_memchr_6);
  tcase_add_test(t_case, s21_memchr_7);
  tcase_add_test(t_case, s21_memchr_8);
  tcase_add_test(t_case, s21_memchr_9);
  tcase_add_test(t_case, s21_memchr_10);

  suite_add_tcase(s, t_case);
}
