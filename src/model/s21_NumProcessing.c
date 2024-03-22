#include "s21_SmartCalc.h"

void s21_NumberProcessing(char** str, StackSign* ListSign, StackNum* ListNum) {
  if (**str != 'x') *str = s21_NumParser(*str, ListNum);
  if (ListSign->head != NULL && ListNum->head != NULL) {
    if (ListSign->head->sign == '~') {
      ListNum->head->num = ListNum->head->num * -1;
      while (ListSign->head != NULL && ListSign->head->sign == '~')
        s21_DeleteHead_StackSign(ListSign);
    } else if (ListSign->head->sign == '!') {
      while (ListSign->head != NULL && ListSign->head->sign == '!')
        s21_DeleteHead_StackSign(ListSign);
    }
  }
}

char* s21_NumParser(char* str, StackNum* ListNum) {
  s21_IncilizationList_StackNum(ListNum, strtold(str, &str));
  return str - 1;
}
