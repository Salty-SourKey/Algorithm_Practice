#include <iostream>
#include <vector>
using namespace std;

class CirclesCountry{
public:
    int leastBorders(vector<int> X, vector<int> Y, vector<int> R, int x1, int y1, int x2, int y2){
        int N = X.size();
        int ans = 0;
        for(int i = 0; i < N; ++i){
            if((x1-X[i])*(x1-X[i]) + (y1-Y[i])*(y1-Y[i]) < R[i]*R[i] && (x2-X[i])*(x2-X[i]) + (y2-Y[i])*(y2-Y[i]) < R[i]*R[i]) continue;
            if((x1-X[i])*(x1-X[i]) + (y1-Y[i])*(y1-Y[i]) < R[i]*R[i]) ans++;
            if((x2-X[i])*(x2-X[i]) + (y2-Y[i])*(y2-Y[i]) < R[i]*R[i]) ans++;
        }
        return ans;
    }
};

int main(){
    CirclesCountry c;
    vector<int> X{-107,-38,140,148,-198,172,-179,148,176,153,-56,-187};
    vector<int> Y{175,-115,23,-2,-49,-151,-52,42,0,68,109,-174};
    vector<int> R{135,42,70,39,89,39,43,150,10,120,16,8};
    int x1 = 102;
    int y1 = 16;
    int x2 = 19;
    int y2 = -108;
    cout << c.leastBorders(X,Y,R,x1,y1,x2,y2);
    return 0;
}