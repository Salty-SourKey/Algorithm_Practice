#include <stdio.h>
int dp[1000001][2];
long long int rectangle(int x){
    dp[0][0] = 1;
    dp[1][0] = 2;
    dp[2][0] = 7;
    for(int i = 3; i <= x; i++){                   //다이나믹 프로그래밍은 Bottom to Top 기법 사용할때가 많음!!
        dp[i][1] = (dp[i-1][1] + 2*dp[i-3][0])%1000000007;
        dp[i][0] = (2*dp[i-1][0]+3*dp[i-2][0]+dp[i][1])%1000000007;
    }
        
    return dp[x][0];
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%lld", rectangle(n));
    return 0;
}