/*
 * 各种样式的typedef和struct，其区别一览无余
 */

struct point {
    int x;
    int y;
};

struct point1 {
    int x;
    int y;
} p1;

struct {
    int x;
    int y;
} p2;

typedef struct square {
    int width;
    int high;
} _square;

typedef struct {
    int width;
    int high;
} _square2;

struct point p3;

struct square s1;

_square s2;

_square2 s3;

int main(){
    return 0;
}
