#include "s21_SmartCalc.h"

double* s21_Input(const char* str, double x) {
    double* res = (double*)malloc(sizeof(double)); 
    double* resultArray = (double*)malloc(2 * sizeof(double));
    int error = 0;

    if (str != NULL && res != NULL && resultArray != NULL) {
        *res = 0;
        char* string = (char*)str;
        StackSign* ListSign = (StackSign*)malloc(sizeof(StackSign));
        ListSign->head = NULL;
        StackNum* ListNum = (StackNum*)malloc(sizeof(StackNum));
        ListNum->head = NULL;

        error = s21_StringParser(string, ListSign, ListNum, x);
        if (error == 0) *res = s21_Result(ListSign, ListNum);
        if (error == 0 && (ListSign->head != NULL)) error = 1;
        s21_DeleteStruct_StackSign(ListSign);
        s21_DeleteStruct_StackNum(ListNum);
    } else {
        error = 1;
    }

    resultArray[0] = *res;
    resultArray[1] = error;

    free(res);
    return resultArray;
}

int s21_StringParser(char* str, StackSign* ListSign, StackNum* ListNum,
                     double x) {
  int error = 0, CountBrackets = 0;
  while (error == 0 && *str != '\0') {
    if (*str == ' ') {
      str++;
      continue;
    }
    if ((*str >= '0' && *str <= '9') || *str == 'x') {
      if (*str == 'x') s21_IncilizationList_StackNum(ListNum, x);
      s21_NumberProcessing(&str, ListSign, ListNum);
    } else if (s21_Priority_StackSign(*str) != -1)
      error = s21_OperatorProcessing(&str, ListSign, ListNum, &CountBrackets);
    else if (*str == ')')
      error = s21_BraceProcessing(&str, ListSign, ListNum, &CountBrackets);

    else
      error = 1;
    str++;
  }
  if (CountBrackets != 0) error = 1;
  return error;
}

double s21_Result(StackSign* ListSign, StackNum* ListNum) {
  double res = 0;
  while (ListSign->head != NULL && ListNum->head != NULL &&
         ListNum->head->next != NULL) {
    s21_ArithmeticOperators(ListSign, ListNum);
  }
  if (ListNum->head != NULL && ListSign->head != NULL &&
      ListNum->head->next == NULL && ListSign->head->priority == 2) {
    double result = s21_TrigonometricOtions(ListSign, ListNum->head->num);
    s21_DeleteHead_StackNum(ListNum);
    s21_IncilizationList_StackNum(ListNum, result);
    s21_DeleteHead_StackSign(ListSign);
  }
  if (ListNum->head != NULL && ListNum->head->next == NULL &&
      ListSign->head == NULL)
    res = ListNum->head->num;
  return res;
}
