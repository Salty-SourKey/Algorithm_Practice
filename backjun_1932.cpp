#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[501][501];
int val[501][501];
int triangle(int x, int y){
    if(x == 1 && y == 1) return dp[1][1];
    if(dp[x][y] != 0) return dp[x][y];
    if(y == 1) dp[x][y] = triangle(x-1, 1) + val[x][y];
    else if(y == x) dp[x][y] = triangle(x-1, x-1) + val[x][y];
    else dp[x][y] = max(triangle(x-1, y-1), triangle(x-1, y)) + val[x][y];
    return dp[x][y];
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);

    int n, t, maximum = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= i; ++j) cin >> val[i][j];   
    dp[1][1] = val[1][1];
    for(int i = 1; i <= n; ++i) maximum = max(maximum, triangle(n, i));
    cout << maximum;
    return 0;
}