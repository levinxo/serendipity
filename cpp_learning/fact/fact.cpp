#include "fact.h"

/**
 * @brief 阶乘迭代
 */
long fact_iteration(long num){
    long ret = 1;
    while (num > 1){
        ret *= num--;
    }
    return ret;
}

/**
 * @brief 阶乘递归
 */
long fact_recursion(long num){
    if (1==num){
        return 1;
    }
    return num*fact_recursion(num-1);
}

