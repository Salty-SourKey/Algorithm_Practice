#include <stdio.h>
int n_array[100];
long long int dp[101];
long long int p(int x){
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    if(dp[x] != 0) return dp[x];
    return dp[x] = p(x-1) + p(x-5);
}

int main(){
    int T, N;
    scanf("%d", &T);
    for(int i = 0; i < T; ++i) scanf("%d", &n_array[i]);
    for(int i = 0; i < T; ++i) printf("%lld\n", p(n_array[i]));
    return 0;
}