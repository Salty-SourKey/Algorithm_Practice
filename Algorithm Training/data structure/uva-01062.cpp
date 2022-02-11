#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;
//Stack과 Greedy 문제
int main(){
    string input;
    int idx, num = 1;
    vector<stack<char>> ship;
    while(cin >> input, input != "end"){
        for(int i = 0; i < input.length(); i++){
            idx = 0;
            while(idx < ship.size()){
                if(ship[idx].top() == input[i])
                    break;
                else if(input[i] < ship[idx].top()){
                    ship[idx].push(input[i]);
                    break;
                }
                idx++;
            }
            stack<char> temp;
            temp.push(input[i]);
            if(idx == ship.size()) ship.push_back(temp);   
        }
        cout << "Case " << num++ << ": " << ship.size() << endl;
        ship.clear();
    }
    return 0;
}