#include <iostream>
using namespace std;
int dp[101][10];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    long long int result = 0;
    cin >> N;
    for(int i = 1; i <= 9; ++i) dp[1][i] = 1;
    for(int i = 2; i <= N; ++i){
        dp[i][0] = dp[i-1][1]%1000000000;
        dp[i][9] = dp[i-1][8]%1000000000;
        for(int k = 1; k <= 8; ++k) dp[i][k] = dp[i-1][k+1]%1000000000 + dp[i-1][k-1]%1000000000;
    }
    for(int i = 0; i < 10; ++i) result += dp[N][i];
    cout << result%1000000000;
    return 0;
}