#include <iostream>
using namespace std;
long long dp[51];
class HandShaking{
public:
    long countPerfect(int n){
        if(dp[n] != 0) return dp[n];
        if(n == 2 || n == 0) return dp[n] = 1;
        for(int i = 0; i < n; i=i+2){
            dp[n] += countPerfect(i) * countPerfect(n-i-2);
        }
        return dp[n];
    }
};

int main()
{
    HandShaking h;
    cout << h.countPerfect(10);
    return 0;
}