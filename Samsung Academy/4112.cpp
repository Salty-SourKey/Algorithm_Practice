#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
vector<vector<int>> pyramid;

void set_pyramid(){
    int num = 1, lv = 0;
    while(num <= 10000){
        pyramid.push_back(vector<int>{});
        for(int i = 0; i < lv+1; i++)
            pyramid[lv].push_back(num++);
        lv++;
    }
}
int main(){
    int T;
    set_pyramid();
    cin >> T;
    for(int t = 1; t <= T; t++){
        int a, b, a_idx, a_lv = -1, b_idx, b_lv = -1;
        int ans = 0;
        cin >> a >> b;
        for(int i = pyramid.size()-1; i >= 0; i--){
            if(a_lv == -1 && a >= pyramid[i][0]){
                a_lv = i;
                a_idx = a - pyramid[i][0];
            }
            if(b_lv == -1 && b >= pyramid[i][0]){
                b_lv = i;
                b_idx = b - pyramid[i][0];
            }
        }
        if(a_lv > b_lv){
            int temp_lv = a_lv;
            int temp_idx = a_idx;
            a_idx = b_idx;
            a_lv = b_lv;
            b_idx = temp_idx;
            b_lv = temp_lv;
        }

        if(b_idx <= a_idx)
            ans = (a_idx - b_idx) + (b_lv - a_lv);
        else{
            if((b_idx - a_idx) > (b_lv - a_lv))
                ans = (b_idx - a_idx);
            else{
                ans = (b_lv - a_lv);
            }
                
        }
        
        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}