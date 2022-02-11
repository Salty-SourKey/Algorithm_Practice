#include <iostream>
#include <stack>
using namespace std;
stack<int> binary_num;
int main(){
    int ox = 0xFF;
    while(ox){
        binary_num.push(ox%2);
        ox /= 2;
    }
    while(binary_num.size()){
        cout << binary_num.top();
        binary_num.pop();
    }
    return 0;
}