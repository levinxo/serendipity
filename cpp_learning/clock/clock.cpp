#include <stdio.h>
#include <string>
#include <cstring>
#include "clock.h"
#include "util.h"

using namespace std;

Clock::Clock(){
}

void Clock::setH(int h){
    _h = h;
}

void Clock::setM(int m){
    _m = m;
}

void Clock::setS(int s){
    _s = s;
}

void Clock::fmtClock(char *str){
    //时间format字符串
    char tmp_str[30] = "";
    //小时字符串
    char tmp_h[10];
    //分钟字符串
    char tmp_m[10];
    //秒字符串
    char tmp_s[10];

    //时分秒不满两位时，多加一个0前缀
    char str_zore_prefix[] = "0";
    //时间字符串时分秒的冒号分隔符
    char str_time_colon[]  = ":";

    //将时分秒由int转为字符串
    Util::strval(tmp_h, _h);
    Util::strval(tmp_m, _m);
    Util::strval(tmp_s, _s);

    //开始拼接时间字符串
    if (strlen(tmp_h) < HOUR_MAX_LEN){
        strcat(tmp_str, str_zore_prefix);
    }
    strcat(tmp_str, tmp_h);
    strcat(tmp_str, str_time_colon);

    if (strlen(tmp_m) < MIN_MAX_LEN){
        strcat(tmp_str, str_zore_prefix);
    }
    strcat(tmp_str, tmp_m);
    strcat(tmp_str, str_time_colon);

    if (strlen(tmp_s) < SEC_MAX_LEN){
        strcat(tmp_str, str_zore_prefix);
    }
    strcat(tmp_str, tmp_s);

    strcpy(str, tmp_str);
}

void Clock::display(){
    char str[30];

    this->fmtClock(str);
    printf("%s\n", str);
}

