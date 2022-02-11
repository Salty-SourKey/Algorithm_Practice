#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, temp;
    cin >> N;
    vector<int> dp;
    for(int i = 1; i<=N; ++i){
        cin >> temp;
        if(dp.empty() == true || dp.back() < temp) dp.push_back(temp);
        else{
            auto iter = lower_bound(dp.begin(), dp.end(), temp);
            *iter = temp; 
        }
    }
    cout << int(dp.size());
    return 0;
}
