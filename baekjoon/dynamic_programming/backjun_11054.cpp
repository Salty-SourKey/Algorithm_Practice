#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[1001];
int dp_a[1001];
int dp_b[1001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, result = 0;
    cin >> N;
    for(int i = 1; i <= N; ++i) cin >> arr[i];
    for(int i = 1; i <= N; ++i){
        dp_a[i] = 1;
        for(int j = 1; j <= i; ++j)
            if(arr[j] < arr[i]) dp_a[i] = max(dp_a[j]+1, dp_a[i]);
    }
    //이미 구한 값에 다시 불러와야지 구하지도 않은 값 불러내면 안됨
    //for(int i = 1; i <= N; ++i){...}
    for(int i = N; i>=1; --i){
        dp_b[i] = 1;
        for(int j = N; j >= i; --j)
            if(arr[j] < arr[i]) dp_b[i] = max(dp_b[j]+1, dp_b[i]);
    }
    for(int i = 1; i <= N; ++i) result = max(result, dp_a[i]+dp_b[i]);
    cout << result-1;
    return 0;
}