#include <iostream>
#include <cstdlib>
#include "fact.h"

#define CAL_FUNC(num) \
do { \
    ret = fact_iteration(num); \
} while (0)

int main (int argc, char *argv[]){
    int num(-1);
    long ret;

    if (argc > 1){
        num = atoi(argv[1]);
    }

    if (num >= 1){
        CAL_FUNC(num);
        std::cout << num << "! = " << ret << std::endl;
    } else {
        std::cerr << "Invalid num! Usage: " << argv[0] << " [num]" << std::endl;
    }
    return 0;
}

