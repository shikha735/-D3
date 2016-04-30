// Reversing a string using a stack

#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack> // stack from standard template library (STL)
using namespace std;

void reverseString(char *str, int len){
    stack<char> S;
    for(int i=0;i<len;i++){
        S.push(str[i]);
    }

    for(int i=0;i<len;i++){
        str[i] = S.top();
        S.pop();
    }
}

int main(){
    char str[20];
    cout << "Enter a string: ";
    gets(str);
    reverseString(str, strlen(str));
    puts(str);
    return 0;
}
