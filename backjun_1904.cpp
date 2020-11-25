#include <stdio.h>
int array[1000001];

int dp(int x){
    if(x == 1) return 1;
    if(x == 2) return 2;
    if(array[x] > 0 ) return array[x];
    return array[x] = (dp(x-1) + dp(x-2))%15746;
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%d", dp(n));
    return 0;
}