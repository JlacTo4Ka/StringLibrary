#include "s21_sprintf.h"

int s21_sprintf(char *str, const char *format, ...) {
  str[0] = '\0';
  int answer = 0;
  va_list args;
  va_start(args, format);

  while (format[0] != '\0') {
    options ops = {0};

    if (format[0] == '%') {
      format++;
      format = parse_flags(&ops, format);
      format = parse_width(&ops, format, args);
      format = parse_precision(&ops, format, args);
      format = parse_length(&ops, format);
      format = parse_specifiers(&ops, format);
      action(&ops, args, &str, answer);
      answer += ops.char_index;
    } else {
      s21_strncat(str, format, 1);
      format++;
      answer++;
    }
  }
  va_end(args);

  return answer;
}

const char *parse_flags(options *ops, const char *format) {
  while (format[0] == '-' || format[0] == '+' || format[0] == ' ' ||
         format[0] == '#' || format[0] == '0') {
    if (format[0] == '-') {
      ops->flag_minus = 1;
    } else if (format[0] == '+') {
      ops->flag_plus = 1;
    } else if (format[0] == ' ') {
      ops->flag_space = 1;
    } else if (format[0] == '#') {
      ops->flag_sharp = 1;
    } else if (format[0] == '0') {
      ops->flag_zero = 1;
    }
    format++;
  }

  return format;
}

const char *parse_width(options *ops, const char *format, va_list args) {
  ops->width = 0;
  if (format[0] == '*') {
    ops->width = va_arg(args, int);
    format++;
  } else {
    while (format[0] >= '0' && format[0] <= '9') {
      ops->width *= 10;
      ops->width += format[0] - '0';
      format++;
    }
  }
  return format;
}

const char *parse_precision(options *ops, const char *format, va_list args) {
  ops->precision = 0;
  if (format[0] == '.') {
    ops->precision_active = 1;
    format++;
    if (format[0] == '*') {
      ops->precision = va_arg(args, int);
      format++;
    } else {
      while (format[0] >= '0' && format[0] <= '9') {
        ops->precision *= 10;
        ops->precision += format[0] - '0';
        format++;
      }
    }
  }

  return format;
}

const char *parse_length(options *ops, const char *format) {
  if (format[0] == 'h' || format[0] == 'l' || format[0] == 'L') {
    ops->length = format[0];
    format++;
  }

  return format;
}

const char *parse_specifiers(options *ops, const char *format) {
  if (format[0] != '\0' && s21_strchr("cdieEfgGosuxXpn%", *format)) {
    ops->specifier = format[0];
    format++;
  }
  return format;
}

void action(options *ops, va_list args, char **str, int answer) {
  if (ops->specifier == '%' || ops->specifier == 'c') {
    specifier_c(ops, args, str);
  } else if (ops->specifier == 'd' || ops->specifier == 'i') {
    specifier_d(ops, args, *str);
  } else if (ops->specifier == 's') {
    specifier_s(ops, args, *str);
  } else if (ops->specifier == 'f' || ops->specifier == 'e' ||
             ops->specifier == 'E' || ops->specifier == 'g' ||
             ops->specifier == 'G') {
    specifier_float(ops, *str, args);
  } else if (ops->specifier == 'o' || ops->specifier == 'u' ||
             ops->specifier == 'x' || ops->specifier == 'X') {
    specifier_unsigned(ops, *str, args);
  } else if (ops->specifier == 'n') {
    specifier_n(ops, args, answer);
  } else if (ops->specifier == 'p') {
    specifier_p(ops, *str, args);
  }
}

void specifier_c(options *ops, va_list args, char **str) {
  char c = 0;
  ops->char_index = 1;

  if (ops->specifier == 'c') {
    c = va_arg(args, int);
  } else if (ops->specifier == '%') {
    c = '%';
  }

  char *str_copy = *str;
  while (str_copy[0] != '\0') {
    str_copy++;
  }
  ops->width--;

  if (ops->width != 0) {
    str_copy[0] = c;
    str_copy++;
    if (c == '\0') {
      str_copy[0] = '\0';
    }
    *str = str_copy;
    add_spaces(ops, *str);
    add_zeros(ops, *str);
  } else {
    add_spaces(ops, *str);
    add_zeros(ops, *str);
    while (str_copy[0] != '\0') {
      str_copy++;
    }
    str_copy[0] = c;
    str_copy++;
    if (c == '\0') {
      str_copy[0] = '\0';
    }
    *str = str_copy;
  }
}

void add_spaces(options *ops, char *str) {
  if (ops->flag_zero == 0 || ops->flag_minus != 0) {
    while (ops->width > 0) {
      s21_strcat(str, " ");
      ops->width--;
      ops->char_index++;
    }
  }
}

void add_zeros(options *ops, char *str) {
  if ((ops->flag_zero != 0 || ops->flag_minus == 0)) {
    while (ops->width > 0) {
      s21_strcat(str, "0");
      ops->width--;
      ops->char_index++;
    }
  }
}

void specifier_d(options *ops, va_list args, char *str) {
  long value = 0;

  if (ops->length == 'l') {
    value = (long)va_arg(args, long int);
  } else if (ops->length == '\0') {
    value = (int)va_arg(args, int);
  } else if (ops->length == 'h') {
    value = (short int)va_arg(args, int);
  }

  char int_str[3000] = "\0";

  s21_itoa(value, int_str);
  write_int(ops, str, int_str);
}

void s21_itoa(long value, char *str) {
  char str2[2048] = {'\0'};
  int i = 0, k = 0;
  if (value < 0) {
    str[i++] = '-';
    str2[k++] = '-';
  }
  if (value == 0) {
    str[i] = '0';
  }
  while (value != 0) {
    int a = 1;
    int b = 0;
    if (value < 0) a = -1;
    b = value % 10;
    str2[i++] = a * b + '0';
    value /= 10;
  }
  i--;
  while (i >= 0 && str2[i] != '-') {
    str[k++] = str2[i--];
  }
}

void write_int(options *ops, char *str, char *str_int) {
  char buffer_str[2048] = {'\0'};
  int length = (int)s21_strlen(str_int);
  if (ops->width > length) {
    length = ops->width;
  }
  if (ops->precision > length) {
    length = ops->precision;
  }
  if (ops->flag_minus) {
    fill_precision_int(ops, buffer_str, str_int, length);
    fill_width_int(ops, buffer_str, str_int, length);
    s21_strncat(str, buffer_str, s21_strlen(buffer_str));
  } else {
    fill_width_int(ops, buffer_str, str_int, length);
    fill_precision_int(ops, buffer_str, str_int, length);
    s21_strncat(str, buffer_str, s21_strlen(buffer_str));
  }
  ops->char_index += (int)s21_strlen(buffer_str);
}

void fill_precision_int(options *ops, char *buffer_str, char *str_int,
                        int length) {
  int f = ops->width <= ops->precision && ops->precision_active &&
          str_int[0] != '-';
  if (ops->flag_space && !ops->flag_plus &&
      ops->width <= (int)s21_strlen(str_int)) {
    s21_strncat(buffer_str, " ", f);
  }
  if (ops->flag_space && !ops->flag_plus && str_int[0] != '-') {
    s21_strncat(buffer_str, " ", !f);
  }
  length = ops->precision - s21_strlen(str_int) + (str_int[0] == '-');
  if (length < 0) {
    length = 0;
  }
  char buffer[1024] = {'\0'};
  if (ops->flag_plus) {
    s21_strncat(buffer_str, "+", 1);
  }
  if (ops->flag_zero && str_int[0] == '-') {
    buffer_str[s21_strlen(buffer_str) - ops->flag_plus] = '0';
    buffer_str[0] = '-';
    int i = 0;
    while (i != (int)s21_strlen(str_int) - 1) {
      str_int[i] = str_int[i + 1];
      i++;
    }
    str_int[i] = 0;
  }
  if (str_int[0] == '-') {
    buffer_str[s21_strlen(buffer_str) - ops->flag_plus] = '-';
    int i = 0;
    while (i != (int)s21_strlen(str_int) - 1) {
      str_int[i] = str_int[i + 1];
      i++;
    }
    str_int[i] = 0;
  }
  s21_memset(buffer, '0', length);
  s21_strncat(buffer_str, buffer, s21_strlen(buffer));
  if (!(ops->precision_active && !ops->precision && *str_int == '0')) {
    s21_strncat(buffer_str, str_int, s21_strlen(str_int));
  }
}

void fill_width_int(options *ops, char *buffer_str, char *str_int, int length) {
  char buffer[1024] = {'\0'};
  int width = 0;
  char ch = ' ';
  if (ops->flag_minus) {
    width = length - s21_strlen(buffer_str);
  } else {
    if (ops->precision >
        (int)s21_strlen(str_int) - (s21_strchr(str_int, '-') != 0)) {
      width = length - (ops->precision) -
              ((s21_strchr(str_int, '-') != 0) || ops->flag_plus);
    } else {
      if (!ops->precision && ops->precision_active && ops->width) {
        width = ops->width - s21_strlen(str_int) +
                (ops->precision_active && !ops->precision && *str_int == '0');
      } else {
        width = length - (s21_strlen(str_int)) -
                (ops->flag_plus && (!s21_strchr(str_int, '-')));
      }
    }
  }
  if (width < 0) {
    width = 0;
  }
  if (ops->flag_zero) {
    ch = '0';
  }
  s21_memset(buffer, ch, width);
  s21_strncat(buffer_str, buffer, s21_strlen(buffer));
}

void specifier_s(options *ops, va_list args, char *str) {
  char *s = va_arg(args, char *);
  if (s == s21_NULL) {
    s = "(null)";
    if (ops->precision > (int)s21_strlen(s)) {
      ops->precision = (int)s21_strlen(s);
    }
  } else {
    if (ops->precision > (int)s21_strlen(s) || !ops->precision_active) {
      ops->precision = s21_strlen(s);
    }
  }
  ops->char_index = ops->precision;
  if (ops->width > 0 && (ops->width - ops->precision) <= 0 &&
      ops->precision_active != 0) {
    if (ops->width > (int)s21_strlen(s)) {
      ops->width -= (int)s21_strlen(s);
    } else {
      ops->width = 0;
    }
  } else {
    ops->width -= ops->precision;
  }
  if (ops->flag_minus != 0) {
    s21_strncat(str, s, ops->precision);
    add_spaces(ops, str);
    add_zeros(ops, str);
  } else {
    add_spaces(ops, str);
    add_zeros(ops, str);
    s21_strncat(str, s, ops->precision);
  }
}

void specifier_float(options *ops, char *str, va_list args) {
  long double value = 0;

  switch (ops->length) {
    case 'l':
      value = (double)va_arg(args, double);
      break;
    case '\0':
      value = va_arg(args, double);
      break;
    case 'L':
      value = (long double)va_arg(args, long double);
      break;
  }
  switch (ops->specifier) {
    case 'f':
      specifier_f(ops, str, value);
      break;
    case 'e':
    case 'E':
      specifier_e(ops, str, value);
      break;
    case 'g':
    case 'G':
      specifier_g(ops, str, value);
      break;
  }
}

void specifier_f(options *ops, char *str, long double value) {
  char str_float[2048] = {'\0'};
  if (!ops->precision_active) {
    ops->precision = 6;
  }
  s21_ftoa(value, str_float, ops->precision);
  write_f(ops, str, str_float);
}

void s21_ftoa(long double value, char *str_float, long precision) {
  char buffer[2048] = {'\0'};
  if (value < 0) {
    value *= -1;
    *str_float++ = '-';
  }
  if (!isNanInf(value, str_float)) {
    int i = 0;
    long double buffer_value = floorl(fabsl(value));
    long double decimal = value - buffer_value;
    if (!precision && !(value > 0 && value < 1)) {
      value = roundl(value);
      if (value == 0) {
        buffer[i++] = (s21_size_t)(value) + '0';
      }
      handler_for_s21_ftoa(value, str_float, i, buffer);
      while (*str_float) {
        str_float++;
      }
    } else {
      if (precision < 0) precision = 0;
      long double intdec = decimal * (powl(10, precision));
      intdec = (roundl(intdec) / (pow(10, precision)));
      buffer_value = buffer_value + intdec;
      if (buffer_value == 0) {
        *str_float++ = '0';
      } else if (buffer_value < 1) {
        *str_float++ = '0';
      }
      handler_for_s21_ftoa(buffer_value, str_float, i, buffer);
      while (*str_float) {
        str_float++;
      }
      if (precision) {
        s21_memset(buffer, '0', 2048);
        *str_float++ = '.';
        decimal = roundl(decimal * (powl(10, precision)));
      }
      s21_size_t precision2 = precision;
      while (precision) {
        buffer[precision - 1] = (fmodl(decimal, 10)) + '0';
        decimal /= 10;
        precision--;
      }
      for (s21_size_t j = 0; j < precision2; j++) {
        *str_float++ = buffer[j];
      }
    }
  }
}

void handler_for_s21_ftoa(long double new_value, char *str_float, int i,
                          char *buffer) {
  while ((s21_size_t)new_value > 0) {
    buffer[i++] = ((s21_size_t)(new_value) % 10) + '0';
    new_value /= 10;
  }
  while (i) {
    *str_float++ = buffer[i - 1];
    i--;
  }
}

int isNanInf(long double value, char *str_float) {
  int result = 0;
  int i = 0 + (str_float[0] != 0);
  if (isinf(value)) {
    str_float[i] = 'i';
    str_float[i + 1] = 'n';
    str_float[i + 2] = 'f';
    result = 1;
  }
  if (isnan(value)) {
    str_float[i] = 'n';
    str_float[i + 1] = 'a';
    str_float[i + 2] = 'n';
    result = 1;
  }
  return result;
}

void write_f(options *ops, char *str, char *str_float) {
  int length = (int)s21_strlen(str_float);
  ops->char_index = length;
  if (ops->width > length) {
    ops->width -= length;
  } else {
    ops->width = 0;
  }
  if (ops->flag_minus) {
    flag_fill_maker(ops, str, str_float);
    float_fill_maker(ops, str, str_float);
    fill_width_float(ops, str, str_float);
  } else {
    fill_width_float(ops, str, str_float);
    flag_fill_maker(ops, str, str_float);
    float_fill_maker(ops, str, str_float);
  }
}

// void float_fill_maker(options *ops, char *str, char *str_float) {
//   s21_strcat(str, str_float);
//   if (ops->flag_sharp && !ops->precision) {
//     s21_strcat(str, ".");
//     ops->char_index++;
//   }
//   ops->flag_space = 0;
//   ops->flag_plus = 0;
//   ops->flag_zero = 0;
// }

void flag_fill_maker(options *ops, char *str, char *str_float) {
  char *ch = {0};
  ch = "";
  if (s21_strncmp(str_float, "-", 1)) {
    if (ops->flag_space) {
      ch = " ";
    }
    if (ops->flag_plus) {
      ch = "+";
    }
    if (ops->flag_space || ops->flag_plus) {
      ops->width--;
      ops->char_index++;
      ops->flag_space = 0;
      ops->flag_plus = 0;
    }
  } else {
    ch = "-";
    offset_maker(str_float);
    ops->flag_plus = 0;
    ops->flag_space = 0;
  }
  s21_strcat(str, ch);
}

void offset_maker(char *str) {
  while (*str) {
    *str = *(str + 1);
    str++;
  }
}

void float_fill_maker(options *ops, char *str, char *str_float) {
  s21_strcat(str, str_float);
  if (ops->flag_sharp && !ops->precision) {
    s21_strcat(str, ".");
    ops->char_index++;
  }
  ops->flag_space = 0;
  ops->flag_plus = 0;
  ops->flag_zero = 0;
}

void fill_width_float(options *ops, char *str, char *str_float) {
  char *ch = " ";
  if (!s21_strncmp(str_float, "-", 1)) {
    ops->flag_space = 0;
    ops->flag_plus = 0;
  }
  if (ops->flag_zero) {
    ch = "0";
    if (!s21_strncmp(str_float, "-", 1)) {
      s21_strcat(str, "-");
      offset_maker(str_float);
    } else if (ops->flag_plus || ops->flag_space) {
      flag_fill_maker(ops, str, str_float);
    }
  }
  if ((ops->flag_space || ops->flag_plus) &&
      (!s21_strchr(str_float, 'e') || !s21_strchr(str_float, 'E'))) {
    ops->width--;
  }
  if (ops->flag_sharp && !ops->precision) {
    ops->width--;
  }
  while (ops->width > 0) {
    s21_strcat(str, ch);
    ops->width--;
    ops->char_index++;
  }
}

void specifier_e(options *ops, char *str, long double value) {
  char str_float[2048] = {'\0'};
  if (!ops->precision_active) {
    ops->precision = 6;
  }
  s21_ftoe(ops, value, str_float, ops->precision);
  if (ops->specifier == 'E') {
    upperStrX(str_float);
  }
  write_f(ops, str, str_float);
}

void s21_ftoe(options *ops, long double value, char *str_float,
              long precision) {
  int k = 0;
  char coef[128] = {0};
  char e[3] = {0};
  if (value < 0) {
    *str_float++ = '-';
    value *= -1;
  }
  if (value == 0) {
    s21_strncat(e, "e+", 2);
  } else if (value > 1) {
    while (value >= 10) {
      value /= 10;
      k++;
    }
    s21_strncat(e, "e+", 2);
  } else if (value < 1) {
    while (fmodl(value, 10) < 1) {
      value *= 10;
      k++;
    }
    s21_strncat(e, "e-", 2);
  }
  if (precision) {
    s21_ftoa(value, str_float, precision);
  } else {
    value = roundl(value);
    s21_ftoa(value, str_float, precision);
  }
  if (ops->flag_sharp && !ops->precision) {
    s21_strcat(str_float, ".");
    ops->char_index++;
    ops->flag_sharp = 0;
  }
  s21_strncat(str_float, e, 2);
  if (k < 10) {
    s21_itoa(k, coef);
    s21_strncat(str_float, "0", 1);
    s21_strncat(str_float, coef, s21_strlen(coef));
  } else {
    s21_itoa(k, coef);
    s21_strncat(str_float, coef, s21_strlen(coef));
  }
}

void specifier_g(options *ops, char *str, long double value) {
  char str_float[2048] = {'\0'};
  long double buffer_value = floorl(fabsl(value));
  if (!ops->precision_active) {
    ops->precision = 6;
  }
  int precision = 0;
  int decimal_count = 0;
  if (fabsl(value) >= 1) {
    while (buffer_value >= 1) {
      buffer_value /= 10;
      precision++;
    }
  } else if (fabsl(value)) {
    buffer_value = fabsl(value);
    while (buffer_value < 1) {
      buffer_value *= 10;
      decimal_count++;
    }
  }
  if (precision > ops->precision || decimal_count > 4) {
    s21_ftoe(ops, value, str_float, ops->precision - 1);
    if (!ops->flag_sharp &&
        !((ops->specifier == 'g' || ops->specifier == 'G') &&
          !ops->precision_active)) {
      sharp_offset_maker(str_float);
    }
  } else {
    if (precision) {
      ops->precision -= precision;
    } else if ((ops->specifier == 'g' || ops->specifier == 'G') &&
               ops->precision) {
      ops->precision--;
      ops->precision += decimal_count;
    } else {
      ops->precision += decimal_count;
    }
    s21_ftoa(value, str_float, ops->precision);

    if (!ops->flag_sharp) {
      sharp_offset_maker(str_float);
    }
  }
  if (ops->specifier == 'G') {
    upperStrX(str_float);
  }
  write_f(ops, str, str_float);
}

void upperStrX(char *adrees) {
  for (s21_size_t i = 0; i < s21_strlen(adrees); i++) {
    if (adrees[i] >= 'a' && adrees[i] <= 'z') {
      adrees[i] -= 32;
    }
  }
}

void sharp_offset_maker(char *str) {
  if (s21_strchr(str, 'e')) {
    char *p = s21_strchr(str, 'e');
    p--;
    if (*p == '0') {
      while (*(p) == '0' || *(p) == '.') {
        offset_maker(p);
        p--;
      }
    }
  } else {
    if (s21_strchr(str, '.')) {
      str += s21_strlen(str) - 1;
      while (*(str) == '0') {
        *str = 0;
        str--;
      }
      if (*str == '.') {
        *str = 0;
      }
    }
  }
}

void specifier_unsigned(options *ops, char *str, va_list args) {
  unsigned long long value = 0;
  switch (ops->length) {
    case 'h':
      value = (short unsigned)va_arg(args, unsigned int);
      break;
    case '\0':
      value = (unsigned)va_arg(args, unsigned int);
      break;
    case 'l':
      value = (unsigned long)va_arg(args, unsigned long int);
      break;
  }
  switch (ops->specifier) {
    case 'o':
      specifier_o(ops, str, value);
      break;
    case 'x':
    case 'X':
      specifier_x(ops, str, value);
      break;
    case 'u':
      specifier_u(ops, str, value);
      break;
  }
}

void specifier_u(options *ops, char *str, unsigned long long value) {
  char str2[2048] = {'\0'};
  s21_utoa(value, str2);
  write_unsigned(ops, str, str2);
}

void s21_utoa(unsigned long long value, char *str) {
  char str2[2048] = {'\0'};
  int i = 0, k = 0;
  if (value == 0) {
    str[i] = '0';
  }
  while (value != 0) {
    str2[i++] = value % 10 + '0';
    value /= 10;
  }
  i--;
  while (i >= 0) {
    str[k++] = str2[i--];
  }
}

void write_unsigned(options *ops, char *str, char *str_int) {
  char buffer_str[2048] = {'\0'};
  int length = (int)s21_strlen(str_int);
  if (ops->width > length) {
    length = ops->width;
  }
  if (ops->precision > length) {
    length = ops->precision;
  }
  if (ops->flag_minus) {
    fill_precision_unsigned(ops, buffer_str, str_int, length);
    fill_width_unsigned(ops, buffer_str, str_int, length);
    s21_strncat(str, buffer_str, s21_strlen(buffer_str));
  } else {
    fill_width_unsigned(ops, buffer_str, str_int, length);
    fill_precision_unsigned(ops, buffer_str, str_int, length);
    s21_strncat(str, buffer_str, s21_strlen(buffer_str));
  }
  ops->char_index = s21_strlen(buffer_str);
}

void fill_precision_unsigned(options *ops, char *buffer_str, char *str_int,
                             int length) {
  if (ops->flag_space && !ops->flag_plus &&
      ops->width <= (int)s21_strlen(str_int)) {
    s21_strncat(buffer_str, " ", ops->width > (int)s21_strlen(str_int));
  }
  length = ops->precision - s21_strlen(str_int);
  if (length < 0) {
    length = 0;
  }
  char buffer[1024] = {'\0'};
  s21_memset(buffer, '0', length);
  s21_strncat(buffer_str, buffer, s21_strlen(buffer));
  if (!(ops->precision_active && !ops->precision && *str_int == '0')) {
    s21_strncat(buffer_str, str_int, s21_strlen(str_int));
  }
}

void fill_width_unsigned(options *ops, char *buffer_str, char *str_int,
                         int length) {
  char buffer[1024] = {'\0'};
  int width = 0;
  char ch = ' ';
  if (ops->flag_minus) {
    width = length - s21_strlen(buffer_str);
  } else {
    if (ops->precision > (int)s21_strlen(str_int)) {
      width = length - (ops->precision);
    } else {
      if (!ops->precision && ops->precision_active && ops->width) {
        width = ops->width - s21_strlen(str_int) +
                (ops->precision_active && !ops->precision && *str_int == '0');
      } else {
        width = length - (s21_strlen(str_int));
      }
    }
  }
  if (width < 0) {
    width = 0;
  }
  if (ops->flag_zero) {
    ch = '0';
  }
  s21_memset(buffer, ch, width);
  s21_strncat(buffer_str, buffer, s21_strlen(buffer));
}

void specifier_o(options *ops, char *str, unsigned long long value) {
  char valueStr[1024] = {'\0'};
  dex_to_hex(ops, valueStr, value, 8);
  int valueLen = s21_strlen(valueStr);
  ops->precision -= valueLen;
  if (ops->precision <= 0) {
    ops->width -= valueLen;
  } else {
    ops->width -= valueLen + ops->precision;
  }
  ops->char_index += valueLen;
  if (ops->flag_minus != 0) {
    prefix(ops, &str, value);
    zero(ops, str);
    add_zeros(ops, str);
    s21_strcat(str, valueStr);
    add_spaces(ops, str);
  } else {
    prefix(ops, &str, value);
    zero(ops, str);
    add_zeros(ops, str);
    s21_strcat(str, valueStr);
  }
}

void dex_to_hex(options *ops, char *adrees, unsigned long long value,
                int base) {
  const char hex[17] = {"0123456789abcdef"};
  char pt[1024] = {0};
  int i = 0;
  if (value == 0 && ((ops->precision_active == 1 && ops->precision > 0) ||
                     (ops->precision_active == 0))) {
    int x = value % base;
    value = value / base;
    pt[i++] = hex[x];
  } else if (value == 0 && ops->specifier == 'o' &&
             ((ops->precision_active == 1 && ops->precision > 0) ||
              (ops->precision_active == 0))) {
    pt[i++] = '0';
  }
  while (value != 0) {
    int x = value % base;
    value = value / base;
    pt[i++] = hex[x];
  }
  i--;
  int j = 0;
  while (i >= 0) {
    adrees[j++] = pt[i--];
  }
}

void prefix(options *ops, char **str, unsigned long long value) {
  if (ops->specifier != 'o') {
    if (ops->flag_minus != 0) {
      if (ops->flag_sharp == 1 && value != 0) {
        ops->width -= 2;
        ops->char_index += 2;
        if (ops->specifier == 'x') {
          s21_strcat(*str, "0x");
        } else {
          s21_strcat(*str, "0X");
        }
      }
    } else {
      if (ops->flag_sharp == 1 && value != 0) {
        ops->width -= 2;
        ops->char_index += 2;
        add_spaces(ops, *str);
        if (ops->specifier == 'x') {
          s21_strcat(*str, "0x");
        } else {
          s21_strcat(*str, "0X");
        }
      } else {
        add_spaces(ops, *str);
      }
    }
  } else {
    if (ops->flag_minus != 0) {
      if (ops->flag_sharp == 1 && ops->precision < 0 && value != 0) {
        ops->width--;
        ops->char_index++;

        ops->precision--;
        s21_strcat(*str, "0");
      }
    } else {
      if (ops->flag_sharp == 1 && value != 0) {
        add_spaces(ops, *str);
        ops->width--;
        ops->char_index++;
        ops->precision--;
        s21_strcat(*str, "0");
      } else {
        add_spaces(ops, *str);
      }
    }
  }
}

void zero(options *ops, char *str) {
  int i = ops->precision;
  const char ignore[] = "feEgG";
  while (i > 0 && s21_strchr(ignore, ops->precision) == s21_NULL) {
    s21_strcat(str, "0");
    ops->char_index++;
    i--;
  }
}

void specifier_x(options *ops, char *str, unsigned long long value) {
  char valueStr[1024] = {'\0'};
  dex_to_hex(ops, valueStr, value, 16);
  if (ops->specifier == 'x') {
    lowerStrX(valueStr);
  }
  if (ops->specifier == 'X') {
    upperStrX(valueStr);
  }
  int valueLen = s21_strlen(valueStr);
  ops->precision -= valueLen;
  if (ops->precision <= 0) {
    ops->width -= valueLen;
  } else {
    ops->width -= valueLen + ops->precision;
  }
  ops->char_index += valueLen;
  if (ops->flag_minus != 0) {
    prefix(ops, &str, value);
    zero(ops, str);
    add_zeros(ops, str);
    s21_strcat(str, valueStr);
    add_spaces(ops, str);
  } else {
    prefix(ops, &str, value);
    zero(ops, str);
    add_zeros(ops, str);
    s21_strcat(str, valueStr);
  }
}

void lowerStrX(char *adrees) {
  for (s21_size_t i = 0; i < s21_strlen(adrees); i++) {
    if (adrees[i] >= 'A' && adrees[i] <= 'Z') {
      adrees[i] += 32;
    }
  }
}

void specifier_n(options *ops, va_list args, int result) {
  ops->n = 1;
  int *val = va_arg(args, int *);
  *val = result;
}

void specifier_p(options *ops, char *str, va_list args) {
  char adrees[1024] = {0};
  unsigned long long value =
      (unsigned long long)va_arg(args, unsigned long long);
  dex_to_hex(ops, adrees, value, 16);
  int valueLen = s21_strlen(adrees) + 2;
  ops->precision -= valueLen - 2;
  if (ops->precision <= 0) {
    ops->width -= valueLen;
  } else {
    ops->width -= valueLen + ops->precision;
  }
  ops->char_index += valueLen;
  if (ops->flag_minus != 0) {
    if (ops->flag_plus == 1) {
      s21_strcat(str, "+");
      ops->char_index++;
    }
    s21_strcat(str, "0x");
    zero(ops, str);
    s21_strcat(str, adrees);
    add_spaces(ops, str);
  } else {
    add_spaces(ops, str);
    s21_strcat(str, "0x");
    zero(ops, str);
    s21_strcat(str, adrees);
  }
}