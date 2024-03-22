#include "s21_SmartCalc.h"

int s21_OperatorProcessing(char** str, StackSign* ListSign, StackNum* ListNum,
                           int* CountBrackets) {
  int error = 0;
  char operator= s21_SignNegative(ListNum, str);
  if (operator== '(') *CountBrackets += 1;
  if (ListSign->head != NULL &&
      ListSign->head->priority == 2 && operator== '^') {
    if (*(*str + 1) == '\0' || *(*str + 2) == ')' || *(*str + 1) != '^')
      s21_ArithmeticOperators(ListSign, ListNum);
  }
  if ((ListSign->head != NULL) &&
      ((ListSign->head->priority | s21_Priority_StackSign(operator)) > 1))
    while ((ListNum->head != NULL) && (ListNum->head->next != NULL) &&
           (ListSign->head->priority != 0) &&
           (ListSign->head->priority <= s21_Priority_StackSign(operator))) {
      s21_ArithmeticOperators(ListSign, ListNum);
    }
  s21_IncilizationList_StackSign(ListSign, operator);
  return error;
}

int s21_BraceProcessing(char** str, StackSign* ListSign, StackNum* ListNum,
                        int* CountBrackets) {
  int error = 0;
  s21_SignNegative(ListNum, str);
  *CountBrackets -= 1;
  if (*CountBrackets >= 0)
    while (ListSign->head != NULL && ListSign->head->priority != 0)
      s21_ArithmeticOperators(ListSign, ListNum);
  s21_DeleteHead_StackSign(ListSign);
  return error;
}

char s21_SignNegative(StackNum* ListNum, char** str) {
  char operator = s21_NameOption(str);
  if (operator == '-' || operator == '+') {
    if (((!((*(*str - 1) >= '0' && *(*str - 1) <= '9') || *(*str - 1) == 'x') && *(*str - 1) != ')') && ((*(*str + 1) >= '0' && *(*str + 1) <= '9') || *(*str + 1) == 'x')) || ListNum->head == NULL) {
      if (operator == '-') {
        operator = '~';
      } else if (operator == '+') {
        operator = '!';
      }
    }
  }
  return operator;
}


void s21_ArithmeticOperators(StackSign* ListSign, StackNum* ListNum) {
  double result = 0;
  if (ListSign->head != NULL &&
      strchr("cCsStTnql", ListSign->head->sign) != NULL) {
    double OneNum = ListNum->head->num;
    s21_DeleteHead_StackNum(ListNum);
    result = s21_TrigonometricOtions(ListSign, OneNum);
  } else {
    double TwoNum = ListNum->head->num;
    double OneNum = ListNum->head->next->num;

    s21_DeleteHead_StackNum(ListNum);
    s21_DeleteHead_StackNum(ListNum);
    result = s21_OperatorsResuit(ListSign->head->sign, OneNum, TwoNum);
  }

  s21_DeleteHead_StackSign(ListSign);
  s21_IncilizationList_StackNum(ListNum, result);
}

double s21_TrigonometricOtions(StackSign* ListSign, double OneNum) {
  double result = 0;
  if (ListSign->head != NULL) {
    if (ListSign->head->sign == 'c')
      result = cosl(OneNum);
    else if (ListSign->head->sign == 'C')
      result = acosl(OneNum);
    else if (ListSign->head->sign == 's')
      result = sinl(OneNum);
    else if (ListSign->head->sign == 'S')
      result = asinl(OneNum);
    else if (ListSign->head->sign == 't')
      result = tanl(OneNum);
    else if (ListSign->head->sign == 'T')
      result = atanl(OneNum);
    else if (ListSign->head->sign == 'n')
      result = logl(OneNum);
    else if (ListSign->head->sign == 'l')
      result = log10l(OneNum);
    else if (ListSign->head->sign == 'q')
      result = sqrtl(OneNum);
  }
  return result;
}

char s21_NameOption(char** str) {
  char name = **str;
  if (strchr("cstalm", **str) != NULL) {
    int num = 2;
    if (strncmp(*str, "ln", num) == 0)
      name = 'n';
    else if (strncmp(*str, "sin", ++num) == 0)
      name = 's';
    else if (strncmp(*str, "cos", num) == 0)
      name = 'c';
    else if (strncmp(*str, "tan", num) == 0)
      name = 't';
    else if (strncmp(*str, "log", num) == 0)
      name = 'l';
    else if (strncmp(*str, "mod", num) == 0)
      name = 'm';
    else if (strncmp(*str, "sqrt", ++num) == 0)
      name = 'q';
    else if (strncmp(*str, "asin", num) == 0)
      name = 'S';
    else if (strncmp(*str, "atan", num) == 0)
      name = 'T';
    else if (strncmp(*str, "acos", num) == 0)
      name = 'C';
    *str += (num - 1);
  }
  return name;
}

double s21_OperatorsResuit(char sign, double NumOne,
                                double NumTwo) {
  double result = 0;
  if (sign == '+')
    result = NumOne + NumTwo;
  else if (sign == '-')
    result = NumOne - NumTwo;
  else if (sign == '*')
    result = NumOne * NumTwo;
  else if (sign == '/')
    result = NumOne / NumTwo;
  else if (sign == '^')
    result = powl(NumOne, NumTwo);
  else if (sign == 'm')
    result = fmodl(NumOne, NumTwo);
  return result;
}
