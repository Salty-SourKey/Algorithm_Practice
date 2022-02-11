#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[41];
class BadNeighbors{
public:
    int maxDonations(vector<int> donations){
        int N = donations.size();
        int ans = 0; 
        for(int i = 0; i < N-1; ++i){
            dp[i] = donations[i];
            if(i>0) dp[i] = max(dp[i],dp[i-1]);
            if(i>1) dp[i] = max(dp[i],dp[i-2]+donations[i]);
            ans = max(dp[i],ans);
        }
        for(int i = 1; i < N; ++i){
            dp[i] = donations[i];
            if(i>1) dp[i] = max(dp[i],dp[i-1]);
            if(i>2) dp[i] = max(dp[i],dp[i-2]+donations[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main(){
    vector<int> v{1,2,3,4,5,1,2,3,4,5};
    //
    BadNeighbors b;
    cout << b.maxDonations(v);
    return 0;
}