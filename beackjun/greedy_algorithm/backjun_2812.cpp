#include <iostream>
#include <vector>
using namespace std;
vector<char> res;
int n,k;
string s;
int main()
{
    cin >> n >> k >> s;
    for(int i = 0; i < s.size(); i++){
        while( k != 0 && !res.empty() && res.back() <s[i]){
            res.pop_back();
            k--;
        }
        res.push_back(s[i]);
    }
    for(int i = 0; i < res.size()-k; i++) cout << res[i];
    return 0;
}