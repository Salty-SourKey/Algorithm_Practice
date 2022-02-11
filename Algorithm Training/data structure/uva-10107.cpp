#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> arr;
    int input, num = 0;

    while(cin >> input){
        arr.push_back(input);
        num++;
        sort(arr.begin(),arr.end());

        if(num%2 == 0)
            cout << (arr[num/2]+arr[num/2-1])/2 << endl;
        else
            cout << arr[num/2] << endl;

    }
    return 0;
}