#include <stdio.h>
int dp[1001];

int rectangle(int x){
    if(x == 1) return 1;
    if(x == 2) return 3;
    if(dp[x] != 0) return dp[x];
    return dp[x] = (rectangle(x-1) + 2*rectangle(x-2))%10007;
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", rectangle(n));
    return 0;
}