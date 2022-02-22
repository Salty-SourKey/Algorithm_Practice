#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n], order[n] = {0,};
    for(int i = n-1; i >= 0; i--) cin >> arr[i];
    for(int i = 0; i < n; i++){
        if(order[arr[i]] == 0) order[arr[i]] = n-i;
        else{
            for(int k = n-2; k >= arr[i]; k--) order[k+1] = order[k];
            order[arr[i]] = n-i;       
        }
    }
    for(int i = 0; i < n; i++) cout << order[i] << " ";
    return 0;
}