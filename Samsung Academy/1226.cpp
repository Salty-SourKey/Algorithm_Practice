//간단한 BFS 문제

#include <iostream>
#include <queue>
#include <memory.h>
#define N 16
using namespace std;

int arr[17][17];
int vis[17][17];

int x_pos[4] = {0,0,1,-1};
int y_pos[4] = {1,-1,0,0};

void bfs(){
    queue<pair<int,int>> maze;
    maze.push({1,1});
    vis[1][1] = 1;
    while(!maze.empty()){
        int x = maze.front().first;
        int y = maze.front().second;

        maze.pop();

        for(int i = 0; i < 4; i++){
            int nx = x + x_pos[i];
            int ny = y + y_pos[i];
            if(nx >= 0 && nx < N && ny >= 0 && ny < N && !vis[nx][ny]){
                if(arr[nx][ny] == 0 || arr[nx][ny] == 3){
                    vis[nx][ny] = 1;
                    if(arr[nx][ny] == 3) return;
                    maze.push({nx,ny});
                }
            }
            
        }
    }
}


int main(){
    int T;
    char input;
    for(int t = 1; t <= 10; t++){
        int target_x, target_y;
        cin >> T;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                cin >> input;
                if(input == '3'){
                    target_x = i;
                    target_y = j;
                }
                arr[i][j] = input - 48;
            }
        }
        memset(vis, 0, sizeof(vis));
        bfs();
        cout << "#" << T << " " << vis[target_x][target_y] << endl;
    }
}