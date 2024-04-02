#include <locale.h>
#include <stdarg.h>
#define NMAX 1000
#define ABORT -9999

struct flags {
  char *s0;
  int star;
  int abort;
  int conv_fields;
  int h;
  int l;
  int L;
  int space;
};

void switch_func(char prm, char **string, int width, va_list ap,
                 struct flags *flag);

void check_empty(char *s, struct flags *fl);

void case_c(char **string, int width, va_list ap, struct flags *fl);

void case_d(char **string, int width, va_list ap, struct flags *fl);

void case_i(char **string, int width, va_list ap, struct flags *fl);

void case_e(char **string, int width, va_list ap, struct flags *fl);

void case_f(char **string, int width, va_list ap, struct flags *fl);

void case_g(char **string, int width, va_list ap, struct flags *fl);

void case_o(char **string, int width, va_list ap, struct flags *fl);

void case_s(char **string, int width, va_list ap, struct flags *fl);

void case_u(char **string, int width, va_list ap, struct flags *fl);

void case_x(char **string, int width, va_list ap, struct flags *fl);

void case_p(char **string, int width, va_list ap, struct flags *fl);

void case_n(struct flags *fl, va_list ap, char *s0, char *s);

void case_oZo(char **string, int width, va_list ap, struct flags *fl);

int search_int(char *string);

void common_strtol(char **string, int width, va_list ap, struct flags *fl,
                   int base);

void common_strtoul(char **string, int width, va_list ap, struct flags *fl,
                    int base);

void common_strtof(char **string, int width, va_list ap, struct flags *fl);

int s21_sscanf(const char *str, const char *format, ...);

int s21_strcpy_width(char *s, char **t, int width);

int s21_isdigit(char c);

void del_space(char **string);

void parsing(char **p, int *width, struct flags *fl);
