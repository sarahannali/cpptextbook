#include "./my.h"
#include "./my.cpp"

int foo = 7;

main()
{
    print_foo();
    int i = 99;
    print(i);

    int x = 7;
    int y = 9;
    swap_r (x, y);
    print(x);
    print(y);
    // swap_r (7, 9); for swap_r, need to pass a refernce, won't work
    const int cx = 7;
    const int cy = 9;
    // swap_r (cx, cy); can't swap because constants, won't work
    // swap_r (7.7, 9.9); for swap_r, need to pass a refernce, won't work
    double dx = 7.7;
    double dy = 9.9;
    // swap_r (dx, dy); double won't turn into int
    // swap_r (7.7, 9.9); for swap_r, need to pass a refernce, won't work

}