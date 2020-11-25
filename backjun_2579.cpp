#include <iostream>
#include <algorithm>
using namespace std;
int dp[301];
int dt[301];
int stair(int x){
    if(x == 0) return 0;
    if(x == 1) return dt[1];
    if(x == 2) return dt[1] + dt[2];
    if(dp[x] != 0 ) return dp[x];
    return dp[x] = max(stair(x-2), stair(x-3)+dt[x-1]) + dt[x];
}


int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int N;
    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> dt[i];
    cout << stair(N);
    return 0;

}