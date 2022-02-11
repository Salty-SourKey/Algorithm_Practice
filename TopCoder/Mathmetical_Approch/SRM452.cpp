#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> ans;
class HamiltonPath{
public:
    int countPaths(vector<string> roads){
        int count;
        int temp = 0;
        int check = -1;
        int howmanyCluster = 0;
        int N = roads.size();
        for(int i = 0; i < N; ++i) ans.push_back(i);
        for(int i = 0; i < N; ++i){
            count = 0;
            for(int j = 0; j < N; ++j){
                if(roads[i][j] == 'Y'){
                    count++;
                    if(count > 2) return 0;
                    ans[j] = roadUnion(i,j);
                }
            }
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < N; ++i){
            if(ans[i] != check){
                temp++;
                check = ans[i];
            }
            if(std::count(ans.begin(), ans.end(), i) > 1) howmanyCluster++;
        }
        return (2*howmanyCluster*factorial(temp)) % 1000000007;

    }
    int roadUnion(int i,int j){
        if(ans[i] == ans[j]) return ans[i];
        roadUnion(ans[i], i);
    }
    long long factorial(int n){
        if(n == 0) return 1;
        return n*factorial(n-1);
    }
};

int main(){
    vector<string> roads;
    roads.push_back("NYY");
    roads.push_back("YNY");
    roads.push_back("YYN");
    HamiltonPath h;
    cout << h.countPaths(roads);
    return 0;
}
