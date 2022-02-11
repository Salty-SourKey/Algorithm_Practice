#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;
string word;
string goal;

void simulation(string stack, string cur, string op, int idx){

    if(cur.length() == word.length() && goal == cur){
        cout << op << endl;
        return;
    }
    string temp;
    if(idx <= word.length()){
        //PUSH
        temp = stack + word[idx];
        simulation(temp, cur, op + " i", idx + 1);
    }
    if(stack.length() > 0 && stack[stack.size()-1] == goal[cur.length()]){
        //POP
        temp = stack.substr(0, stack.size()-1);
        simulation(temp, cur + stack.substr(stack.size()-1), op + " o", idx);
    }

    
}

int main(){
    string temp;
    while(cin >> word >> goal){
        temp = "";
        cout << "[" << endl;
        simulation(word.substr(0,1), temp, "i", 1);
        cout << "]" << endl;
    }
}