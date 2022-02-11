//Greedy + Map


#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
int arr[1000001];

int main(){
    int T, caseNum = 1;
    cin >> T;
    while(T--){
        int N, n;
        long long ans = 0;
        cin >> N;
        map<int, int> highest;
        for(int i = 1; i <= N; i++){
            cin >> n;
            arr[i] = n;
            highest[n] = i;
        }

        for(int i = 1; i <= N; i++){
            for(map<int,int>::iterator iter = highest.end(); iter != highest.find(arr[i]); iter--){
                if(iter->second > i && iter->first -arr[i] > 0){
                    ans += iter->first - arr[i];
                    break;
                }
            }
        }
        highest.clear();
        cout << "#" << caseNum++ << " " << ans << endl;
    }
    return 0;
}