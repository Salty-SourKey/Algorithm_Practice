#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> w;
vector<int> temp;
int main(){
    int weight, n, k, i = 1;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> weight;
        w.push_back(weight);
    }
    sort(w.begin(), w.end());
    while(1){
        temp = w;
        if(i == 1) if(w.find(1) != w.end()) continue;
        else{
            for(int k = 0; k < i/2; k++){
                if(w.find(k+1) != w.end() && w.find(i-k-1) != w.end()){
                    temp(w.find(k+1)) = 0;
                    temp(w.find(i-k-1)) = 0;
                }
            }
        }
    }
    ios::sync_with_stdio(false);
    return 0;
}