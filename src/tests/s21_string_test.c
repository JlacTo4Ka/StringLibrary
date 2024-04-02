#include "s21_string_test.h"

Suite *s21_string_suite(void) {
  Suite *s = suite_create("S21_String");

  add_s21_sscanf_test_c(s);
  add_s21_sscanf_test_d(s);
  add_s21_sscanf_test_i(s);
  add_s21_sscanf_test_eEgG(s);
  add_s21_sscanf_test_f(s);
  add_s21_sscanf_test_o(s);
  add_s21_sscanf_test_s(s);
  add_s21_sscanf_test_uoZo(s);
  add_s21_sscanf_test_x(s);
  add_s21_sscanf_test_np(s);

  add_s21_memchr_test(s);
  add_s21_memcmp_test(s);
  add_s21_memcpy_test(s);
  add_s21_memset_test(s);
  add_s21_strncat_test(s);
  add_s21_strncmp_test(s);
  add_s21_strncpy_test(s);
  add_s21_strcspn_test(s);
  add_s21_strcpy_test(s);
  add_s21_strchr_test(s);
  add_s21_strlen_test(s);
  add_s21_strpbrk_test(s);
  add_s21_strrchr_test(s);
  add_s21_strstr_test(s);
  add_s21_strtok_test(s);
  add_s21_strerror_test(s);

  add_s21_insert_test(s);
  add_s21_to_lower_test(s);
  add_s21_to_upper_test(s);
  add_s21_trim_test(s);

  add_s21_sprintf_test(s);

  return s;
}

int main(void) {
  int number_faild = 0;
  Suite *s = s21_string_suite();
  SRunner *sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_faild = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_faild == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
