#include<iostream>
#include<vector>
#include<map>
using namespace std;



class InfiniteSequence2{
public:
    long long calc(long n, int p, int q, int x, int y){
        const int MAX = 1000000;

        if(n <= 0) return 1;
        if( n < MAX && dp.find(n) != dp.end()) return dp[n];
        return dp[n] = calc(long(n/p) - x, p, q, x, y) + calc(long(n/q) - y, p, q, x, y); 
    }
    map<long long, long long> dp;
};

int main(){
    long n = 10000000000000;
    int p = 2;
    int q = 2;
    int x = 0;
    int y = 123456;
    InfiniteSequence2 i;
    cout << i.calc(n, p, q, x, y);
    return 0;
}