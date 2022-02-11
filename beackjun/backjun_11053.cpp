#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];
int dp[1001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, maximum = 0;
    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> arr[i];
    for(int i = 1; i <= N; ++i){
        dp[i] = 1;
        for(int j = 1; j < i; ++j) if(arr[i] > arr[j] ) dp[i] = max(dp[i], dp[j]+1);
        if(maximum < dp[i]) maximum = dp[i];
    }
    cout << maximum;
    return 0;
}