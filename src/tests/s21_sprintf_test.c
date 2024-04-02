#include "s21_string_test.h"

START_TEST(s21_sprintf_1) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Hell%c world!";
  char a = 'o';
  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_2) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Hell%c world!";
  int a = -1;
  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_3) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "----%c!!!!----";
  int c = 366;
  ck_assert_int_eq(sprintf(str1, str3, c), s21_sprintf(str2, str3, c));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_4) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "----%c---";
  char a = 0;
  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_5) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Hello%-010c----Hello<% -10c---%-lc!!!";
  int a = 74;
  unsigned long int b = 74;
  ck_assert_int_eq(sprintf(str1, str3, a, a, b),
                   s21_sprintf(str2, str3, a, a, b));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// START_TEST(s21_sprintf_6) {
//   char str1[100] = "";
//   char str2[100] = "";
//   char *str3 = "<%6.4c>|<%-6.4c>|<%4.10lc>|<%-4.10lc>|<%-0lc>";
//   int a = 10;
//   unsigned long int b = 10;
//   unsigned long int c = 10;
//   ck_assert_int_eq(sprintf(str1, str3, a, a, b, c, c),
//                    s21_sprintf(str2, str3, a, a, b, c, c));
//   ck_assert_pstr_eq(str1, str2);
// }
// END_TEST

START_TEST(s21_sprintf_7) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "--%hc---";
  int a = 3;
  ck_assert_int_eq(sprintf(str1, str3, a), s21_sprintf(str2, str3, a));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_8) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%d>|<%3.d>|<%5.7d>|<%10d>|<%#d>|<%-d>|<%+d>|<%.d>|<% .d>";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val,
                  val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_9) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%e>|<%5e>|<%5.e>";
  double num = -764231539.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_10) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%e>|<%.e>|<%4e>|<%4.e>|<%5.10e>";
  double num = -764231539.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_11) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%#e>|<%#.e>|<%#5.e>|<%#.0e>|<%#0.0e>";
  double num = -665695342471359.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_12) {
  char str1[300] = "";
  char str2[300] = "";
  double num1 = -.3529373967;
  double num4 = -0000000000000.3529373967;
  char *str3 = "<%20.E>|<%-20.E>";
  ck_assert_int_eq(sprintf(str1, str3, num4, num1),
                   s21_sprintf(str2, str3, num4, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_13) {
  char str1[300] = "";
  char str2[300] = "";
  double num1 = 53296575676899283734747273752737878257.;
  char *str3 = "<%- 17.1E>|<% -17.1E>";
  ck_assert_int_eq(sprintf(str1, str3, num1, num1),
                   s21_sprintf(str2, str3, num1, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_14) {
  char str1[300] = "";
  char str2[300] = "";
  double num2 = -53296575676899283734747273752737878257.;
  char *str3 = "<%# 10.2E>|<% #10.0E>|<%010.E>";
  ck_assert_int_eq(sprintf(str1, str3, num2, num2, num2),
                   s21_sprintf(str2, str3, num2, num2, num2));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_15) {
  char str1[600] = "";
  char str2[600] = "";
  double num1 = 53296575676899283734747273752737878257.;
  char *str3 = "<% 10.1E>|<%- 10.1E>";
  ck_assert_int_eq(sprintf(str1, str3, num1, num1),
                   s21_sprintf(str2, str3, num1, num1));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_16) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "<%.e>|<%.2e>|<%.5E>|<%.9E>|<%.13E>";
  double num = -2599999999.;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_17) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%e>|<%.e>|<%.5e>|<%.9e>|<%.15E>";
  double num = 0;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_18) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%060Le!>|<%.14Le>";
  long double num =
      -93257812350000000000000000000683689988320616583292392563908359623906832590653989623598263628236642932982362398.;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_19) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%f>|<%.f>|<%4f>|<%4.f>|<%5.10f>";
  double num = 76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_20) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%f>|<%.f>|<%3f>|<%4.f>|<%5.10f>";
  double num = -76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_21) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%Lf>|<%.Lf>|<%+-#Lf>|<%+#.Lf>|<%-#.Lf>";
  long double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_22) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%5f>|<%6.1f>|<%8.2f>";
  double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_23) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%+15.f>|<%+#16.f>|<%+#18.0f>";
  double num = 7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_24) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%15.13f>|<%26.15f>";
  double num = -365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_25) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%+- 14f>|<%+ 10f>|<% +25f>";
  double num = -365789.34;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_26) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%+- 010.2f>|<%- 025.7f>|<%+- 18.4f>";
  double num = -947.6785643;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_27) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<% 15.1Lf>|<% -26.13Lf>|<%- 30.8Lf>";
  long double num = -2358.367776967;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_28) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%.1Lf>|<%.2Lf>|<%.3Lf>";
  long double num = -9999.99999;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_29) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%.1Lf>|<%.2Lf>|<%.3Lf>";
  long double num = 000000000000000.00000000000;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_30) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%.1Lf>|<%.2Lf>|<%.3Lf>";
  long double num = -236310753.6495633;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_31) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%-+.1Lf>|<%- .2Lf>|<%-0.3Lf>";
  long double num = -0.999999;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_32) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%g>|<%.g>|<%4g>|<%4.g>|<%5.10g>";
  double num = -76.756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_33) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%g>|<%.g>|<%4g>|<%4.g>|<%#5.10g>";
  double num = 0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_34) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%g>|<%.g>|<%4g>|<%4.g>|<%#5.10g>";
  double num = -0.0000756589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_35) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%g>|<%.0g>|<%4.2g>|<%4.g>|<%5.10g>";
  double num = -57251397732103429.56589367;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_36) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%#-10.g>|<%-+25.g>";
  double num = -7648938790.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_37) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%Lg>|<%.Lg>";
  long double num_long = -76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num_long, num_long),
                   s21_sprintf(str2, str3, num_long, num_long));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_38) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%Lg>|<%.Lg>|<%+-#Lg>|<%+#.Lg>|<%-#.Lg>";
  long double num = 76.756589;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num, num, num),
                   s21_sprintf(str2, str3, num, num, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_39) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%15.13g>|<%26.15g>";
  double num = 365289.34628654873789362746834;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_40) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%-+ 025.5g>|<%- 020.4g>";
  double num = 837564.4753366;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_41) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%.g>|<%.2g>|<%.3g>";
  double num = 0;
  ck_assert_int_eq(sprintf(str1, str3, num, num, num),
                   s21_sprintf(str2, str3, num, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_42) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%-20.13g>|<%-25.7g>";
  double num = -4353.235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_43) {
  char str1[400] = "";
  char str2[400] = "";
  char *str3 = "<%+20.13g>|<%+25.7g>";
  double num = 0.00000235300;
  ck_assert_int_eq(sprintf(str1, str3, num, num),
                   s21_sprintf(str2, str3, num, num));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_44) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%x><%3.x><%5.7x><%10x><%#x><%-x><%+x><%.x><% .x>";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_45) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%i><%3.i><%5.7i><%10i><%#i><%-i><%+i><%.i><% .i>";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val,
                  val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_46) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "text %n text";
  int valn1 = 0, valn2 = 0;
  ck_assert_int_eq(sprintf(str1, str3, &valn1),
                   s21_sprintf(str2, str3, &valn2));
  ck_assert_pstr_eq(str1, str2);
  ck_assert_int_eq(valn1, valn2);
}
END_TEST

START_TEST(s21_sprintf_47) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%o><%3.o><%5.7o><%10o %#o %-o %+o %.o % .o>";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_48) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "<%u><%3.u><%5.7u><%10u><%#u><%-u><%+u><%.u><% .u>";
  unsigned int val = 0;
  sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val);
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(s21_sprintf_49) {
  char str1[200] = "";
  char str2[200] = "";
  char *str3 = "--%*d---";
  int width = 10;
  int value = 42;
  ck_assert_int_eq(sprintf(str1, str3, width, value),
                   s21_sprintf(str2, str3, width, value));
  // ck_assert_pstr_eq(str1, str2);
}
END_TEST

void add_s21_sprintf_test(Suite *s) {
  TCase *tc = tcase_create("Core of s21_sprintf");

  tcase_add_test(tc, s21_sprintf_1);
  tcase_add_test(tc, s21_sprintf_2);
  tcase_add_test(tc, s21_sprintf_3);
  tcase_add_test(tc, s21_sprintf_4);
  tcase_add_test(tc, s21_sprintf_5);
  // tcase_add_test(tc, s21_sprintf_6);
  tcase_add_test(tc, s21_sprintf_7);
  tcase_add_test(tc, s21_sprintf_8);
  tcase_add_test(tc, s21_sprintf_9);
  tcase_add_test(tc, s21_sprintf_10);
  tcase_add_test(tc, s21_sprintf_11);
  tcase_add_test(tc, s21_sprintf_12);
  tcase_add_test(tc, s21_sprintf_13);
  tcase_add_test(tc, s21_sprintf_14);
  tcase_add_test(tc, s21_sprintf_15);
  tcase_add_test(tc, s21_sprintf_16);
  tcase_add_test(tc, s21_sprintf_17);
  tcase_add_test(tc, s21_sprintf_18);
  tcase_add_test(tc, s21_sprintf_19);
  tcase_add_test(tc, s21_sprintf_20);
  tcase_add_test(tc, s21_sprintf_21);
  tcase_add_test(tc, s21_sprintf_22);
  tcase_add_test(tc, s21_sprintf_23);
  tcase_add_test(tc, s21_sprintf_24);
  tcase_add_test(tc, s21_sprintf_25);
  tcase_add_test(tc, s21_sprintf_26);
  tcase_add_test(tc, s21_sprintf_27);
  tcase_add_test(tc, s21_sprintf_28);
  tcase_add_test(tc, s21_sprintf_29);
  tcase_add_test(tc, s21_sprintf_30);
  tcase_add_test(tc, s21_sprintf_31);
  tcase_add_test(tc, s21_sprintf_32);
  tcase_add_test(tc, s21_sprintf_33);
  tcase_add_test(tc, s21_sprintf_34);
  tcase_add_test(tc, s21_sprintf_35);
  tcase_add_test(tc, s21_sprintf_36);
  tcase_add_test(tc, s21_sprintf_37);
  tcase_add_test(tc, s21_sprintf_38);
  tcase_add_test(tc, s21_sprintf_39);
  tcase_add_test(tc, s21_sprintf_40);
  tcase_add_test(tc, s21_sprintf_41);
  tcase_add_test(tc, s21_sprintf_42);
  tcase_add_test(tc, s21_sprintf_43);
  tcase_add_test(tc, s21_sprintf_44);
  tcase_add_test(tc, s21_sprintf_45);
  tcase_add_test(tc, s21_sprintf_46);
  tcase_add_test(tc, s21_sprintf_47);
  tcase_add_test(tc, s21_sprintf_48);
  tcase_add_test(tc, s21_sprintf_49);

  suite_add_tcase(s, tc);
}
