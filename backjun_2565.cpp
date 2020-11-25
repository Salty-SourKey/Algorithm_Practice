#include <iostream>
#include <algorithm>
using namespace std;
int arr[501];
int dp[501];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, temp, maximum = 0;
    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> temp >> arr[temp];
    for(int i = 1; i <= 501; ++i){
        if(arr[i] == 0) continue;
        dp[i] = 1;
        for(int j = 1; j < i; ++j){
            if(arr[j] == 0) continue;
            if(arr[j] < arr[i]) dp[i] = max(dp[i], dp[j]+1);
        }
        maximum = max(maximum, dp[i]);
    }
    cout << N - maximum;
    return 0;
}