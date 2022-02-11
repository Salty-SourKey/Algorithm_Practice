#include <iostream>
#include <string>

using namespace std;

string bool_op(string func){
    int a = func[1] - 48;
    int b = func[3] - 48;

    if(func[2] == '|')
        return to_string(a|b); 
    else if(func[2] == '&')
        return to_string(a&b); 
    else if(func[2] == '^')
        return to_string(a^b);
}

int calc(string func){
    int idx;
    if(func == "1" || func == "0") return func[0] - 48;
    for(int i = 0; i < func.length(); i++){
        if(func[i] == '(') idx = i;
        else if(func[i] == ')'){
            func.replace(func.find(func.substr(idx, 5)), 5, bool_op(func.substr(idx,5)));
            return calc(func);
        }
    }
}

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        string func_1, func_2;
        int ans;
        cin >> func_1;
        func_2 = func_1;

        for(int i = 0; i < func_1.length(); i++){
            if(func_1[i] == 'x'){
                func_1[i] = '0';
                func_2[i] = '1';
            }
            else if(func_1[i] == 'X'){
                func_1[i] = '1';
                func_2[i] = '0';
            }
        }

        if(calc(func_1) != calc(func_2)) ans = 1;
        else ans = 0;

        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}