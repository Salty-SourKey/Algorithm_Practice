#include <iostream>
#include <algorithm>
using namespace std;

int warr[5] = {3,4,1,2,3};
int varr[5] = {2,3,2,3,6};
int maxw = 10;
int dp[6][11];

int main(){
    for(int n = 1; n < 6; ++n){
        for(int w = 1; w < 11; ++w){
            if(w-warr[n-1]>=0) dp[n][w] = max(dp[n-1][w], dp[n-1][w-warr[n-1]] + varr[n-1]);
            else dp[n][w] = dp[n-1][w];
        }
    }
    cout << dp[5][10];
    return 0;
}