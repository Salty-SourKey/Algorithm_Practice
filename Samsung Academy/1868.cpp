//시뮬레이션 + BFS

#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

char arr[301][301];
int bomb[301][301];
int vis[301][301];
int x[8] = {0,0,1,-1, 1, -1, 1, -1};
int y[8] = {1,-1,0,0, 1, 1, -1, -1};

void bfs(int _x, int _y, int N){
    queue<pair<int,int>> grid;
    grid.push({_x,_y});
    vis[_x][_y] = true;
    while(!grid.empty()){
        int x_ = grid.front().first;
        int y_ = grid.front().second;
        
        grid.pop();

        for(int i = 0; i < 8; i++){
            int nx = x_ + x[i];
            int ny = y_ + y[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < N && !vis[nx][ny]){
                vis[nx][ny] = true;
                if(bomb[nx][ny] == 0)
                    grid.push({nx,ny});
            }
        }
    }
}

int main(){
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++){
        int N;
        int ans = 0;
        cin >> N;
        memset(bomb, 0, sizeof(bomb));
        memset(vis, false, sizeof(vis));

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> arr[i][j];
                if(arr[i][j] == '*') bomb[i][j] = -1;
            }
        }
    

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(bomb[i][j] != -1){
                    for(int dir = 0; dir < 8; dir++){
                        int nx = i + x[dir];
                        int ny = j + y[dir];
                        if(nx >= 0 && nx < N && ny >= 0 && ny < N && arr[nx][ny] == '*')
                            bomb[i][j]++;
                    }
                }
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(!vis[i][j] && bomb[i][j] == 0){
                    bfs(i,j, N);
                    ans++;
                }
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(!vis[i][j] && bomb[i][j] != -1)
                    ans++;
            }
        }
        cout << "#" << t << " " << ans << endl;
    }
    return 0;
}