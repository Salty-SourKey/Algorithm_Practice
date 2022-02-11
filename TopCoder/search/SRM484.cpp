#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class NumberMagicEasy{
public:
    int theNumber(string answer){
        string c[] = {"YYYYYYYYNNNNNNNN",
                      "YYYYNNNNYYYYNNNN",
                      "YYNNYYNNYYNNYYNN",
                      "YNYNYNYNYNYNYNYN"};
        for(int i = 0; i < 16; ++i){
            string temp = "";
            for(int j = 0; j < 4; ++j) temp += c[j][i];
            if(answer == temp) return i+1;
        }
    }
};

int main(){
    string answer;
    NumberMagicEasy find_num;
    cin >> answer;
    cout << find_num.theNumber(answer);
    return 0;
}