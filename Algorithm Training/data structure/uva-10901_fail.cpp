#include <iostream>
#include <queue>
#include <string>

using namespace std;

int ans[10001];

int main(){
    int c, n, t, m, input;
    int cur_time;
    string bank;
    bool isLeft;
    queue<pair<int, int>> left, right;
    cin >> c;

    while(c--){
        cin >> n >> t >> m;
        for(int i = 0; i < m; i++){
            cin >> input >> bank;
            if(bank == "left") left.push({i, input});
            else right.push({i, input});
        }
        isLeft = true;
        cur_time = 0;
        while(!(left.empty() && right.empty())){
            if(isLeft && !left.empty()){
                if(left.front().second > cur_time){
                    if(left.front().second <= right.front().second){
                        cur_time = left.front().second;
                        ans[left.front().first] = cur_time + t;
                        left.pop();
                    }
                    else
                        cur_time = right.front().second;
                }
                else{
                    for(int i = 0; i < n; i++){
                        if(!left.empty() && left.front().second <= cur_time){
                            ans[left.front().first] = cur_time + t;
                            left.pop();
                        }
                        else break;
                    }
                }
            }
            else if(!isLeft && !right.empty()){
                if(right.front().second > cur_time){
                    if(right.front().second <= left.front().second){
                        cur_time = right.front().second;
                        ans[right.front().first] = cur_time + t;
                        right.pop();
                    }
                    else 
                        cur_time = left.front().second;
                }
                else{
                    for(int i = 0; i < n; i++){
                        if(!right.empty() && right.front().second <= cur_time){
                            ans[right.front().first] = cur_time + t;
                            right.pop();
                        }
                        else break;
                    }
                }
            }
            isLeft = !isLeft;
            cur_time+=t;   
        }

        for(int i = 0; i < m; i++)
            cout << ans[i] << endl;
        cout << endl;
    }
    return 0;
}