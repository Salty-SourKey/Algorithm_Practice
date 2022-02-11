#include <iostream>
using namespace std;
int main(){
    int input,temp=0, min=0;
    cin >> input;
    temp = 1000-input;
    min += temp/500;
    temp = temp%500;
    min += temp/100;
    temp = temp%100;
    min += temp/50;
    temp = temp%50;
    min += temp/10;
    temp = temp%10;
    min += temp/5;
    temp = temp%5;
    min += temp;
    cout << min;
    return 0;
}