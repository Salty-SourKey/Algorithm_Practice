#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];

int main(){
    int N;
    for(int i = 1; i <= 10; i++){
        int ans = 0;
        int left; 
        int right;

        cin >> N;
        for(int j = 0; j < N; j++)
            cin >> arr[j];
        for(int j = 2; j < N - 2; j++){
            left = max(arr[j-2], arr[j-1]);
            right = max(arr[j+1], arr[j+2]);
            if(arr[j] - (max(left, right)) > 0)
                ans += arr[j] - (max(left, right));
        }

        cout << "#" << i << " " << ans << endl;
    }
    return 0;
}