#include <string>
#include <cstring>
#include <stdio.h>
#include "util.h"

void Util::strval(char *str, int n){
    char s[30];
    sprintf(s, "%d", n);
    strcpy(str, s);
}

int Util::num_length(int n){
    char s[30];
    int length = sprintf(s, "%d", n);
    return length;
}

