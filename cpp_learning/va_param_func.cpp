/**
 * @brief 可变参数函数
 * @date 2016-10-29
 */

#include <stdarg.h>
#include <iostream>

int sum(int count, ...){
    int result = 0;

    //此变量访问可变参数列表中的参数，先初始化它
    va_list p_list;

    //初始化可变参数列表变量
    //va_start根据...前第一个参数来判断可变参数列表的起始位置
    va_start(p_list, count);
    while (count--){
        //开始获取可变参数列表中的参数值，type为参数值的类型
        //va_arg调用完毕后将可变参数列表变量指向下一个参数
        result += va_arg(p_list, int);
    }
    //关闭对可变参数列表的访问
    va_end(p_list);

    return result;
}

int main(int argc, char* argv[]){
    std::cout << sum(5, 1, 2, 3, 4, 5) << std::endl;     //输出15
}
