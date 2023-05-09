#include "s21_grep_lib.h"

int main(int argc, char* argv[]) {
  size_t size_buffer_tmp = 256;
  char* buffer_tmp = (char*)malloc(size_buffer_tmp * sizeof(char));
  int file_name[argc], size_buffer, cnt, cnt_s, buffer_lenght = 0, len_line = 0;
  char flag[6] = "";
  int fl_cnt = check(argc, argv, flag, file_name);
  for (int i = 0; i < fl_cnt; i++) {
    cnt = 0;
    cnt_s = 0;
    FILE* cat_file = fopen(argv[file_name[i]], "r");
    if (cat_file != NULL) {
      while ((len_line = getline(&buffer_tmp, &size_buffer_tmp, cat_file)) !=
             -1) {
        size_buffer = len_line * 2;
        char buffer[size_buffer];
        buffer_lenght = cat_etv(buffer, flag, buffer_tmp, len_line);
        cat_sbn(buffer, flag, &cnt_s, &cnt, buffer_lenght);
      }
    }
    fclose(cat_file);
  }
  if (buffer_tmp != 0) free(buffer_tmp);
  return 0;
}
