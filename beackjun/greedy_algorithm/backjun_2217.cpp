#include <iostream>
#include <algorithm>
using namespace std;
int arr[100000];
int main(){
    int n, max=0;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr,arr+n);  //로프의 견딜 수 있는 무게 입력을 정렬
    for(int i = 0; i < n; i++) 
        if(max<arr[i]*(n-i)) max = arr[i]*(n-i);  //모든 로프를 사용할 필요는 없기 때문에 가장 작은 값부터 최대값 구하고 작은 값 빼고 최대값 구해보고를 반복
    cout << max;
    return 0;
}