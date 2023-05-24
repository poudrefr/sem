#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

size_t s21_strlen(const char* str);

int s21_strcmp(const char* str1, const char* str2);

char* s21_strcpy(char* str1, char* str2);

char* s21_strcat(char* str1, char* str2);

char* s21_strchr(char* str, int symbol);

char* s21_strstr(char* str1, char* str2);

char* s21_strtok(char* str1, char* chop);

#endif  // SRC_S21_STRING_H_
