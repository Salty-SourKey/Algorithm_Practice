/*

*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


int main(){
    string str;
    vector<string> ans;
    ifstream file("1-3-1_input.txt");
    int v;
    int c = 1;
    while(getline(file, str)){
        v = 0;
        for(int i = 0; i < str.length(); i++){
            if(str[i] != ' '){
                v += str[i] - '0';
            }
        }
        if(c++ > 1) cout << endl;
        cout << v;
    }
    return 0;
}
