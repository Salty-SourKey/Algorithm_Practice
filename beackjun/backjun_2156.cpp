#include <iostream>
#include <algorithm>
using namespace std;
int dt[10001];
int dp[10001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> dt[i];
    dp[1] = dt[1];
    dp[2] = dp[1] + dt[2];
    for(int i = 3; i <= N; ++i) dp[i] = max(max(dt[i]+dt[i-1]+dp[i-3],dt[i]+dp[i-2]), dp[i-1]);
    cout << dp[N];
    return 0;
}