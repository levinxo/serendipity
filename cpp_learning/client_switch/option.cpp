/**
 * @brief Simple option with parameter and switch statement
 */

#include <iostream>
#include <cstdlib>

extern int option;

int main(int argc, char *argv[]){
    int option(-1);

    if (argc > 1){
        option = atoi(argv[1]);
    }

    switch (option){
        case 1:
            std::cout << "Hello!" << std::endl;
            break;
        case 2:
            std::cout << "Bye!" << std::endl;
            break;
        default:
            std::cerr << "Usage: " << argv[0] << " [1|2]" << std::endl;
    }
    return 0;
}

