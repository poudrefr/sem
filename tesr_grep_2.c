#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char flag[10] = ""; 
    char bffr[2048] = ""; 
    char keyword[256] = ""; 
    char file_name[256] = ""; 
    //int argv_lnth = strlen(argv);
    for (int i = 1; i < argc; i++ ) { 
        if (argv[i][0] == '-') {
            strcat(flag, argv[i]);
            strcat(flag, " ");
            printf("[%s]\n", flag);
        } else if (strchr(argv[i], '.')) {
            strcat(file_name, argv[i]);
            printf("{%s}\n", file_name);
        } else {
            strcat(keyword, argv[i]);
            strcat(keyword, " ");
            printf("|%s|\n", keyword);
        }   
    }   
        int cnt = 1;
        FILE* grep_file = fopen(file_name, "r");
        while (!feof(grep_file)) {
            fgets(bffr, 2048, grep_file);
            if (!strcmp(flag, "")) {
                printf("%s", bffr);
            //cnt++;
            } else {
                //printf("test");
                if (strstr(bffr, keyword))
                printf("%d%s", cnt, bffr);
                //cnt++;
            }
            cnt++;
        }
        fclose(grep_file);
    return 0;
}

