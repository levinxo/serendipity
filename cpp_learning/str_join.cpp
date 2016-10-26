/**
 * @brief 主要练习一下拼接字符串和内存分配
 * @date 2016/10/26
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *str_join(char *str1, char *str2){
    //cpp需要手动地转一下malloc的返回类型
    //注意这里是strlen而不是sizeof
    char *result = (char*) malloc(strlen(str1) + strlen(str2) + 1);
    if (result == NULL){
        exit(1);
    }
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

int main(){
    char str1[] = "abcdef";
    char str2[] = "-zxy";

    char *ret = str_join(str1, str2);
    printf("%s\n", ret);

    return 0;
}
