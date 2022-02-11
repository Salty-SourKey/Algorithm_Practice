#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int N, course, ans, popular;
    map<vector<int>, int> dict;
    while(cin >> N, N){
        ans = 0;
        popular = 0;
        for(int i = 0; i < N; i++){
            vector<int> temp;
            for(int j = 0; j < 5; j++){
                cin >> course;
                temp.push_back(course); 
            }
            sort(temp.begin(), temp.end());
            if(dict.find(temp) != dict.end())
                dict[temp]++;
            else
                dict.insert({temp, 1});
        }
        for(map<vector<int>, int>::iterator iter = dict.begin(); iter != dict.end(); iter++){
            if(popular < iter->second){
                ans = iter->second;
                popular = iter->second;
            }
            else if(popular == iter->second)
                ans += iter->second;
        }
        cout << ans << endl;
        dict.clear();
    }
    return 0;
}