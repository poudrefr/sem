#include <stdlib.h>
#include <stdio.h>
#include "s21_string.h"

size_t s21_strlen(const char* str) {
    size_t lenght = 0;
    for (; *(str+lenght); lenght++) {}
    return lenght;
}

int s21_strcmp(const char* str1, const char* str2) {
  for (; *str1&&*str1 == *str2; str1++, str2++) {}
  int rez = *str1-*str2;
return rez;
}

char* s21_strcpy(char* str1, char* str2) {
  int i = 0;
  while (str2[i] != '\0') {
    str1[i] = str2[i];
    i++;
  }
  str1[i] = '\0';
return str1;
}

char* s21_strcat(char* str1, char* str2) {
  int len1 = s21_strlen(str1),
      len2 = s21_strlen(str2);
  for (int i = len1; i < (len1 + len2); i++)
    str1[i] = str2[i-len1];
  str1[len1 + len2] = '\0';
  return str1;
}

char* s21_strchr(char* str, int symbol) {
  char* serch = NULL;
  char* buffer = str;
  int flag = 0;
  if (buffer != NULL) {
    while ((flag != 1) && (*buffer != '\0')) {
      if (*buffer == symbol) {
        flag = 1;
      } else {
        buffer++;
      }
    if (flag == 1)
      serch = buffer;
    }
  }
  return serch;
}

char* s21_strstr(char* str1, char* str2) {
  int flag = 0;
  char* rez = NULL;
  int tem;
  for (int i = 0; ((str1[i] != '\0') && (flag != 1)); i++) {
    tem = i;
    int j = 0;
    while (str1[i++] == str2[j++]) {
      if (str2[j] == '\0') {
        flag = 1;
      }
    }
    i = tem;
  }
  if (flag == 1)
    rez = str1+tem;
  return rez;
}

char* s21_strtok(char* str1, char* str2) {
  int flag = 0;
  char* rez = NULL;
  int i = 0;
  //int tem;
  for (i = 0; ((str1[i] != '\0') && (flag != 1)); i++) {
    //tem = i;
    int j = 0;
    while (str1[i++] == str2[j++]) {
      if (str2[j] == '\0') {
        flag = 1;
      }
    }
    //i = tem;
  }
  if (flag == 1)
    rez = str1+i;
  return rez;
}
