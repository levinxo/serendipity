/**
 * @brief struct和union的区别
 * @date 2016/10/28
 */

#include <iostream>

using namespace std;

union U {
    char c;
    int i;
    double d;
};

struct S {
    char c;
    int i;
    double d;
};

int main(){
    cout << " U's size = " << sizeof(U) << endl;
    cout << " S's size = " << sizeof(S) << endl;
    cout << " 其中 " << sizeof(char) << " + " << sizeof(int) << " + " << sizeof(double) << " = " << sizeof(char) + sizeof(int) + sizeof(double) << endl;
    cout << " ----------------------- " << endl;

    S s;
    s.c = 'A';
    cout << " 1 s.c = " << s.c << endl;
    s.d = 23.2132;
    cout << " 1 s.d = " << s.d << endl;
    cout << " 2 s.c = " << s.c << endl;
    cout << " ----------------------- " << endl;

    U u;
    u.c = 'A';
    cout << " 1 u.c = " << u.c << endl;

    u.i = 23322;
    cout << " 1 u.i = " << u.i << endl;

    u.d = 23.2132;
    cout << " 1 u.d = " << u.d << endl;
    cout << " 2 u.c = " << u.c << endl;
    cout << " 2 u.i = " << u.i << endl;
    return 0;
}
