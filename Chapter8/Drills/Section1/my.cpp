#include "./my.h"
#include "../../std_lib_facilities.h.txt"

void print_foo(){
    cout << foo;
}

void print(int i){
    cout << i;
}

void swap_v(int a,int b){ // doesn't swap bc treats x and y as a and b -- local variables
    { int temp; temp = a, a=b; b=temp; }
}

void swap_r(int& a,int& b){
    { int temp; temp = a, a=b; b=temp; }
}

// doesn't work because cannot modify what is passed in as a const argument:

// void swap_cr(const int& a,const int& b){
//     { int temp; temp = a, a=b; b=temp; }
// }