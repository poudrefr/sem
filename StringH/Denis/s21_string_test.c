#include <stdlib.h>
#include <stdio.h>
#include "s21_string.h"

void s21_strstr_test(char* test1, char* test2, char* ansr);
void s21_strchr_test(char* test, int symbl, char* ansr);
void s21_strcat_test(char* test1, char* test2);
void s21_strcpy_test(char* test1, char* test2);
void s21_strcmp_test(char* test1, char* test2, int anse);
void s21_strlen_test(char* test, size_t len);
void output(char* string);

int main() {
  char test_1[50] = "";
  char test_2[50] = "1 1%d '1' 1 ";
  char test_2_srch[50] = " 1%d '1' 1 ";
  char test_3[50] = ".!@#\0$^&";
  char test_4[50] = "#¶SCHOOL21æ#(1)";
  char test_5[50] = "1234567890";
  char test_5_srch[50] = "0";
  char test_6[50] = "123456789";
  char test_6_srch[50] = "9";
  char test_7[50] = "American Standard Code'\n' for Information Interch";
  char test_7_srch[50] = "\n' for Information Interch";
  char test_8[50] = "AmerIcan";

  #ifdef LENGHT
    s21_strlen_test(test_1, 0);
    s21_strlen_test(test_2, 12);
    s21_strlen_test(test_3, 9);
    s21_strlen_test(test_4, 15);
    s21_strlen_test(test_7, 50);
  #endif
  #ifdef CHECK
    s21_strcmp_test(test_2, test_2, 0);
    s21_strcmp_test(test_3, test_4, 1);
    s21_strcmp_test(test_1, test_1, 0);
    s21_strcmp_test(test_6, test_5, -1);
    s21_strcmp_test(test_7, test_8, 1);
  #endif
  #ifdef COPY
    s21_strcpy_test(test_1, test_2);
    s21_strcpy_test(test_2, test_3);
    s21_strcpy_test(test_4, test_4);
    s21_strcpy_test(test_6, test_5);
    s21_strcpy_test(test_7, test_8);
  #endif
  #ifdef CATER
    s21_strcat_test(test_1, test_2);
    s21_strcat_test(test_2, test_3);
    s21_strcat_test(test_4, test_4);
    s21_strcat_test(test_6, test_5);
    s21_strcat_test(test_7, test_8);
  #endif
  #ifdef SERCH
    s21_strchr_test(test_5, (int)'0', test_5_srch);
    s21_strchr_test(test_7, (int)'\n', test_7_srch);
    s21_strchr_test(test_6, (int)'9', test_6_srch);
    s21_strchr_test(test_2, (int)' ', test_2_srch);
    s21_strchr_test(test_1, (int)'@', 0);
  #endif
  #ifdef SERSTR
    s21_strstr_test(test_5, "0", test_5_srch);
    s21_strstr_test(test_7, "\n' ", test_7_srch);
    s21_strstr_test(test_6, "y", 0);
    s21_strstr_test(test_2, " 1%", test_2_srch);
    s21_strstr_test(test_1, "1", 0);
  #endif
  #ifdef SRTCHOP
    s21_strstr_test(test_5, "0", test_5_srch);
    s21_strstr_test(test_7, "\n' ", test_7_srch);
    s21_strstr_test(test_6, "y", 0);
    s21_strstr_test(test_2, " 1%", test_2_srch);
    s21_strstr_test(test_1, "1", 0);
  #endif
  return 0;
}

void s21_strlen_test(char* test, size_t len) {
  output(test);
  printf(" %ld | ", s21_strlen(test));
  if (len == s21_strlen(test))
    printf("SUCCESS");
  else
    printf("FAIL");
  printf("\n");
}

void s21_strcmp_test(char* test1, char* test2, int anse) {
  output(test1);
  output(test2);
  printf(" %d | ", s21_strcmp(test1, test2));
  if (anse == 1) {
    if (0 < s21_strcmp(test1, test2))
      printf("SUCCESS");
    else
      printf("FAIL");
  } else {
    if (anse == 0) {
      if (0 == s21_strcmp(test1, test2))
        printf("SUCCESS");
      else
        printf("FAIL");
      } else {
        if (anse == -1) {
          if (0 > s21_strcmp(test1, test2))
            printf("SUCCESS");
          else
            printf("FAIL");
        }
    }
  }
  printf("\n");
}

void s21_strcpy_test(char* test1, char* test2) {
  printf("%s | %s | ", test1, test2);
  printf("%s | ", s21_strcpy(test1, test2));
  if (s21_strcmp(test1, s21_strcpy(test1, test2)) == 0)
    printf("SUCCESS");
  else
    printf("FAIL");
  printf("\n");
}

void s21_strcat_test(char* test1, char* test2) {
  int len = s21_strlen(test1);
  printf("%s | %s | ", test1, test2);
  printf("%s | ", s21_strcat(test1, test2));
  if (s21_strlen(test1) == (len+s21_strlen(test2)))
    printf("SUCCESS");
  else
    printf("FAIL");
  printf("\n");
}

void s21_strchr_test(char* test, int symbl, char* ansr) {
  char* rez = s21_strchr(test, symbl);
  printf("%s | %c | ", test, symbl);
  if (rez == NULL) {
    printf("NULL | ");
    if ( ansr == 0)
      printf("SUCCESS");
    else
      printf("FAIL");
  } else {
    output(rez);
    if (s21_strcmp(rez, ansr) == 0)
      printf("SUCCESS");
    else
      printf("FAIL");
  }
  printf("\n");
}

void s21_strstr_test(char* test1, char* test2, char* ansr) {
  char* rez = s21_strstr(test1, test2);
  printf("%s | %s | ", test1, test2);
  if (rez == NULL) {
    printf("NULL | ");
    if ( ansr == 0)
      printf("SUCCESS");
    else
      printf("FAIL");
  } else {
    output(rez);
    if (s21_strcmp(rez, ansr) == 0)
      printf("SUCCESS");
    else
      printf("FAIL");
  }
  printf("\n");
}

void s21_strtok_test(char* test1, char* test2, char* ansr) {
  char* rez = s21_strtok(test1, test2);
  printf("%s | %s | ", test1, test2);
  if (rez == NULL) {
    printf("NULL | ");
    if ( ansr == 0)
      printf("SUCCESS");
    else
      printf("FAIL");
  } else {
    output(rez);
    if (s21_strcmp(rez, ansr) == 0)
      printf("SUCCESS");
    else
      printf("FAIL");
  }
  printf("\n");
}

void output(char* string) {
  for (size_t i = 0; i < s21_strlen(string); i++)
    printf("%c", string[i]);
  printf(" | ");
}
