#include <iostream>
#include <algorithm>
using namespace std;
int dp[100001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, temp, result = -1000000;
    cin >> N;
    for(int i = 1; i <= N; ++i){
        cin >> temp;
        dp[i] = max(temp+dp[i-1], temp);
        result = max(result, dp[i]); 
    }
    cout << result;
    return 0;
}