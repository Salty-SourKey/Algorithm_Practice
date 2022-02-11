#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class CutSticks{
public:
    double maxKth(vector<int> sticks, int C, int k){
        double a = 0;
        double b = 1e9;
        long long sum, cut = 0;
        double mid;
        for(int j = 0; j < 1000; ++j){
            sum = 0;
            cut = 0;
            mid = (a + b) / 2.0;
            for(int i = 0; i < sticks.size(); ++i){
                if((long(sticks[i] / mid)) > 0){
                    sum += long(sticks[i] / mid);
                    cut += long(sticks[i] / mid) - 1;
                }
            }
            if(cut > C) sum-=cut-C;
            /** sum -= max(0, cut-C) **/

            if( k <= sum ) a = mid;
            else b = mid;
        }
        return mid;
    }
};

int main(){
    vector<int> sticks{76, 594, 17, 6984, 26, 57, 9, 876, 5816, 73, 969, 527, 49};
    int C = 789;
    int k = 459;
    CutSticks c;
    cout << c.maxKth(sticks, C, k);
    return 0;

}