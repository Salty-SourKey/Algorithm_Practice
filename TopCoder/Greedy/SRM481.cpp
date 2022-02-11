#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

struct comp{
    template<typename T>
    bool operator()(const T& l, const T& r) const{
        if(l.second != r.second){
            return l.second < r.second;
        }
        return l.first < r.first;
    }
};

class BatchSystem{
public:
    vector<int> schedule(vector<int> duration, vector<string> user){
        map<string, long long> dic;
        int N = duration.size();
        int temp = 0;
        vector<int> ans(N, -1);
        for(int i = 0; i < N; ++i) dic[user[i]] += duration[i];
        set<pair<string, long long>, comp> sorted_set(dic.begin(), dic.end());
        for(auto iter = sorted_set.begin(); iter != sorted_set.end(); ++iter){
            for(int i = 0; i < N; ++i){
                if(iter->first == user[i] && ans[i] == -1) ans[i] = temp++;
            }
        }
        return ans;     
    }
};

int main(){
    vector<int> duration{100, 200, 50};
    vector<string> user{"H", "h", "Y"};
    BatchSystem b;
    vector<int> temp(duration.size());
    temp = b.schedule(duration, user);
    for(int i = 0; i < temp.size(); ++i)
        cout << temp[i] << " ";
    return 0;
}