#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class ThePalidrome{
public:
    int find(string s){
        int iter = s.length()-1;
        int result = s.length();
        int i = 0;
        while(i < iter){
            if(s[i] != s[iter]){
                result++;
                i++;
            }
            else{
                iter--;
                i++;
            }
        }
        return result;
    }
};

int main(){
    string s;
    cin >> s;
    ThePalidrome check;
    cout << check.find(s);
    return 0;
}