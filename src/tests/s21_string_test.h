#ifndef TEST_S21_STRING_H
#define TEST_S21_STRING_H

#include <check.h>
#include <stdarg.h>
#include <string.h>

#include "../functions/s21_sscanf.h"
#include "../s21_string.h"

void add_s21_sscanf_test_c(Suite *s);
void add_s21_sscanf_test_d(Suite *s);
void add_s21_sscanf_test_i(Suite *s);
void add_s21_sscanf_test_eEgG(Suite *s);
void add_s21_sscanf_test_f(Suite *s);
void add_s21_sscanf_test_o(Suite *s);
void add_s21_sscanf_test_s(Suite *s);
void add_s21_sscanf_test_uoZo(Suite *s);
void add_s21_sscanf_test_x(Suite *s);
void add_s21_sscanf_test_np(Suite *s);

void add_s21_memchr_test(Suite *s);
void add_s21_memcmp_test(Suite *s);
void add_s21_memcpy_test(Suite *s);
void add_s21_memset_test(Suite *s);
void add_s21_strncat_test(Suite *s);
void add_s21_strncmp_test(Suite *s);
void add_s21_strncpy_test(Suite *s);
void add_s21_strcspn_test(Suite *s);
void add_s21_strcpy_test(Suite *s);
void add_s21_strchr_test(Suite *s);
void add_s21_strlen_test(Suite *s);
void add_s21_strpbrk_test(Suite *s);
void add_s21_strrchr_test(Suite *s);
void add_s21_strstr_test(Suite *s);
void add_s21_strtok_test(Suite *s);
void add_s21_strerror_test(Suite *s);

void add_s21_insert_test(Suite *s);
void add_s21_to_upper_test(Suite *s);
void add_s21_to_lower_test(Suite *s);
void add_s21_trim_test(Suite *s);

void add_s21_sprintf_test(Suite *s);

Suite *s21_string_suite(void);

#endif
