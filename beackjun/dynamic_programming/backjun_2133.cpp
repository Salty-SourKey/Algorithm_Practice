#include <stdio.h>

int dp[31];
int rectangle(int x){
    if(x % 2 != 0 ) return 0;
    if(x == 0) return 1;
    if(x == 2) return 3;
    if(dp[x] != 0) return dp[x];
    dp[x] = 3*rectangle(x-2);
    for(int i = 1; i < x/2; i++){
        dp[x] += 2*rectangle(x-(i*2+2));    }
    return dp[x];
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", rectangle(n));
    return 0;
}