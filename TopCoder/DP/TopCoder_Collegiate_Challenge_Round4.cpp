#include <iostream>
#include <vector>
using namespace std;
long long dp[100][100][50];
int vx[16] = {0,1,1,1,0,-1,-1,-1,-1,1,2,2,1,-1,-2,-2};
int vy[16] = {1,1,0,-1,-1,-1,1,0,2,2,1,-1,-2,-2,-1,1};

class ChessMetric{
public:
    long long howMany(int size, vector<int> start, vector<int> end, int numMoves){
        dp[start[0]][start[1]][0] = 1;
        for(int i = 0; i < numMoves; ++i){
            for(int x = 0; x < size; ++x){
                for(int y = 0; y < size; ++y){
                    for(int k = 0; k < 16; ++k){
                        int x_next = x+vx[k];
                        int y_next = y+vy[k];
                        if((0 <= x_next && x_next < size) && (0 <= y_next && y_next < size)){
                            dp[x_next][y_next][i+1] += dp[x][y][i]; 
                        }
                    }
                }
            }
        }
        return dp[end[0]][end[1]][numMoves];
    }
};

int main(){
    int size = 100;
    vector<int> start{0,0};
    vector<int> end{0, 99};
    int numMoves = 50;
    ChessMetric cm;
    cout << cm.howMany(size, start, end, numMoves);
    return 0;
}