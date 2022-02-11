#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
class CantorDust{
public:
    int occurencesNumber(vector<string> pattern, int time){
        int N = pow(3,time);
        vector<int> CantorArray{1};
        vector<int>tempVec;
        vector<vector<int>> possible(N);
        int check;
        for(int i = 0; i < time; ++i){
            vector<int> zeros(pow(3,i));
            tempVec = CantorArray;
            CantorArray.insert(CantorArray.end(), zeros.begin(), zeros.end());
            CantorArray.insert(CantorArray.end(), tempVec.begin(), tempVec.end());
        }
        vector<int> hori(pattern[0].size(),0);
        vector<int> vert(pattern.size(),0);
        for(int i = 0; i < pattern.size(); ++i){
            for(int j = 0; j < pattern[0].size(); ++j){
                if((pattern[i])[j] == '.') check = 0;
                else check = 1;
                hori[j] = hori[j] || check;
                vert[vert.size()-i-1] = vert[vert.size()-i-1] || check;
            }
        }
        bool match;
        int h_ans = 0;
        int v_ans = 0;
        for(int i = 0; i <= N - hori.size(); ++i){
            match = 1;
            for(int j = 0; j < hori.size(); ++j){
                if(CantorArray[i+j] != hori[j]){
                    match = 0;
                    break;
                }
            }
            if(match) h_ans++;
            else continue;
        }
        for(int i = 0; i <= N - vert.size(); ++i){
            match = 1;
            for(int j = 0; j < vert.size(); ++j){
                if(CantorArray[i+j] != vert[j]){
                    match = 0;
                    break;
                }
            }
            if(match) v_ans++;
            else continue;
        }
        auto iter = find(hori.begin(),hori.end(), 1);

        if(iter != hori.end()) return v_ans * h_ans; 
        else return ((N - vert.size()+1) * h_ans) + ((N - hori.size() + 1) * v_ans) - h_ans * v_ans;
    } 
};
int main(){
    CantorDust c;
    vector<string> pattern{"X"};
    cout << c.occurencesNumber(pattern,9);
    return 0;
}