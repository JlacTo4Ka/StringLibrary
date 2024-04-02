#include "s21_string_test.h"

START_TEST(test_s21_strncpy_normal_case) {
  char dest[20] = "";
  const char *src = "Hello, World!";
  size_t n = 10;
  char *result_s21 = s21_strncpy(dest, src, n);
  ck_assert_str_eq(result_s21, dest);
}
END_TEST

START_TEST(test_s21_strncpy_null_dest) {
  const char *src = "Hello, World!";
  size_t n = 5;
  char *result_s21 = s21_strncpy(NULL, src, n);
  ck_assert_ptr_null(result_s21);
}
END_TEST

START_TEST(test_s21_strncpy_null_src) {
  char dest[20] = "";
  size_t n = 5;
  char *result_s21 = s21_strncpy(dest, NULL, n);
  ck_assert_ptr_null(result_s21);
}
END_TEST

START_TEST(test_s21_strncpy_empty_src) {
  char dest[20] = "";
  const char *src = "";
  size_t n = 5;
  char *result_s21 = s21_strncpy(dest, src, n);
  ck_assert_str_eq(result_s21, dest);
}
END_TEST

void add_s21_strncpy_test(Suite *s) {
  TCase *tc = tcase_create("S21_strncpy");
  tcase_add_test(tc, test_s21_strncpy_normal_case);
  tcase_add_test(tc, test_s21_strncpy_null_dest);
  tcase_add_test(tc, test_s21_strncpy_null_src);
  tcase_add_test(tc, test_s21_strncpy_empty_src);
  suite_add_tcase(s, tc);
}

// // Обычный случай
// START_TEST(test_s21_strncpy_common)
// {
//     char dest[20];
//     const char *src = "Hello, World!";
//     char expected[20];
//     s21_strncpy(dest, src, 30);
//     strncpy(expected, src, 30);
//     ck_assert_str_eq(dest, expected);
// }
// END_TEST

// // Случай с пустым источником
// START_TEST(test_s21_strncpy_empty_src)
// {
//     char dest[20] = "Hello, ";
//     const char *src = "";
//     char expected[20] = "Hello, ";
//     s21_strncpy(dest, src, 30);
//     strncpy(expected, src, 30);
//     ck_assert_str_eq(dest, expected);
// }
// END_TEST

// // Случай с пустым назначением
// START_TEST(test_s21_strncpy_empty_dest)
// {
//     char dest[20] = "";
//     const char *src = "Hello, World!";
//     char expected[20] = "";
//     s21_strncpy(dest, src, 5);
//     strncpy(expected, src, 5);
//     ck_assert_str_eq(dest, expected);
// }
// END_TEST

// // Случай, когда длина src превышает размер dest
// START_TEST(test_s21_strncpy_exceed_dest_size) {
//   char dest[10];
//   const char *src = "Hello, World!";

//   char expected[10];
//   strncpy(expected, src, 10);
//   expected[9] = '\0'; // Исправление: установка нулевого символа в конце
//   ожидаемой строки

//   s21_strncpy(dest, src, 10);
//   ck_assert_str_eq(dest, expected);
// }
// END_TEST

// // Случай, когда src равно NULL
// START_TEST(test_s21_strncpy_null_src) {
//   char dest[20] = "Hello, ";
//   const char *src = NULL;

//   char expected[20] = "Hello, ";
//   strncpy(expected, src, 30);

//   s21_strncpy(dest, src, 30);
//   ck_assert_str_eq(dest, expected);
// }
// END_TEST

// void add_s21_strncpy_test(Suite *s)
// {
//     TCase *t_case = tcase_create("S21_strncpy");
//     tcase_add_test(t_case, test_s21_strncpy_common);
//     tcase_add_test(t_case, test_s21_strncpy_empty_src);
//     tcase_add_test(t_case, test_s21_strncpy_empty_dest);
//     tcase_add_test(t_case, test_s21_strncpy_exceed_dest_size);
//     tcase_add_test(t_case, test_s21_strncpy_null_src);
//     suite_add_tcase(s, t_case);
// }