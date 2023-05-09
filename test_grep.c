#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char bffr[2048];
    if (argc < 5) {
    fgets(bffr, 2048, stdin);
    printf("{%s}\n", bffr);

    }
    int cnt = 1;
    char grep_nmb[7] = "-n";
    for(int j = 0; j < argc; j++) {
        printf("|%s|\n", argv[j]);
    }

    for (int i = 3; i < argc; i++) {
        FILE* grep_file = fopen(argv[3], "r");
        while (!feof(grep_file)) {
            fgets(bffr, 2048, grep_file);
            if (strcmp(argv[1], grep_nmb)) {
                printf("%s", bffr);
            //cnt++;
            } else { 
                if (strstr(bffr, argv[2]))
                printf("%d%s", cnt, bffr);
                //cnt++;
            }   
            cnt++;
        }   
    fclose(grep_file);
    }   
  return 0;
}

