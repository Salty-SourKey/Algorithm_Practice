//간단한 시뮬레이션

#include <iostream>

using namespace std;

int x[4] = {1,0,-1,0};
int y[4] = {0,1,0,-1};


int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int N, pos_x, pos_y, dir;
        int greed[11][11];
        for(int i = 0; i < 11; i++)
            for(int j = 0; j < 11; j++)
                greed[i][j] = 0;

        cin >> N;
        pos_x = 0;
        pos_y = 0;
        dir = 0;
        for(int i = 1; i <= N*N; i++){
            greed[pos_y][pos_x] = i;
            if(pos_x+x[dir] < 0 || pos_x+x[dir] >= N || pos_y+y[dir] < 0 || pos_y+y[dir] >= N || greed[pos_y+y[dir]][pos_x+x[dir]] != 0)
                dir = (dir + 1) % 4;
            
            pos_x += x[dir];
            pos_y += y[dir];
        }
        cout << "#" << t << endl;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(j) cout << " ";
                cout << greed[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}