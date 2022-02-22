#include <iostream>
#include <queue>
using namespace std;

int N;
priority_queue<int, vector<int>, greater<int>> bigger;
priority_queue<int, vector<int>, less<int>> smaller;

int main(){   
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> N;
    int mid, input;
    for(int i = 0; i < N; i++){
        if(i == 0)
            cin >> mid;
        else{
            cin >> input;
            if(mid <= input){
                if(bigger.size() > smaller.size()){
                    smaller.push(mid);
                    bigger.push(input);
                    mid = bigger.top();
                    bigger.pop();
                }
                else
                    bigger.push(input);
            }
            else{
                if(bigger.size() < smaller.size()){
                    smaller.push(input);
                    bigger.push(mid);
                    mid = smaller.top();
                    smaller.pop();
                }
                else if(bigger.size() > smaller.size())
                    smaller.push(input);
                else{
                    smaller.push(input);
                    bigger.push(mid);
                    mid = smaller.top();
                    smaller.pop();
                }
            }
        }
        printf("%d\n", mid);
        
    }
}
