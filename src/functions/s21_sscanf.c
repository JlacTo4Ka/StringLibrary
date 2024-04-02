#include "s21_sscanf.h"

#include "../s21_string.h"

int s21_sscanf(const char *str, const char *format, ...) {
  va_list ap;
  struct flags fl;
  fl.conv_fields = 0;
  fl.abort = 1;
  fl.h = 0;
  fl.l = 0;
  fl.L = 0;
  fl.space = 0;

  char copy_format[NMAX];
  char copy_str[NMAX];
  int width = -1;

  s21_strcpy(copy_format, format);
  s21_strcpy(copy_str, str);

  char *p = copy_format;
  char *s = copy_str;
  fl.s0 = s;

  del_space(&p);
  check_empty(s, &fl);

  if (*s == '\0' || *s == -1 || s == NULL || *s == '\n') {
    fl.conv_fields = ABORT;
  }

  va_start(ap, format);
  for (; *p && fl.abort; p++) {
    fl.star = 1;
    width = -1;
    del_space(&p);
    if (*p != '%') {
      s++;
      continue;
    }

    parsing(&p, &width, &fl);
    switch_func(*++p, &s, width, ap, &fl);
  }

  p = NULL;
  va_end(ap);

  if (fl.conv_fields < 0) {
    fl.conv_fields = -1;
  }

  return fl.conv_fields;
}

int search_int(char *string) {
  int len = 0;

  while (s21_isdigit(string[len])) {
    len++;
  }

  return len;
}

void common_strtof(char **string, int width, va_list ap, struct flags *fl) {
  char string1[200];
  char *end = NULL;
  void *pointer = NULL;

  for (int i = 0; i < 200; i++) {
    string1[i] = -1;
  }

  if (fl->star != ABORT && width != -1) {
    fl->conv_fields++;
    width = s21_strcpy_width(string1, string, width);
    if (fl->l == 1) {
      pointer = va_arg(ap, void *);
      *(double *)pointer = (double)strtod(string1, &end);
      if (string1 == end && width != 1) {
        fl->conv_fields--;
      } else if (width == 1) {
        if (strtod(string1, &end) == 0 && *string1 != '0') {
          fl->conv_fields--;
        }
      }
    } else if (fl->L) {
      pointer = va_arg(ap, void *);
      *(long double *)pointer = (long double)strtold(string1, &end);
      if (string1 == end && width != 1) {
        fl->conv_fields--;
      } else if (width == 1) {
        if (strtold(string1, &end) == 0 && *string1 != '0') {
          fl->conv_fields--;
        }
      }
    } else {
      pointer = va_arg(ap, void *);
      *(float *)pointer = (float)strtof(string1, &end);
      if (string1 == end && width != 1) {
        fl->conv_fields--;
      } else if (width == 1) {
        if ((strtof(string1, &end) == 0 && *string1 != '0') ||
            *string1 == '.' || *string1 == '+') {
          fl->conv_fields--;
        }
      }
    }
  }

  if (fl->star != ABORT && width == -1) {
    fl->conv_fields++;
    if (fl->l == 1) {
      pointer = va_arg(ap, void *);
      *(double *)pointer = (double)strtod(*string, &end);
      if (*string == end) {
        fl->conv_fields--;
      }
    } else if (fl->L == 1) {
      pointer = va_arg(ap, void *);
      *(long double *)pointer = (long double)strtold(*string, &end);
      if (*string == end) {
        fl->conv_fields--;
      }
    } else {
      pointer = va_arg(ap, void *);
      *(float *)pointer = (float)strtof(*string, &end);
      if (*string == end) {
        fl->conv_fields--;
      }
    }
  }

  if (fl->star == ABORT) {
    if (width == -1) {
      strtod(*string, &end);
    } else {
      strtod(string1, &end);
    }
  }

  if (width == -1) {
    *string = end;
  } else {
    *string += width;
  }
}

void common_strtoul(char **string, int width, va_list ap, struct flags *fl,
                    int base) {
  char string1[200];
  char *end = NULL;
  void *pointer = NULL;

  for (int i = 0; i < 200; i++) {
    string1[i] = -1;
  }

  if (fl->star != ABORT && width != -1) {
    fl->conv_fields++;
    width = s21_strcpy_width(string1, string, width);
    if (fl->h == 1) {
      pointer = va_arg(ap, void *);
      *(short *)pointer = (short)(long int)strtoul(string1, &end, base);
      if (string1 == end) {
        fl->conv_fields--;
      }
    } else if (fl->l == 1) {
      pointer = va_arg(ap, void *);
      *(long *)pointer = (long)strtoul(string1, &end, base);
      if (string1 == end) {
        fl->conv_fields--;
      }
    } else {
      pointer = va_arg(ap, void *);
      *(int *)pointer = (int)strtoul(string1, &end, base);
      if (string1 == end) {
        fl->conv_fields--;
      }
    }
  }

  if (fl->star != ABORT && width == -1) {
    fl->conv_fields++;
    if (fl->h == 1) {
      pointer = va_arg(ap, void *);
      *(short *)pointer = (short)(long int)strtoul(*string, &end, base);
      if (*string == end) {
        fl->conv_fields--;
      }
    } else if (fl->l == 1) {
      pointer = va_arg(ap, void *);
      *(long *)pointer = (long)strtoul(*string, &end, base);
      if (*string == end) {
        fl->conv_fields--;
      }
    } else {
      pointer = va_arg(ap, void *);
      *(int *)pointer = (int)strtoul(*string, &end, base);
      if (*string == end) {
        fl->conv_fields--;
      }
    }
  }

  if (fl->star == ABORT) {
    if (width == -1) {
      strtoul(*string, &end, base);
    } else {
      strtoul(string1, &end, base);
    }
  }

  if (width == -1) {
    *string = end;
  } else {
    *string += width;
  }
}

void common_strtol(char **string, int width, va_list ap, struct flags *fl,
                   int base) {
  char string1[200];
  char *end = NULL;
  void *pointer = NULL;

  for (int i = 0; i < 200; i++) {
    string1[i] = -1;
  }

  if (fl->star != ABORT && width != -1) {
    fl->conv_fields++;
    width = s21_strcpy_width(string1, string, width);
    if (fl->h == 1) {
      pointer = va_arg(ap, void *);
      *(short *)pointer = (short)(long int)strtol(string1, &end, base);
      if (string1 == end) {
        fl->conv_fields--;
      }
    } else if (fl->l == 1) {
      pointer = va_arg(ap, void *);
      *(long *)pointer = (long)strtol(string1, &end, base);
      if (string1 == end) {
        fl->conv_fields--;
      }
    } else {
      pointer = va_arg(ap, void *);
      *(int *)pointer = (int)strtol(string1, &end, base);
      if (string1 == end) {
        fl->conv_fields--;
      }
    }
  }

  if (fl->star != ABORT && width == -1) {
    fl->conv_fields++;
    if (fl->h == 1) {
      pointer = va_arg(ap, void *);
      *(short *)pointer = (short)(long int)strtol(*string, &end, base);
      if (*string == end) {
        fl->conv_fields--;
      }
    } else if (fl->l == 1) {
      pointer = va_arg(ap, void *);
      *(long *)pointer = (long)strtol(*string, &end, base);
      if (*string == end) {
        fl->conv_fields--;
      }
    } else {
      pointer = va_arg(ap, void *);
      *(int *)pointer = (int)strtol(*string, &end, base);
      if (*string == end) {
        fl->conv_fields--;
      }
    }
  }

  if (fl->star == ABORT) {
    if (width == -1) {
      strtol(*string, &end, base);
    } else {
      strtol(string1, &end, base);
    }
  }

  if (width == -1) {
    *string = end;
  } else {
    *string += width;
  }
}

void case_c(char **string, int width, va_list ap, struct flags *fl) {
  if (width == 0) {
  };
  size_t len = 2;

  wchar_t *warr;
  char *cval;

  if (fl->star != ABORT) {
    fl->conv_fields++;
    if (fl->l == 1) {
      warr = va_arg(ap, wchar_t *);
      mbstowcs(warr, *string, len);
    } else {
      cval = va_arg(ap, char *);
      *cval = **string;
    }
  }
  *string += 1;
}

void case_d(char **string, int width, va_list ap, struct flags *fl) {
  common_strtol(string, width, ap, fl, 10);
}

void case_i(char **string, int width, va_list ap, struct flags *fl) {
  common_strtol(string, width, ap, fl, 0);
}
void case_e(char **string, int width, va_list ap, struct flags *fl) {
  common_strtof(string, width, ap, fl);
}

void case_f(char **string, int width, va_list ap, struct flags *fl) {
  common_strtof(string, width, ap, fl);
}

void case_g(char **string, int width, va_list ap, struct flags *fl) {
  common_strtof(string, width, ap, fl);
}

void case_o(char **string, int width, va_list ap, struct flags *fl) {
  common_strtoul(string, width, ap, fl, 8);
}

void case_s(char **string, int width, va_list ap, struct flags *fl) {
  wchar_t wcopy[1000];
  wchar_t *wsval = wcopy;

  char copy[1000];
  char *sval = copy;

  while (**string == ' ') {
    (*string)++;
  }

  if (fl->star != ABORT) {
    fl->conv_fields++;
    if (fl->l == 1) {
      wsval = va_arg(ap, wchar_t *);
    } else {
      sval = va_arg(ap, char *);
    }
  }

  if (fl->l == 1) {
    if (width == -1) {
      for (int i = 0; **string != ' ' && **string != '\0'; *string += 1, i++) {
        mbstowcs(wsval, *string, 1);
        wsval++;
      }
    } else {
      for (int i = 0; i < width && **string != '\0'; *string += 1, i++) {
        mbstowcs(wsval, *string, width);
        wsval++;
      }
    }
  } else {
    if (width == -1) {
      for (int i = 0; **string != ' ' && **string != '\0'; *string += 1, i++) {
        *sval = **string;
        sval++;
      }
    } else {
      for (int i = 0; i < width && **string != '\0'; *string += 1, i++) {
        *sval = **string;
        sval++;
      }
    }
  }

  *sval = '\0';
}

void case_u(char **string, int width, va_list ap, struct flags *fl) {
  common_strtoul(string, width, ap, fl, 10);
}

void case_x(char **string, int width, va_list ap, struct flags *fl) {
  common_strtoul(string, width, ap, fl, 16);
}

void case_p(char **string, int width, va_list ap, struct flags *fl) {
  if (width == 0) {
  };
  char *end;
  int len = 0;

  long unsigned int copy = 0;
  long unsigned int *ival = &copy;

  void **pval;

  if (fl->star != ABORT) {
    pval = va_arg(ap, void **);
    len = search_int(*string);
    *ival = strtoul(*string, &end, 16);
    if (*string != end) {
      fl->conv_fields++;
      *pval = (void *)*ival;
      *pval = (short *)*pval;
    }
  } else {
    *ival = strtoul(*string, &end, 16);
  }
  if (len == 0) {
    fl->conv_fields = ABORT;
  }
  *string = end;
}

void case_n(struct flags *fl, va_list ap, char *s0, char *s) {
  int copy = 0;
  int *nval = &copy;

  if (fl->star != ABORT) {
    nval = va_arg(ap, int *);
    if (fl->conv_fields < 0) {
      *nval = 0;
      fl->conv_fields = 0;
    } else {
      if (fl->space == 1) {
        *nval = s - s0 + 1;
      } else {
        *nval = s - s0;
      }
    }
  }
  if (fl->conv_fields == 0) {
    *nval = 0;
  }
}

void case_oZo(char **string, int width, va_list ap, struct flags *fl) {
  if (width == 0) {
  };
  char *cval = NULL;
  if (fl->star != ABORT) {
    cval = va_arg(ap, char *);
  }
  *cval = '%';
  *string += 1;
}

int s21_isdigit(char c) {
  int res = 0;
  if (c >= 48 && c <= 57) {
    res = 1;
  }
  return res;
}

void del_space(char **string) {
  while (**string == ' ') {
    *string += 1;
  }
}

int s21_strcpy_width(char *s, char **t, int width) {
  int i = 0;

  if (*t == NULL) {
    return 0;
  }

  if (width != 1) {
    while (**t == ' ') {
      (*t)++;
    }
  }
  while (i < width && (s[i] = (*t)[i]) != '\0' && (*t)[i] != ' ') {
    i++;
  }
  if (width == 1) {
    i = 1;
  }
  return i;
}

void parsing(char **p, int *width, struct flags *fl) {
  if (s21_isdigit(*(*p + 1))) {
    if (s21_isdigit(*(*p + 2))) {
      *width = (*(*p + 1) - '0') * 10 + (*(*p + 2) - '0');
      *p += 2;
    } else {
      *width = *(*p + 1) - '0';
      *p += 1;
    }
  }
  if (*(*p + 1) == '*') {
    fl->star = ABORT;
    *p += 1;
  }
  if (*(*p + 1) == 'h') {
    fl->h = 1;
    *p += 1;
  } else if (*(*p + 1) == 'l') {
    fl->l = 1;
    *p += 1;
  } else if (*(*p + 1) == 'L') {
    fl->L = 1;
    *p += 1;
  }
}

void check_empty(char *s, struct flags *fl) {
  int len = 0;
  int res = 1;
  while (s[len]) {
    if (s[len] == ' ') {
      res *= 1;
      fl->space = 1;
    } else {
      res *= 0;
    }
    len++;
  }
  if (res == 1) {
    fl->conv_fields = ABORT;
  }
}

void switch_func(char prm, char **string, int width, va_list ap,
                 struct flags *flag) {
  switch (prm) {
    case 'c':
      case_c(string, width, ap, flag);
      break;
    case 'd':
      case_d(string, width, ap, flag);
      break;
    case 'i':
      case_i(string, width, ap, flag);
      break;
    case 'e':
      case_e(string, width, ap, flag);
      break;
    case 'E':
      case_e(string, width, ap, flag);
      break;
    case 'f':
      case_f(string, width, ap, flag);
      break;
    case 'g':
      case_g(string, width, ap, flag);
      break;
    case 'G':
      case_g(string, width, ap, flag);
      break;
    case 'o':
      case_o(string, width, ap, flag);
      break;
    case 's':
      case_s(string, width, ap, flag);
      break;
    case 'u':
      case_u(string, width, ap, flag);
      break;
    case 'x':
      case_x(string, width, ap, flag);
      break;
    case 'X':
      case_x(string, width, ap, flag);
      break;
    case 'p':
      case_p(string, width, ap, flag);
      break;
    case 'n':
      case_n(flag, ap, flag->s0, *string);
      break;
    case '%':
      case_oZo(string, width, ap, flag);
      break;
    default:
      break;
  }
}