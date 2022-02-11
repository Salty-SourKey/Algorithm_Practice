#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long dp[101];
class CorporationSalary{
public:
    long long totalalary(vector<string> relations){
        long long ans = 0;
        for(int i = 0; i < relations.size(); ++i) ans+=calc(relations, i);
        return ans;
    }
    long long calc(vector<string> relations, int n){
        if(dp[n] != 0) return dp[n];
        if(relations[n].find('Y') == string::npos) return dp[n] = 1;
        for(int i = 0; i < relations.size(); ++i){
            if(relations[n][i] == 'Y') dp[n] += calc(relations, i);  
        }
        return dp[n];
    }
};
int main(){
    vector<string> rel;
    rel.push_back("NNNNNN");
    rel.push_back("YNYNNY");
    rel.push_back("YNNNNY");
    rel.push_back("NNNNNN");
    rel.push_back("YNYNNN");
    rel.push_back("YNNYNN");
    CorporationSalary c;
    cout << c.totalalary(rel);
    return 0;
}