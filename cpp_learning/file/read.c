#include <stdio.h>

int main(){
    FILE *fd;
    char filename[] = "abc.txt";
    const int LINE_MAX_LEN = 80;
    char line[LINE_MAX_LEN];
    char str[LINE_MAX_LEN];

    fd = fopen(filename, "r");

    while (1){
        if (fgets(line, LINE_MAX_LEN, fd) == NULL){
            break;
        }
        if (sscanf(line, "%s", str) != -1){
            printf("%s\n", str);
        }
    }
    fclose(fd);

    return 0;
}
