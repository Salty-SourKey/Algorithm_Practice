#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class NotTwo{
public:
    int maxStones(int width, int height){
        vector<int> max{1,1,0,0,1,1,0,0,1,1,0,0};
        int N = max.size();
        vector<int> maxStone;
        int ans, num_O, num_X = 0;
        for(int i = 0; i < (width / N); ++i) maxStone.insert(maxStone.end(), max.begin(), max.end());
        for(int i = 0; i < (width % N); ++i) maxStone.insert(maxStone.end(), max[i]);
        num_O = count(maxStone.begin(), maxStone.end(), 1);
        num_X = count(maxStone.begin(), maxStone.end(), 0);
        if(height % 4 == 3) return (num_O * 2 + num_X * 2) * (height / 4) + 2 * num_O + num_X;
        else return (num_O * 2 + num_X * 2) * (height / 4) + num_O * (height % 4);
        
    }
};
int main(){
    int w = 1000;
    int h = 1000;
    NotTwo n;
    cout << n.maxStones(w,h);
    return 0;
}