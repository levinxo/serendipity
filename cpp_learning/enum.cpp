/**
 * @brief 枚举，第一个定义默认从0开始，后续依次加1
 * @date 2016/10/28
 */

#include <iostream>

enum WEEK {
    W_DAY_1 = 1,
    W_DAY_2,
    W_DAY_3,
    W_DAY_4,
    W_DAY_5,
    W_DAY_6,
    W_DAY_7
};

int main(){
    std::cout << W_DAY_1 << std::endl;
    std::cout << W_DAY_2 << std::endl;
    std::cout << W_DAY_3 << std::endl;
    std::cout << W_DAY_4 << std::endl;
    std::cout << W_DAY_5 << std::endl;
    std::cout << W_DAY_6 << std::endl;
    std::cout << W_DAY_7 << std::endl;

    return 0;
}
