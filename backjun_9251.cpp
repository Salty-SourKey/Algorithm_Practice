#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int dp[1001][1001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string st_1, st_2;
    cin >> st_1 >> st_2;
    st_1 = "0" + st_1;
    st_2 = "0" + st_2;
    int len1 = st_1.length();
    int len2 = st_2.length();
    for(int i = 0; i < len1; i++){
        for(int j = 0; j < len2; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
                continue;
            }
            else{
                if(st_1[i] == st_2[j]) dp[i][j] = dp[i-1][j-1] + 1;
                else{
                    if(dp[i-1][j] > dp[i][j-1]) dp[i][j] = dp[i-1][j];
                    else dp[i][j] = dp[i][j-1]; 
                }
            }
        }
    }
    cout << dp[len1-1][len2-1];
    return 0;
}
