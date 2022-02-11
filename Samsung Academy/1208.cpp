#include <iostream>
#include <algorithm>

using namespace std;
int arr[101];
int main(){
    int T = 1;
    while(T <= 10){
        int dump;
        cin >> dump;
        for(int i = 0; i < 100; i++)
            cin >> arr[i];
        sort(arr, arr+100);
        for(int i = 0; i < dump; i++){
            if(arr[99] - arr[0] <= 1) break;
            arr[0]++;
            arr[99]--;
            sort(arr, arr+100);
        }

        cout << "#" << T << " " << arr[99] - arr[0] << endl;
        T++;
    }
    return 0;
}