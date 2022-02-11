#include <iostream>
#include <algorithm>
using namespace std;

int dp[101][100001];
int dt[101][2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    for(int i = 1; i <= N; ++i) cin >> dt[i][0] >> dt[i][1];
    for(int i = 1; i <= N; ++i){
        for(int j = 0; j <= K; ++j){
            if(dt[i][0] <= j) dp[i][j] = max(dp[i-1][j], dp[i-1][j-dt[i][0]]+dt[i][1]);
            else dp[i][j] = dp[i-1][j]; 
        }
    }
    cout << dp[N][K];
    return 0;
}