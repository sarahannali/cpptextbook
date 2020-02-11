#include "../cpptextbook/std_lib_facilities.h.txt"

// don't use multiplication operator

int square(int x){
    int ans = x;
    for(int i = 0; i < x-1; i++){
        ans += x; 
    }

    return ans;
}

int main()
{
    cout << square(7);
}