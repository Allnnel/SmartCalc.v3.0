#ifndef S21_SMARTCALC_H_
#define S21_SMARTCALC_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NodeSign {
  char sign;
  int priority;
  struct NodeSign* next;
} NodeSign;

typedef struct NodeNum {
  double num;
  struct NodeNum* next;
} NodeNum;

typedef struct StackSign {
  NodeSign* head;
} StackSign;
typedef struct StackNum {
  NodeNum* head;
} StackNum;

double* s21_Input(const char* str, double x);
int s21_StringParser(char* str, StackSign* ListSign, StackNum* ListNum,
                     double x);
double s21_Result(StackSign* ListSign, StackNum* ListNum);

// Num Processing
void s21_NumberProcessing(char** str, StackSign* ListSign, StackNum* ListNum);
char* s21_NumParser(char* str, StackNum* ListNum);

// Operator Processing
int s21_OperatorProcessing(char** str, StackSign* ListSign, StackNum* ListNum,
                           int* CountBrackets);
int s21_BraceProcessing(char** str, StackSign* ListSign, StackNum* ListNum,
                        int* CountBrackets);
char s21_SignNegative(StackNum* ListNum, char** str);
void s21_ArithmeticOperators(StackSign* ListSign, StackNum* ListNum);
double s21_TrigonometricOtions(StackSign* ListSign, double OneNum);
char s21_NameOption(char** str);
double s21_OperatorsResuit(char sign, double NumOne,
                                double NumTwo);

// StackSign
void s21_IncilizationList_StackSign(StackSign* list, char value);
void s21_DeleteStruct_StackSign(StackSign* list);
void s21_DeleteHead_StackSign(StackSign* list);
int s21_Priority_StackSign(char sign);

// StackNum
void s21_IncilizationList_StackNum(StackNum* list, double num);
void s21_DeleteStruct_StackNum(StackNum* list);
void s21_DeleteHead_StackNum(StackNum* list);

#endif
