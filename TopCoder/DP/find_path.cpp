#include <iostream>
using namespace std;

int dp[5][6];

int main(){
    for(int i = 0; i < 5; ++i){
        for(int j = 0; j < 6; ++j){
            if(i == 0 || j == 0) dp[i][j] = 1;
            else if((i == 3 && j == 1) || (i == 1 && j == 2) || (i == 2 && j == 4)) continue;
            else dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    cout << dp[4][5];
    return 0;
}