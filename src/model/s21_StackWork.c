#include "s21_SmartCalc.h"

void s21_IncilizationList_StackSign(StackSign* list, char value) {
  if (list) {
    NodeSign* NewNode = (NodeSign*)malloc(sizeof(NodeSign));
    NewNode->sign = value;
    NewNode->priority = s21_Priority_StackSign(value);
    NewNode->next = list->head;
    list->head = NewNode;
  }
}

void s21_DeleteStruct_StackSign(StackSign* list) {
  if (list) {
    while (list->head != NULL) {
      NodeSign* temp = list->head;
      list->head = list->head->next;
      free(temp);
    }
    free(list);
  }
}

void s21_DeleteHead_StackSign(StackSign* list) {
  if (list)
    if (list->head != NULL) {
      NodeSign* temp = list->head;
      list->head = list->head->next;
      free(temp);
    }
}

int s21_Priority_StackSign(char sign) {
  int priority = 0;
  if (sign == '+' || sign == '-')
    priority = 4;
  else if (sign == '*' || sign == '/' || sign == '%')
    priority = 3;
  else if (strchr("cCsStTlmqna", sign) != NULL)
    priority = 2;
  else if (sign == '^')
    priority = 1;
  else if (sign == '(')
    priority = 0;
  else
    priority = -1;
  return priority;
}

void s21_IncilizationList_StackNum(StackNum* list, double num) {
  if (list) {
    NodeNum* NewNode = (NodeNum*)malloc(sizeof(NodeNum));
    NewNode->num = num;
    NewNode->next = list->head;
    list->head = NewNode;
  }
}

void s21_DeleteStruct_StackNum(StackNum* list) {
  if (list) {
    while (list->head != NULL) {
      NodeNum* temp = list->head;
      list->head = list->head->next;
      free(temp);
    }
    free(list);
  }
}

void s21_DeleteHead_StackNum(StackNum* list) {
  if (list)
    if (list->head != NULL) {
      NodeNum* temp = list->head;
      list->head = list->head->next;
      free(temp);
    }
}
