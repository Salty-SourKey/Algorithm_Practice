#include <iostream>


using namespace std;

int arr[10001];

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int N, score, ans = 0;
        arr[0] = 1;
        cin >> N;
        for(int j = 0; j < N; j++){
            cin >> score;
            for(int k = 10000; k >= 0; k--)
                if(arr[k]) arr[k+score]++;
        }
        for(int j = 0; j <= 10000; j++){
            if(arr[j]){
                ans++;
                arr[j] = 0;
            }
        }
        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}