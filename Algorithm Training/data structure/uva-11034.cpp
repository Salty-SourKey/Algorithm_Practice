#include <iostream>
#include <queue>
#include <string>


using namespace std;

int main(){
    int c, ans, num, limit, input, cur_limit;
    string bank;
    queue<int> left;
    queue<int> right;
    bool isLeft;
    cin >> c;
    
    while(c){
        cin >> limit >> num;
        for(int i = 0; i < num; i++){
            cin >> input >> bank;
            if(bank == "left") left.push(input);
            else right.push(input);
        }
        isLeft = true;
        ans = 0;
        while(!left.empty() || !right.empty()){            
            cur_limit = limit * 100;
            if(isLeft){
                while(!left.empty() && cur_limit - left.front() >= 0){
                    cur_limit -= left.front();
                    left.pop();
                }
            }
            else{
                while(!right.empty() && cur_limit - right.front() >= 0){
                    cur_limit -= right.front();
                    right.pop();
                }
            }
            isLeft = !isLeft;
            ans++;
        }
        cout << ans << endl;
        c--;
    }
    return 0;
}