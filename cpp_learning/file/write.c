#include <stdio.h>
#include <math.h>

int main(){
    FILE *fd;
    char filename[] = "abc.txt";
    char system_cmd[30];
    int n;

    fd = fopen(filename, "a");

    for (n=0; n<10000; n++){
        fprintf(fd, "%s\n", "abcdefghijklmn");
        fflush(fd);
        //sleep(1);
    }
    fclose(fd);

    sprintf(system_cmd, "wc -l %s", filename);
    system(system_cmd);
    return 0;
}
