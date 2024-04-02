#ifndef SRC_S21_SPRINT_H
#define SRC_S21_SPRINT_H

#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_string.h"

#define s21_NULL (void *)0

typedef long unsigned s21_size_t;

typedef struct options {
  int flag_minus;
  int flag_plus;
  int flag_space;
  int flag_sharp;
  int flag_zero;
  int width;
  int precision;
  int precision_active;
  char length;
  char specifier;
  int char_index;
  int n;
} options;

int s21_sprintf(char *str, const char *format, ...);
const char *parse_flags(options *ops, const char *format);
const char *parse_width(options *ops, const char *format, va_list args);
const char *parse_precision(options *ops, const char *format, va_list args);
const char *parse_length(options *ops, const char *format);
const char *parse_specifiers(options *ops, const char *format);
void action(options *ops, va_list args, char **str, int answer);
void specifier_c(options *ops, va_list args, char **str);
void add_spaces(options *ops, char *str);
void add_zeros(options *ops, char *str);
void specifier_d(options *ops, va_list args, char *str);
void s21_itoa(long value, char *str);
void write_int(options *ops, char *str, char *str_int);
void specifier_s(options *ops, va_list args, char *str);
void fill_precision_int(options *ops, char *buffer_str, char *str_int,
                        int length);
void specifier_float(options *ops, char *str, va_list args);
void specifier_f(options *ops, char *str, long double value);
void flag_fill_maker(options *ops, char *str, char *str_float);
void offset_maker(char *str);
void float_fill_maker(options *ops, char *str, char *str_float);
void fill_width_float(options *ops, char *str, char *str_float);
void s21_ftoa(long double value, char *str_float, long precision);
void handler_for_s21_ftoa(long double new_value, char *str_float, int i,
                          char *buffer);
int isNanInf(long double value, char *str_float);
void specifier_e(options *ops, char *str, long double value);
void s21_ftoe(options *ops, long double value, char *str_float, long precision);
void specifier_g(options *ops, char *str, long double value);
void upperStrX(char *adrees);
void sharp_offset_maker(char *str);
void specifier_unsigned(options *ops, char *str, va_list args);
void specifier_o(options *ops, char *str, unsigned long long value);
void dex_to_hex(options *ops, char *adrees, unsigned long long value, int base);
void prefix(options *ops, char **str, unsigned long long value);
void zero(options *ops, char *str);
void specifier_x(options *ops, char *str, unsigned long long value);
void lowerStrX(char *adrees);
void specifier_u(options *ops, char *str, unsigned long long value);
void s21_utoa(unsigned long long value, char *str);
void write_unsigned(options *ops, char *str, char *str_int);
void fill_precision_unsigned(options *ops, char *buffer_str, char *str_int,
                             int length);
void fill_width_unsigned(options *ops, char *buffer_str, char *str_int,
                         int length);
void specifier_n(options *ops, va_list args, int result);
void specifier_p(options *ops, char *str, va_list args);
void write_f(options *ops, char *str, char *str_float);
void fill_width_int(options *ops, char *buffer_str, char *str_int, int length);

#endif
