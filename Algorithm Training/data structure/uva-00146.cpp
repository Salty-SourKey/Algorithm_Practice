#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string input;
    while(cin >> input){
        if(input == "#") break;
        //다음 순열이 존재한다면 다음 순열로 변경 후 return true
        if(next_permutation(input.begin(),input.end()))
            cout << input << endl;
        
        //마지막 순열이라면 return false
        else
            cout << "No Successor" << endl;
    }
    return 0;
}