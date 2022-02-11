#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class InterestingParty
{
    public:
        int bestInvitation(vector<string> first, vector<string> second){
            map <string,int> dic;
            for(int i = 0; i < first.size(); ++i){
                dic[first[i]] = 0;
                dic[second[i]] = 0;
            }
            for(int i = 0; i < first.size(); ++i){
                dic[first[i]]++;
                dic[second[i]]++;
            }
            int ans = 0;
            for(auto i = dic.begin(); i != dic.end(); ++i){
                ans = max(i->second, ans);
            }
            return ans;
        }
};

int main(){
    string a;
    vector <string> f;
    vector <string> s;
    for(int i = 0; i < 4; ++i){
        cin >> a;
        f.push_back(a);
    }
    for(int i = 0; i < 4; ++i){
        cin >> a;
        s.push_back(a);
    }
    InterestingParty party;
    cout << party.bestInvitation(f,s);
    return 0;
}