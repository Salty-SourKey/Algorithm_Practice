#include <iostream>
using namespace std;
int main()
{
    int i, n, point=0, bonus_point=0;
    cin >> n;
    char arr[n];
    for(i = 0; i<n; i++) cin>>arr[i];
    for(i = 0; i<n; ++i){
        if(arr[i]=='O') point+=i+1+bonus_point++;
        else bonus_point = 0;
    }
    cout << point;
    return 0;
}