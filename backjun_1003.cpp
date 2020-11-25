#include <stdio.h>
int dp[41][2];
int ans[1000];

void count(int x){
    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = 1;
    if(dp[x][0] != 0 && dp[x][1] != 0) return;
    for(int i = 2; i <= x; i++){
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];
    }
}
int main(){
    int T, temp;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) scanf("%d", ans+i);
    for(int i = 0; i < T; i++){
        count(ans[i]);
        printf("%d %d\n", dp[ans[i]][0], dp[ans[i]][1]);
    }
    return 0;
}