#include <iostream>
using namespace std;

double prob[4];
int vx[] = {1,-1,0,0};
int vy[] = {0,0,1,-1};
bool check[100][100];
class CrazyBot{
public:
    double dfs(int x, int y, int n){
        if(check[x][y]) return 0;
        if(n == 0) return 1;
        check[x][y] = true;
        double ret = 0;
        for(int i = 0; i < 4; ++i){
            ret += dfs(x+vx[i],y+vy[i],n-1)*prob[i];
        }
        check[x][y] = false;
        return ret;

    }
    double getProbablility(int n, int east, int west, int south, int north){
        prob[0] = east / 100.0;
        prob[1] = west / 100.0;
        prob[2] = south / 100.0;
        prob[3] = north / 100.0;
        return dfs(20,20,n);    
    }
};  

int main(){
    int n, east, west, south, north;
    cin >> n >> east >> west >> south >> north;
    CrazyBot bot;
    cout << bot.getProbablility(n,east,west,south,north);
    return 0;
}
