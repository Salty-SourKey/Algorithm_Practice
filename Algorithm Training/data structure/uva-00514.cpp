#include <iostream>
#include <stack>

using namespace std;

//Stack 1,2,3,4, ... , N 순으로 Push될 때
//Pop으로 만들 수 있는 경우인지 아닌지 판단하는 문제

int main(){
    int N, i, idx;
    int input[1001];
    bool flag;
    while(cin >> N, N){
        stack<int> station;
        while(1){
            i = 1;
            idx = 1;
            flag = true;
            cin >> input[1];
            while(!station.empty()) station.pop();
            if(input[1] == 0) break;
            for(int i = 2; i <= N; i++)
                cin >> input[i];

            while(i <= N){

                if(idx <= N) station.push(idx++);
                else if(input[i] != station.top())
                    break;                

                while(!station.empty() && input[i] == station.top()){
                    station.pop();
                    i++;
                }

            }
            if(!station.empty()) 
                flag = false;

            if(flag) cout << "Yes" << endl;
            else cout << "No" << endl;
        
        }
        cout << endl;
    }
    return 0;
}