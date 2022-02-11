#include <stdio.h>
#include <algorithm>
using namespace std;
int cost[1001][3];
int dp[1001][3];
int result;
int RGB(int x, int y){
    if(x == 1 && y == 0) return cost[1][0]; 
    if(x == 1 && y == 1) return cost[1][1];
    if(x == 1 && y == 2) return cost[1][2];
    if(dp[x][y] != 0) return dp[x][y];
    if(y == 0) return dp[x][y] = min(RGB(x-1,1), RGB(x-1,2)) + cost[x][0];
    if(y == 1) return dp[x][y] = min(RGB(x-1,0), RGB(x-1,2)) + cost[x][1];
    return dp[x][y] = min(RGB(x-1,0), RGB(x-1,1)) + cost[x][2];
}

int main(){
    int N, minimum;
    scanf("%d", &N);
    for(int i = 1; i <=N; ++i)
        for(int j = 0; j < 3; ++j)
            scanf("%d", cost[i]+j);
    minimum = min(min(RGB(N,0), RGB(N,1)), RGB(N,2));
    printf("%d", minimum);
    return 0;
}