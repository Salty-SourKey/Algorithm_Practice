#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    long long int i,M,N,sum=0,anger=0,temp;
    cin >> M >> N;
    long long int arr[N], count[N]={0,};
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        sum+=arr[i];
    }
    sort(&arr[0],&arr[N-1]);
    temp = 0;
    i = sum - M;
    while(i>0){
        for(int k = 0+temp; k < N; k++){
            if(arr[k]>0 && i>0){
                arr[k]--;
                i--;
                count[k]++;
            }
            if(arr[k] == 0 && i>0) temp++;
        }
    }
    for(int i = 0; i < N; i++) anger += count[i]*count[i];
    cout << anger;
    return 0;
}