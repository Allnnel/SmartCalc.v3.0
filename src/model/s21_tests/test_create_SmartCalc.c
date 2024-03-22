#include "../s21_SmartCalc.h"
#include "tests.h"

START_TEST(create_SmartCalc_1) {
  int error = 0;
  const char *str = "1+2";
  long double result = 1 + 2;
  long double x = 0;
   
   long double res = *s21_Input(str, x);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res, result);
}
END_TEST

START_TEST(create_SmartCalc_2) {
  int error = 0;

  const char *str = "20+x^2";
  long double x = 4;

   
  long double result = 20 + pow(4, 2);

   long double res = *s21_Input(str, x);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res, result);
}
END_TEST


START_TEST(create_SmartCalc_3) {
  int error = 0;

  const char *str = "-80/200";
  long double x = 0;

   
  long double result = -80 / 200;

   long double res = *s21_Input(str, x);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res, result);
}
END_TEST

START_TEST(create_SmartCalc_4) {
 int error = 0;

 const char *str = "-80*(+20)";
 long double x = 0;

  
 long double result = -80 * (+20);

  long double res = *s21_Input(str, x);
 ck_assert_int_eq(error, 0);
 ck_assert_int_eq(res, result);
}
END_TEST

START_TEST(create_SmartCalc_5) {
 int error = 0;

 const char *str = "60mod5";
 long double x = 0;

  
 long double result = 60 % 5;

  long double res = *s21_Input(str, x);
 ck_assert_int_eq(error, 0);
 ck_assert_int_eq(res, result);
}
END_TEST

START_TEST(create_SmartCalc_6) {
 int error = 0;

 const char *str = "sin(4)";
 long double x = 0;

  
 long double result = sin(4);

  long double res = *s21_Input(str, x);
 ck_assert_int_eq(error, 0);
 ck_assert_int_eq(res, result);
}
END_TEST

START_TEST(create_SmartCalc_7) {
 int error = 0;

 const char *str = "cos(-2)";
 long double x = 0;

  
 long double result = cos(-2);

  long double res = *s21_Input(str, x);
 ck_assert_int_eq(error, 0);
 ck_assert_int_eq(res, result);
}
END_TEST

START_TEST(create_SmartCalc_8) {
 int error = 0;

 const char *str = "cos(-2))";
 long double x = 0;
  *s21_Input(str, x);
}
END_TEST

START_TEST(create_SmartCalc_9) {
 int error = 0;

 const char *str = "cos((-2)";
 long double x = 0;

  

  long double res = *s21_Input(str, x);
  
}
END_TEST

START_TEST(create_SmartCalc_10) {
 int error = 0;

 const char *str = "76587-----";
 long double x = 0;

  

  long double res = *s21_Input(str, x);
  
}
END_TEST

START_TEST(create_SmartCalc_11) {
 int error = 0;

 const char *str = "*6-2";
 long double x = 0;

  

  long double res = *s21_Input(str, x);
  
}
END_TEST

START_TEST(create_SmartCalc_12) {
 int error = 0;

 const char *str = "20(7/2/";
 long double x = 0;

  

  long double res = *s21_Input(str, x);
  
}
END_TEST

START_TEST(create_SmartCalc_13) {
 int error = 0;

 const char *str = "30+(4*(200+1)/2)-100*asin(1)";
 long double x = 0;

  
 long double result = 30 + (4 * (200 + 1) / 2) - 100 * asin(1);
  long double res = *s21_Input(str, x);
 ck_assert_int_eq(error, 0);
 ck_assert_int_eq(res, result);
}
END_TEST

START_TEST(create_SmartCalc_14) {
 int error = 0;

 const char *str = "8.3+3.8^2";
 long double x = 0;

  
 long double result = 8.3 + powl(3.8, 2);
  long double res = *s21_Input(str, x);
 ck_assert_int_eq(error, 0);
 ck_assert_int_eq(res, result);
}
END_TEST

START_TEST(create_SmartCalc_15) {
 int error = 0;

 const char *str = "atan(3)";
 long double x = 0;

  
 long double result = atan(3);
  long double res = *s21_Input(str, x);
 ck_assert_int_eq(error, 0);
 ck_assert_int_eq(res, result);
}
END_TEST

START_TEST(create_SmartCalc_16) {
 int error = 0;

 const char *str = "tan(3)";
 long double x = 0;

  
 long double result = tan(3);
  long double res = *s21_Input(str, x);
 ck_assert_int_eq(error, 0);
 ck_assert_int_eq(res, result);
}
END_TEST

START_TEST(create_SmartCalc_17) {
 int error = 0;

 const char *str = "sqrt(20)";
 long double x = 0;

  
 long double result = sqrt(20);
  long double res = *s21_Input(str, x);
 ck_assert_int_eq(error, 0);
 ck_assert_int_eq(res, result);
}
END_TEST

START_TEST(create_SmartCalc_18) {
 int error = 0;

 const char *str = "log(5)-ln(2)";
 long double x = 0;

  
 long double result = log10(5) - log(2);
  long double res = *s21_Input(str, x);
 ck_assert_int_eq(error, 0);
 ck_assert_int_eq(res, result);
}
END_TEST

START_TEST(create_SmartCalc_19) {
 int error = 0;

 const char *str = "log(5)-ln(2)";
 long double x = 0;

  
 long double result = log10(5) - log(2);
  long double res = *s21_Input(str, x);
 ck_assert_int_eq(error, 0);
 ck_assert_int_eq(res, result);
}
END_TEST

START_TEST(create_SmartCalc_20) {
 int error = 0;

 const char *str = "60.23/59-294*(87-(-5.34))*2.1";
 long double x = 0;

  
 long double result = 60.23 / 59 - 294 * (+87 - (-5.34)) * 2.1;
  long double res = *s21_Input(str, x);
 ck_assert_int_eq(error, 0);
 ck_assert_int_eq(res, result);
}
END_TEST

START_TEST(create_SmartCalc_21) {
 int error = 0;

 const char *str = "+x-7+(-30)*(-x)--x+x++x";
 long double x = 6;

  
 long double result = (+6) - 7 + (-30) * (-6) - (-6) + 6 + (+6);
  long double res = *s21_Input(str, x);
 ck_assert_int_eq(error, 0);
 ck_assert_int_eq(res, result);
}
END_TEST

START_TEST(create_SmartCalc_22) {
 int error = 0;

 const char *str = "acos(1)";
 long double x = 0;

  
 long double result = acos(1);
  long double res = *s21_Input(str, x);
 ck_assert_int_eq(error, 0);
 ck_assert_int_eq(res, result);
}
END_TEST

START_TEST(create_SmartCalc_23) {
 int error = 0;

 const char *str = "3 + 22 - (5 + 89) * 1";
 long double x = 0;

  
 long double result = 3 + 22 - (5 + 89) * 1;
  long double res = *s21_Input(str, x);
 ck_assert_int_eq(error, 0);
 ck_assert_int_eq(res, result);
}
END_TEST

START_TEST(create_SmartCalc_24) {
 int error = 0;

 const char *str = "i";
 long double x = 0;
  
  long double res = *s21_Input(str, x);
  
}
END_TEST

START_TEST(create_SmartCalc_25) {
 int error = 0;

 const char *str = NULL;
 long double x = 0;
  
  long double res = *s21_Input(str, x);
  
}
END_TEST

START_TEST(create_SmartCalc_26) {
 int error = 0;

 const char *str = "8 + 2 i";
 long double x = 0;
  
  long double res = *s21_Input(str, x);
  
}
END_TEST

START_TEST(create_SmartCalc_27) {
 int error = 0;

 const char *str = "8965 - 22 + (75 * 1) / 2 + 10^3 - -77 + +2";
 long double x = 0;

  
 long double result = 8965 - 22 + (75 * 1) / 2 + powl(10, 3) - -77 + +2;
  long double res = *s21_Input(str, x);
 ck_assert_int_eq(error, 0);
 ck_assert_int_eq(res, result);
}

START_TEST(create_SmartCalc_28) {
 int error = 0;

 const char *str = "+47-22mod3*1";
 long double x = 0;

  
 long double result = +47 - 22 % 3 * 1;
  long double res = *s21_Input(str, x);
 ck_assert_int_eq(error, 0);
 ck_assert_int_eq(res, result);
}

START_TEST(create_SmartCalc_29) {
 int error = 0;

 const char *str =
     "888 - 333333 / 75 + 22 + (-6543) + (654-98765*6543+(8765-543))";
 long double x = 0;

  
 long double result =
     888 - 333333 / 75 + 22 + (-6543) + (654 - 98765 * 6543 + (8765 - 543));
  long double res = *s21_Input(str, x);
 ck_assert_int_eq(error, 0);
 ck_assert_int_eq(res, result);
}

START_TEST(create_SmartCalc_30) {
 int error = 0;

 const char *str = "+3 - -1 + -5 + 765 * -2";
 long double x = 0;

  
 long double result = +3 - -1 + -5 + 765 * -2;
  long double res = *s21_Input(str, x);
 ck_assert_int_eq(error, 0);
 ck_assert_int_eq(res, result);
}



END_TEST

START_TEST(create_SmartCalc_33) {
 int error = 0;

 const char *str = "cos(2^2)-sin(2^2^2)+cos2^2";
 long double x = 0;

  
 long double result =
     cos(powl(2, 2)) - sin(powl(2, powl(2, 2))) + powl(cos(2), 2);
  long double res = *s21_Input(str, x);
 ck_assert_int_eq(error, 0);
 ck_assert_int_eq(res, result);
}

Suite *test_SmartCalc() {
  Suite *s = suite_create("create");
  TCase *tc = tcase_create("create");

  tcase_add_test(tc, create_SmartCalc_1);
  tcase_add_test(tc, create_SmartCalc_2);
  tcase_add_test(tc, create_SmartCalc_3);
 tcase_add_test(tc, create_SmartCalc_4);
 tcase_add_test(tc, create_SmartCalc_5);
 tcase_add_test(tc, create_SmartCalc_6);
 tcase_add_test(tc, create_SmartCalc_7);
 tcase_add_test(tc, create_SmartCalc_8);
 tcase_add_test(tc, create_SmartCalc_9);
 tcase_add_test(tc, create_SmartCalc_10);
 tcase_add_test(tc, create_SmartCalc_11);
 tcase_add_test(tc, create_SmartCalc_12);
 tcase_add_test(tc, create_SmartCalc_13);
 tcase_add_test(tc, create_SmartCalc_14);
 tcase_add_test(tc, create_SmartCalc_15);
 tcase_add_test(tc, create_SmartCalc_16);
 tcase_add_test(tc, create_SmartCalc_17);
 tcase_add_test(tc, create_SmartCalc_18);
 tcase_add_test(tc, create_SmartCalc_19);
 tcase_add_test(tc, create_SmartCalc_20);
 tcase_add_test(tc, create_SmartCalc_21);
 tcase_add_test(tc, create_SmartCalc_22);
 tcase_add_test(tc, create_SmartCalc_23);
 tcase_add_test(tc, create_SmartCalc_24);
 tcase_add_test(tc, create_SmartCalc_25);
 tcase_add_test(tc, create_SmartCalc_26);
 tcase_add_test(tc, create_SmartCalc_27);
 tcase_add_test(tc, create_SmartCalc_28);
 tcase_add_test(tc, create_SmartCalc_29);
 tcase_add_test(tc, create_SmartCalc_30);
 tcase_add_test(tc, create_SmartCalc_33);

  suite_add_tcase(s, tc);

  return s;
}
