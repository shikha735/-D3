// C++ program to toggle bits - Bit manipulation
#include <iostream>
using namespace std;

int toggleBits(int n){
    if(n == 0) return 1;
    int nextSetBit = 1, lastBit, solution = 0;
    while(n != 0){
        lastBit = n&1;
        if(lastBit == 0){
            solution |= nextSetBit;
        }
        nextSetBit <<= 1;
        n = unsigned(n) >> 1; // ensures that the algo works for -ve no.s also
    }
    return solution;
}

int main(){
    int input;
    cin >> input;
    cout << toggleBits(input);
    return 0;
}
