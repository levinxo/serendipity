#include "clock.h"

int main(int argc, char *argv[]){
    Clock ck;

    ck.setH(10);
    ck.setM(1);
    ck.setS(2);

    ck.display();

    return 0;
}

