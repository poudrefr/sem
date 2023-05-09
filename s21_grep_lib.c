#include "s21_grep_lib.h"

int check(int main_argc, char* main_argv[], char flag[], int file_name[]) {
  char flags_short[9] = "eivclnhsfo";
  int cnt = 0, file_list_started = 0;
  for (int i = 1; i < main_argc; i++) {
    if ((main_argv[i][0] == '-')) && (file_list_started == 0)) {
      for (int j = 1; main_argv[i][j] != '\0'; j++) {
        if (!strchr(flags_short, main_argv[i][j])) {
          perror("Invalid Flag");
          exit(1);
        }
      }
      check_flags(main_argv[i], flag);
    } else if (main_argv[i][0] != '-') {
      FILE* check_file_name = fopen(argv[i], "r")
      if (check_file_name == NULL) {
        pattern[cnt_p] = i;
        cnt_p++;
      } else if (check_file_name != NULL) {
        file_list_started = 1;
        file_name[cnt_f] = i;
        cnt_f++;
      }
      fclose(check_file_name);
    }
    if ((file_list_starter == 1) && (i < argc))
      file_list_starter = 0;
      strcat(flag, "0");
      point[cnt_i] = i;
      cnt_i++
  }
  return cnt;
}

void check_flags(char* main_argv, char flag[]) {
  if (strchr(main_argv, 's')) {
    if (!strchr(flag, 's')) strcat(flag, "s");
  }
  if (strchr(main_argv, 'b')) {
    if (!strchr(flag, 'b')) strcat(flag, "b");
  } else if (strchr(main_argv, 'n')) {
    if (!(strchr(flag, 'n') || strchr(flag, 'b'))) strcat(flag, "n");
  }
  if (strchr(main_argv, 'e')) {
    if (!strchr(flag, 'e')) strcat(flag, "e");
  } else if (strchr(main_argv, 'E')) {
    if (!(strchr(flag, 'E') || strchr(flag, 'e'))) strcat(flag, "E");
  }
  if (strchr(main_argv, 't')) {
    if (!strchr(flag, 't')) strcat(flag, "t");
  } else if (strchr(main_argv, 'T')) {
    if (!(strchr(flag, 'T') || strchr(flag, 't'))) strcat(flag, "T");
  }
  if (strchr(main_argv, 'v')) {
    if (!strchr(flag, 'v')) strcat(flag, "v");
  } else if (strchr(main_argv, 'v')) {
    if (!strchr(flag, 'v')) strcat(flag, "v");
  }
}

void check_flags_long(char* main_argv, char flag[]) {
  if (strstr(main_argv, "--squeeze-blank")) {
    if (!strchr(flag, 's')) strcat(flag, "s");
  } else if (strstr(main_argv, "--number-nonblank")) {
    if (!strchr(flag, 'b')) strcat(flag, "b");
  } else if (strstr(main_argv, "--number")) {
    if (!(strchr(flag, 'n') || strchr(flag, 'b'))) strcat(flag, "n");
  }
}

int cat_etv(char buffer[], char flag[], char* buffer_tmp, int len_line) {
  int j = 0;
  if (strchr(flag, 'e') || strchr(flag, 't') || strchr(flag, 'T') ||
      strchr(flag, 'v')) {
    for (int i = 0; i < len_line; i++) {
      if (buffer_tmp[i] == 127) {
        buffer[j] = 94;
        j++;
        buffer[j] = buffer_tmp[i] - 64;
        j++;
      } else if (buffer_tmp[i] < 32 && buffer_tmp[i] >= 0 &&
                 buffer_tmp[i] != 9 && buffer_tmp[i] != 10 &&
                 !strchr(flag, 'T')) {
        buffer[j] = 94;
        j++;
        buffer[j] = buffer_tmp[i] + 64;
        j++;
      } else if (buffer_tmp[i] == 9 &&
                 (strchr(flag, 't') || strchr(flag, 'T'))) {
        buffer[j] = 94;
        j++;
        buffer[j] = buffer_tmp[i] + 64;
        j++;
      } else {
        buffer[j] = buffer_tmp[i];
        j++;
      }
    }
  } else {
    for (int i = 0; i < len_line; i++) {
      buffer[j] = buffer_tmp[i];
      j++;
    }
  }
  return j - 1;
}

void cat_sbn(char buffer[], char flag[], int* cnt_s, int* cnt,
             int buffer_lenght) {
  if (strchr(flag, 's')) {
    if (buffer_lenght != 0) {
      *cnt_s = 0;
    } else {
      *cnt_s = *cnt_s + 1;
    }
  }
  if (strchr(flag, 'b')) {
    if ((buffer[0] != '\0' && buffer[0] != '\n') || (buffer_lenght > 2)) {
      *cnt = *cnt + 1;
      printf("%6d\t", *cnt);
      output(buffer_lenght, buffer, flag);
    } else if (*cnt_s < 2) {
      output(buffer_lenght, buffer, flag);
    }
  } else if (strchr(flag, 'n')) {
    if (*cnt_s < 2) {
      *cnt = *cnt + 1;
      printf("%6d\t", *cnt);
      output(buffer_lenght, buffer, flag);
    }
  }
  if (!strchr(flag, 'n') && !strchr(flag, 'b') && *cnt_s < 2) {
    output(buffer_lenght, buffer, flag);
  }
}

void output(int buffer_lenght, char buffer[], char flag[]) {
  if (strchr(flag, 'e') || strchr(flag, 'E')) {
    if (buffer[buffer_lenght] == '\n') {
      buffer_lenght = buffer_lenght + 1;
      buffer[buffer_lenght - 1] = '$';
      buffer[buffer_lenght] = '\n';
    }
  }
  for (int i = 0; i <= buffer_lenght; i++) {
    printf("%c", buffer[i]);
  }
}
