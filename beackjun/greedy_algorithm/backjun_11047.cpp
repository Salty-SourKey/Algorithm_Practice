#include <iostream>
using namespace std;
int main(){
    int n,k,min=0; // n은 준규가 가지고 있는 동전 개수, k는 만들어야 하는 총 금액
    cin >> n >> k;
    int coin[n]; // 가지고 있는 동전 종류의 배열
    int temp = k;
    for(int i = 0; i < n; i++) cin >> coin[i];
    for(int i = 1; i <= n; i++){
        min += temp / coin[n-i];    //총액과 가장 큰 금액으로 나눈 몫을 최솟값에 더하고
        temp %= coin[n-i];          //총액을 나눈 나머지로 값 변경, 다음으로 큰 금액으로 반복
    }
    cout << min;
    return 0;
}