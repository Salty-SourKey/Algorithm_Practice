#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string num;
int main(){
    string temp = "", max = "";
    cin >> num;
    int arr[num.size()];
    int sum=0;
    for(int i = 0; i < num.size(); i++){            //string을 int배열로 옮김, 옮기면서 모든 자리의 합 계산
        temp = num[i];
        arr[i] = stoi(temp);
        sum+=arr[i];
    }
    sort(arr,arr+num.size(), greater<int>());       //int배열을 오름차순으로 정렬
    if(sum % 3 == 0 && arr[num.size()-1] == 0){     //30으로 나누어 떨어지려면 3,10을 약수로 가져야하기 때문에 모든 자리의 합이 3으로 나누어 떨어지고 끝자리가 0이여야 함
        for(int i = 0; i < num.size(); i++) max += to_string(arr[i]);  //이미 오름차순 정렬이기 때문에 조건만 만족하면 가장 큰 수다
        cout << max;
    }
    else
        cout << -1;
    return 0;
    
}