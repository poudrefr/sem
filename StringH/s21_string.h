#ifndef S21_STRING_H
#define S21_STRING_H
#define s21_NULL ((void*)0)

#include <stdio.h>
#include <stdlib.h>

typedef long unsigned s21_size_t;

void* s21_memchr(const void* String, int Ch, s21_size_t N);
int s21_memcmp(const void* str1, const void* str2, s21_size_t N);
void* s21_memcpy(void* Dest, const void* Src, s21_size_t N);
char* s21_strncat(char* Dest, const char* Src, s21_size_t N);
int s21_strncmp(const char* StringOne, const char* StringTwo, s21_size_t N);
s21_size_t s21_strcspn(const char* StringOne, const char* StringTwo);
s21_size_t s21_strlen(const char* String);
char* s21_strpbrk(const char* StringOne, const char* StringTwo);
char* s21_strstr(const char* StringOne, const char* StringTwo);
char* s21_strchr(const void* String, int Ch);
char* s21_strrchr(const void* String, int Ch);
void* s21_memset(void* Dest, int NumC, size_t NumN);
