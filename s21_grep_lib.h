#ifndef S21_CAT_LIB_H
#define S21_CAT_LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check(int main_argc, char* main_argv[], char flag[], int file_name[]);
void check_flags(char* main_argv, char flag[]);
void check_flags_long(char* main_argv, char flag[]);
int cat_etv(char buffer[], char flag[], char* buffer_tmp, int len_line);
void cat_sbn(char buffer[], char flag[], int* cnt_s, int* cnt,
             int buffer_lenght);
void output(int buffer_lenght, char buffer[], char flag[]);

#endif
