#include "s21_string.h"


void* s21_memchr(const void* String, int ch, size_t n) {
  const char* vStringTmp;
  char vCh = (char)ch;
  for (vStringTmp = (const char*)String; n > 0; n--, vStringTmp++) {
    if (*vStringTmp == vCh) return (void*)vStringTmp;
  }
  return 0;
}

int s21_memcmp(const void* str1, const void* str2, size_t n) {
const char* vStringOne = (const char*)str1;
const char* vStringTwo = (const char*)str2;
int vOut = 0;
  if (str1 != str2) {
    while ((n > 0) && (vOut == 0)) {
      if (*vStringOne != *vStringTwo) {
          vOut = *(vStringOne) - *(vStringTwo);
      }
      n--;
      vStringOne++;
      vStringTwo++;
    }
  }
  return vOut;
}

void* s21_memcpy(void* dest, const void* src, size_t n) {
  char *vDest = (char *) dest;
  char *vSrc = (char *) src;
  while (n > 0 ) {
    *vDest = *vSrc;
    n--;
    vDest++;
    vSrc++;
  }
  return dest;
}



char* s21_strncat(char* vStringDest, const char* vStringSrc, size_t n) {
  int vLen = 0;
  int vLenSrc = 0;
  for (; *(vStringDest + vLen); vLen++)
    ;
  while (n > 0) {
    vStringDest[vLen] = vStringSrc[vLenSrc];
    n--;
    vLen++;
    vLenSrc++;
  }
  return 0;
}

//int s21_strchr(const char* string, const int ch) {
  int vResult = 0, vCnt = 0;
  while((vCnt < s21_strlen(string)) && vResult == 0) {
    int x = string[cnt];
    if (x == ch) vResult = vCnt + 1;
    vCnt++;
  }
  return vResult;
}

int s21_strncmp(char* str1, char* str2, size_t len_n) {
  for (size_t cnt_n = 1; (*str1 && *str1 == *str2) && cnt_n < len_n; str1++, str2++, cnt_n++) {}
  int rez = *str1-*str2;
return rez;
}



size_t s21_strcspn(const char* str1, const char* str2) {
  int vOut = 0;
  int cnt_one = 0, cnt_two = 0;
  while ((str1[cnt_one] != '\0') && (vOut == 0)) {
    cnt_two = 0;
    while ((str2[cnt_two] != '\0') && (vOut == 0)) {
      if (str1[cnt_one] == str2[cnt_two]) vOut = cnt_one;
      cnt_two++;
    }
    cnt_one++;
  }
  return (size_t)vOut;
}



size_t s21_strlen(const char* str) {
  size_t len = 0;
  for (; *(str + len); len++)
    ;
  return len;
}

char* s21_strpbrk(const char *str1, const char *str2) {
  int vCntOne = 0, vCntTwo = 0, vCntOut = 0;
  char* vStringOut;
  while ((str1[vCntOne] != '\0') && (vCntOut == 0)) {
    vCntTwo = 0;
    while ((str2[vCntTwo] != '\0') && (vCntOut == 0)) {
      if (str1[vCntOne] == str2[vCntTwo]) vCntOut = vCntOne;
      vCntTwo++;
    }
    vCntOne++;
  }
  vStringOut = (char*)str1 + vCntOut;
  return vStringOut;
}



char* s21_strstr(char* string1, char* string2) {
  int result = 0;
  int cnt = 0;
  char* address = 0;
  while ((string1[cnt] != '\0') && result == 0) {
    if (string1[cnt] == string2[0]) {
      for (int j = 0; j < s21_strlen(string2); j++) {
        if (string1[cnt + j] == string2[j]) {
          result++;
        } else
          result = 0;
      }
    }
    cnt++;
  }
  if (result != 0) address = &string1[cnt - 1];
  return address;
}
int s21_strcmp(char* string1, char* string2) {
    for (; *string1 && string1 == string2; string1++, string2++)
        ;
    return *string1 - *string2;
}

void s21_strcpy(char* string1, const char* string2) {
    for (int i = 0; (string1[i] = string2[i]) != '\0'; i++)
        ;
}

void s21_strcat(char* string2, const char* string1) {
    int len = 0;
    for (; *(string2 + len); len++)
        ;
    int j = len;
    for (int i = 0; (string2[j] = string1[i]) != '\0'; i++, j++)
        ;
}


